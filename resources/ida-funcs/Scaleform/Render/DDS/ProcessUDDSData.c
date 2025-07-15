char __usercall Scaleform::Render::DDS::ProcessUDDSData@<al>(
        unsigned int size@<eax>,
        Scaleform::Render::ImageFormat format@<edx>,
        const Scaleform::Render::DDS::DDSDescr *ddsFmt@<edi>,
        unsigned __int8 *buffer)
{
  unsigned __int8 *v4; // esi
  unsigned int v5; // ebp
  unsigned int v6; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // ebp
  unsigned int v10; // eax

  if ( format != Image_R8G8B8 )
  {
    if ( format == Image_R8G8B8A8 && size )
    {
      v8 = buffer + 1;
      v9 = ((size - 1) >> 2) + 1;
      do
      {
        v10 = *(v8 - 1) | ((*v8 | (*(unsigned __int16 *)(v8 + 1) << 8)) << 8);
        v8[1] = v10 >> ddsFmt->ShiftB;
        *v8 = v10 >> ddsFmt->ShiftG;
        *(v8 - 1) = v10 >> ddsFmt->ShiftR;
        if ( ddsFmt->HasAlpha )
          v8[2] = v10 >> ddsFmt->ShiftA;
        else
          v8[2] = -1;
        v8 += 4;
        --v9;
      }
      while ( v9 );
    }
    return 1;
  }
  if ( !size )
    return 1;
  v4 = buffer + 1;
  v5 = (size - 1) / 3 + 1;
  do
  {
    v6 = *(v4 - 1) | (*(unsigned __int16 *)v4 << 8);
    v4 += 3;
    *(v4 - 2) = v6 >> ddsFmt->ShiftB;
    *(v4 - 3) = v6 >> ddsFmt->ShiftG;
    --v5;
    *(v4 - 4) = v6 >> ddsFmt->ShiftR;
  }
  while ( v5 );
  return 1;
}
