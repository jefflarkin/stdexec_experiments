#include <cstdio>
#include <experimental/stdexec/execution.hpp>
#include <experimental/exec/static_thread_pool.hpp>

int main()
{
  exec::static_thread_pool ctx(1);
  auto sch = ctx.get_scheduler();

  auto begin = stdexec::schedule(sch);
  auto hello = stdexec::then(begin, []{
                printf("Hello, World!\n");
               });
  
  stdexec::sync_wait(hello);

  return 0;
}