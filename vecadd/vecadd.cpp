#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <experimental/stdexec/execution.hpp>
#include <experimental/exec/static_thread_pool.hpp>
#include <experimental/mdspan>

int main()
{
  int num_threads = 1;
  if (const char* env_num_threads = std::getenv("STDEXEC_NUM_THREADS") ) num_threads = atoi(env_num_threads);
  exec::static_thread_pool ctx(num_threads);
  auto sch = ctx.get_scheduler();
  const int N = 16;

  double *Ap = new double[N];
  double *Bp = new double[N];
  double *Cp = new double[N];

  auto A = std::experimental::mdspan(Ap,N);
  auto B = std::experimental::mdspan(Bp,N);
  auto C = std::experimental::mdspan(Cp,N);

  for (int i = 0; i < N; i++ )
  {
    A[i] = static_cast<double>(i);
    B[i] = static_cast<double>(N);
    C[i] = 0.0;
  }

  auto hello = stdexec::then([] { printf("Hello, World!\n"); })
             | stdexec::bulk(N, [=](int i){ C[i] = A[i] + B[i];})
             | stdexec::then([] { printf("Good Bye, Cruel World!\n");});
  
  stdexec::sync_wait(stdexec::schedule(sch) | hello);

  for (int i = 0; i < N; i++ )
  {
    assert(C[i] == static_cast<double>(i) + static_cast<double>(N));
  }
  printf("Output Correct.\n");
  delete Ap;
  delete Bp;
  delete Cp;
  return 0;
}
