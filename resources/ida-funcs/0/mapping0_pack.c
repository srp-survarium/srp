void __cdecl mapping0_pack(vorbis_info *vi, int *vm, oggpack_buffer *opb)
{
  unsigned int *v4; // edi
  int channels; // eax
  unsigned int v6; // ecx
  unsigned int i; // eax
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int j; // eax
  unsigned int *v11; // edi
  unsigned int *v12; // edi
  int v13; // [esp+18h] [ebp+Ch]
  int v14; // [esp+18h] [ebp+Ch]
  int v15; // [esp+18h] [ebp+Ch]

  if ( *vm <= 1 )
  {
    oggpack_write(opb, 0, 1u);
  }
  else
  {
    oggpack_write(opb, 1u, 1u);
    oggpack_write(opb, *vm - 1, 4u);
  }
  if ( vm[289] <= 0 )
  {
    oggpack_write(opb, 0, 1u);
  }
  else
  {
    oggpack_write(opb, 1u, 1u);
    oggpack_write(opb, vm[289] - 1, 8u);
    v13 = 0;
    if ( vm[289] > 0 )
    {
      v4 = (unsigned int *)(vm + 546);
      do
      {
        channels = vi->channels;
        v6 = 0;
        if ( channels )
        {
          for ( i = channels - 1; i; i >>= 1 )
            ++v6;
        }
        oggpack_write(opb, *(v4 - 256), v6);
        v8 = vi->channels;
        v9 = 0;
        if ( v8 )
        {
          for ( j = v8 - 1; j; j >>= 1 )
            ++v9;
        }
        oggpack_write(opb, *v4, v9);
        ++v13;
        ++v4;
      }
      while ( v13 < vm[289] );
    }
  }
  oggpack_write(opb, 0, 2u);
  if ( *vm > 1 )
  {
    v14 = 0;
    if ( vi->channels > 0 )
    {
      v11 = (unsigned int *)(vm + 1);
      do
      {
        oggpack_write(opb, *v11, 4u);
        ++v14;
        ++v11;
      }
      while ( v14 < vi->channels );
    }
  }
  v15 = 0;
  if ( *vm > 0 )
  {
    v12 = (unsigned int *)(vm + 273);
    do
    {
      oggpack_write(opb, 0, 8u);
      oggpack_write(opb, *(v12 - 16), 8u);
      oggpack_write(opb, *v12, 8u);
      ++v15;
      ++v12;
    }
    while ( v15 < *vm );
  }
}
