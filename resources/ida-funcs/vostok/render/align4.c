unsigned int __usercall vostok::render::align4@<eax>(void *ptr@<eax>)
{
  return ((unsigned int)ptr + 3) & 0xFFFFFFFC;
}
