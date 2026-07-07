#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char *str;
  for(str = out;*fmt != '\0';fmt++){
    if(*fmt == '%'){
      ++fmt;
      switch(*fmt){
        case 's': char *s = va_arg(ap,char *);
        if(!s) s = "<NULL>";
        while(*s != '\0'){
          *str ++ = *s++; 
        }
        continue;
        case 'd': int n = va_arg(ap,int);
        if(n < 0){
          *str++ = '-';
          n = -1 * n;
        }
        int num = n;
        int len = 0;
        if(n == 0) len = 1;
        while(n){
          len++;
          n /= 10;
        }
        str = str + len -1;
        int tmp_len = len;
        while(tmp_len--){
          *str-- = (num % 10) + 48;
          num /= 10;
        }
        str = str + len + 1;
        continue;
        case '%': *str++ = '%';
        continue;
        default: return -1;
      }
    }
    else{
      *str++ = *fmt;
    }
  }
  *str = '\0';
  return str - out;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args,fmt);
  int i = vsprintf(out,fmt,args);
  va_end(args);
  return i;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
