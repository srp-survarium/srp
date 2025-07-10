void __thiscall Scaleform::GFx::TimelineDef::Frame::DestroyTags(Scaleform::GFx::TimelineDef::Frame *this)
{
  unsigned int v2; // edi

  v2 = 0;
  if ( this->TagCount )
  {
    do
    {
      ((void (__thiscall *)(Scaleform::GFx::ExecuteTag *, _DWORD))this->pTagPtrList[v2]->~Scaleform::GFx::ExecuteTag)(
        this->pTagPtrList[v2],
        0);
      ++v2;
    }
    while ( v2 < this->TagCount );
    this->pTagPtrList = 0;
    this->TagCount = 0;
  }
  else
  {
    this->pTagPtrList = 0;
    this->TagCount = 0;
  }
}
