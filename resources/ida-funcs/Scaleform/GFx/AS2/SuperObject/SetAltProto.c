void __thiscall Scaleform::GFx::AS2::SuperObject::SetAltProto(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Object *altProto)
{
  Scaleform::GFx::AS2::Object *pObject; // eax
  Scaleform::GFx::AS2::Object *v4; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::Object *v8; // ecx
  unsigned int v9; // eax

  if ( altProto != this->SuperProto.pObject )
  {
    pObject = this->SuperProto.pObject;
    if ( pObject )
      pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
    v4 = this->SavedProto.pObject;
    if ( v4 )
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
    }
    this->SavedProto.pObject = this->SuperProto.pObject;
    if ( altProto )
      altProto->RefCount = (altProto->RefCount + 1) & 0x8FFFFFFF;
    v6 = this->SuperProto.pObject;
    if ( v6 )
    {
      v7 = v6->RefCount;
      if ( (v7 & 0x3FFFFFF) != 0 )
      {
        v6->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
    this->SuperProto.pObject = altProto;
    if ( altProto )
      altProto->RefCount = (altProto->RefCount + 1) & 0x8FFFFFFF;
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
