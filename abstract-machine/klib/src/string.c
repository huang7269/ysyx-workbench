#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t count = 0;
  while(s[count++] != '\0'){
    ;
  }
  return count-1;
}

char *strcpy(char *dst, const char *src) {
  char *d = dst;
  
  while ((*d++ = *src++) != 0);

  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *address = dst;
  while(n && (*dst++ = *src++)){
    n--;
  }
  if(n){
    while(n--){
      *dst++ = '\0';
    }
  }
  return address;
}

char *strcat(char *dst, const char *src) {
  char *d = dst;

    while (*d++);
    --d;
    while ((*d++ = *src++) != 0);

    return dst;
}

int strcmp(const char *s1, const char *s2) {
  while (*s1 == *s2) {
    if (!*s1++) {
        return 0;
    }
    ++s2;
  }

  return (*s1 < *s2) ? -1 : 1;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while(n-- && *s1 != '\0' && *s1 == *s2){
    s1++;
    s2++;
  }
  int t = *s1 - *s2;
  return t;
}

void *memset(void *s, int c, size_t n) {
  char *tmp = (char *)s;

  for (size_t i = 0; i < n; i++) {
    tmp[i] = c;
  }

  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *p = dst;
  const char *s = src;
  if(s < p){
    for(int i = 0;i < n;i++){
      p[i] = s[i];
    }
  }
  else if(s > p){
    for(int i = n;n > 0;i--){
      p[i-1] = s[i-1];
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  char *p = out;
   const char *s = in;
   while(n--){
    *p++ = *s++;
   }
   return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  const char *p1 = s1;
  const char *p2 = s2;

  for (size_t i = 0; i < n; i++) {
    if (p1[i] < p2[i]) {
        return -1;
      } else if (p1[i] > p2[i]) {
        return 1;
      }
    }
  return 0;
}

#endif
