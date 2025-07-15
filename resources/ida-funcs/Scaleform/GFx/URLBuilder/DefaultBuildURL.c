void __cdecl Scaleform::GFx::URLBuilder::DefaultBuildURL(
        Scaleform::String *ppath,
        const Scaleform::GFx::URLBuilder::LocationInfo *loc)
{
  Scaleform::String *p_FileName; // ebp
  Scaleform::String *p_ParentPath; // esi
  int v4; // edi
  int v5; // eax

  p_FileName = &loc->FileName;
  if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((char *)((loc->FileName.HeapTypeBits & 0xFFFFFFFC) + 8)) )
  {
    Scaleform::String::operator=(ppath, p_FileName);
  }
  else
  {
    p_ParentPath = &loc->ParentPath;
    v4 = *(_DWORD *)(loc->ParentPath.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF;
    if ( v4 )
    {
      Scaleform::String::operator=(ppath, p_ParentPath);
      v5 = *(char *)((p_ParentPath->HeapTypeBits & 0xFFFFFFFC) + v4 + 7);
      if ( v5 != 92 && v5 != 47 )
        Scaleform::String::AppendString(ppath, "/", 0xFFFFFFFF);
      Scaleform::String::operator+=(ppath, p_FileName);
    }
    else
    {
      Scaleform::String::operator=(ppath, p_FileName);
    }
  }
}
