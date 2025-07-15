Scaleform::GFx::AS2::MovieClipObject *__thiscall Scaleform::GFx::AS2::AvmSprite::GetMovieClipObject(
        Scaleform::GFx::AS2::AvmSprite *this)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::MovieClipObject *v3; // edi
  Scaleform::GFx::AS2::GlobalContext *v4; // eax
  Scaleform::GFx::AS2::MovieClipObject *v5; // eax
  Scaleform::GFx::AS2::MovieClipObject *v6; // edi
  Scaleform::GFx::AS2::MovieClipObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::Sprite *pDispObj; // [esp-8h] [ebp-Ch]

  if ( this->ASMovieClipObj.pObject )
    return this->ASMovieClipObj.pObject;
  pHeap = this->pDispObj->pASRoot->pMovieImpl->pHeap;
  v3 = (Scaleform::GFx::AS2::MovieClipObject *)pHeap->Alloc(pHeap, 60u, 0);
  if ( v3 )
  {
    pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
    v4 = this->GetGC(this);
    Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(v3, v4, pDispObj);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  pObject = this->ASMovieClipObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ASMovieClipObj.pObject = v6;
  return v6;
}
