int __cdecl Scaleform::GFx::LoaderImpl::DetectFileFormat(Scaleform::File *pfile)
{
  Scaleform::File *v1; // esi
  int v3; // ebp
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  int v5; // edi
  const char *v6; // eax
  char *v7; // eax

  v1 = pfile;
  if ( !pfile )
    return 0;
  v3 = pfile->Tell(pfile);
  Read = v1->Read;
  v5 = 1;
  pfile = 0;
  if ( Read(v1, (unsigned __int8 *)&pfile, 4) > 0 )
  {
    switch ( (char)pfile )
    {
      case 52:
        v1->Seek(v1, 44, 0);
        if ( v1->Read(v1, (unsigned __int8 *)&pfile, 3) == 3
          && (_BYTE)pfile == 80
          && *(_WORD *)((char *)&pfile + 1) == 21078 )
        {
          v5 = 21;
        }
        break;
      case 67:
      case 70:
        if ( BYTE1(pfile) == 87 )
        {
          if ( BYTE2(pfile) == 83 )
            v5 = 2;
        }
        else if ( BYTE1(pfile) == 70 )
        {
          goto LABEL_9;
        }
        break;
      case 68:
        if ( *(_WORD *)((char *)&pfile + 1) == 21316 )
          v5 = 14;
        break;
      case 71:
        if ( BYTE1(pfile) == 73 )
        {
          if ( HIWORD(pfile) == 14406 )
            v5 = 12;
        }
        else if ( BYTE1(pfile) == 70 )
        {
LABEL_9:
          if ( BYTE2(pfile) == 88 )
            v5 = 3;
        }
        else if ( *(_WORD *)((char *)&pfile + 1) == 21592 && !HIBYTE(pfile) )
        {
          v5 = 24;
        }
        break;
      case -119:
        if ( *(_WORD *)((char *)&pfile + 1) == 20048 && HIBYTE(pfile) == 71 )
          v5 = 11;
        break;
      case -1:
        if ( BYTE1(pfile) == 0xD8 )
          v5 = 10;
        break;
      default:
        break;
    }
    v1->Seek(v1, v3, 0);
    if ( v5 == 1 )
    {
      v6 = v1->GetFilePath(v1);
      if ( v6 )
      {
        strrchr(v6, 0x2Eu);
        if ( v7 )
        {
          if ( !Scaleform::String::CompareNoCase(v7, ".tga") )
            return 13;
        }
      }
    }
  }
  return v5;
}
