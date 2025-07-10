void __thiscall Scaleform::GFx::AS2::TransformObject::~TransformObject(Scaleform::GFx::AS2::TransformObject *this)
{
  Scaleform::GFx::AS2::RectangleObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ColorTransformObject *v4; // ecx
  unsigned int v5; // eax
  Scaleform::GFx::AS2::MatrixObject *v6; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::CharacterHandle *v8; // esi

  pObject = this->PixelBounds.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  v4 = this->pColorTransform.pObject;
  if ( v4 )
  {
    v5 = v4->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v5) != 0 )
    {
      v4->RefCount = v5 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
  v6 = this->Matrix.pObject;
  if ( v6 )
  {
    v7 = v6->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v7) != 0 )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  v8 = this->TargetHandle.pObject;
  if ( v8 )
  {
    if ( --v8->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(v8);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  Scaleform::GFx::AS2::Object::~Object(this);
}
