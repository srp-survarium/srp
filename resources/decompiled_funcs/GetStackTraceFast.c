void __cdecl GetStackTraceFast(void *hThread, unsigned __int64 (*ranOffsets)[2])
{
  int v2; // edx
  int v3; // ecx
  int capcount; // [esp+4h] [ebp-814h]
  void *stacktrace[513]; // [esp+8h] [ebp-810h] BYREF
  int index; // [esp+814h] [ebp-4h]

  if ( s_pfnCaptureStackBackTrace )
  {
    capcount = s_pfnCaptureStackBackTrace(3u, 0x200u, stacktrace, 0);
    for ( index = 0; index < capcount; ++index )
    {
      (*ranOffsets)[2 * index] = (int)stacktrace[index];
      (*ranOffsets)[2 * index + 1] = (int)stacktrace[index];
    }
    if ( (unsigned int)index <= 0x200 )
    {
      v2 = 2 * index;
      LODWORD((*ranOffsets)[v2]) = 0;
      HIDWORD((*ranOffsets)[v2]) = 0;
      v3 = 2 * index;
      LODWORD((*ranOffsets)[v3 + 1]) = 0;
      HIDWORD((*ranOffsets)[v3 + 1]) = 0;
    }
  }
}
