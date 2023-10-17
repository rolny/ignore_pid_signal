#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
  // 建立一個子進程
  pid_t pid = fork();
  if (pid == 0) {
    // 在子進程中，忽略 SIGINT 和 SIGTSTP 信號
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    time_t now = time(NULL);
    char* time_str = ctime(&now);
    for (int i=0;i<10;i++) {
        printf("%s\n", time_str);
        sleep(1);
    }
    // ... 您的程式碼 ...

    return 0;
  }

  // 在父進程中，等待子進程結束
  waitpid(pid, NULL, 0);

  return 0;
}
