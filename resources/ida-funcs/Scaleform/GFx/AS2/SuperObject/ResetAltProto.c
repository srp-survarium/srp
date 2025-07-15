void __thiscall Scaleform::GFx::AS2::SuperObject::ResetAltProto(Scaleform::GFx::AS2::SuperObject *this)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::Object *v3; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v5; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // ecx
  unsigned int v9; // eax

  if ( this->SavedProto.pObject )
  {
    pObject = this->SavedProto.pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
    v3 = this->SuperProto.pObject;
    if ( v3 )
    {
      RefCount = v3->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v3->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
      }
    }
    this->SuperProto.pObject = this->SavedProto.pObject;
    v5 = this->SavedProto.pObject;
    if ( v5 )
    {
      v6 = v5->RefCount;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    this->SavedProto.pObject = 0;
    v7 = this->SuperProto.pObject;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v8 = this->pProto.pObject;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
    this->pProto.pObject = this->SuperProto.pObject;
  }
}
