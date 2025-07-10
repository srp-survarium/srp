_BYTE *__cdecl __RTCastToVoid(void **inptr)
{
  if ( inptr )
    return FindCompleteObject(inptr);
  else
    return 0;
}
