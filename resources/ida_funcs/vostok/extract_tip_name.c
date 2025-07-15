const char *__usercall vostok::extract_tip_name@<eax>(char *prev_text@<eax>)
{
  int v1; // eax

  strchr(prev_text, 0x20u);
  return (const char *)(v1 + 1);
}
