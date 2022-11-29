#include <cstdio>
#include <experimental/stdexec/execution.hpp>
#include <experimental/exec/static_thread_pool.hpp>

int main()
{
  exec::static_thread_pool ctx(1);
  auto sch = ctx.get_scheduler();

  auto hello = stdexec::then([] { printf("Hello, World!\n"); })
             | stdexec::then([] { printf("Good Bye, Cruel World!\n");});
  
  stdexec::sync_wait(stdexec::schedule(sch) | hello);

  return 0;
}