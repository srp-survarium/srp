Scaleform::GFx::MovieImpl *__thiscall Scaleform::GFx::AS2Support::CreateMovie(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::Resource *memContext)
{
  Scaleform::MemoryHeap *pLib; // esi
  Scaleform::GFx::MovieImpl *v4; // eax
  Scaleform::GFx::MovieImpl *v5; // eax
  Scaleform::GFx::MovieImpl *v6; // edi
  Scaleform::GFx::AS2::MovieRoot *v7; // eax
  Scaleform::RefCountVImpl *v8; // eax

  pLib = (Scaleform::MemoryHeap *)memContext->pLib;
  v4 = (Scaleform::GFx::MovieImpl *)pLib->Alloc(pLib, 16496u, 0);
  if ( v4 )
  {
    Scaleform::GFx::MovieImpl::MovieImpl(v4, (int)memContext, pLib);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = (Scaleform::GFx::AS2::MovieRoot *)pLib->Alloc(pLib, 808u, 0);
  if ( v7 )
    Scaleform::GFx::AS2::MovieRoot::MovieRoot(v7, memContext, v6, (Scaleform::GFx::Resource *)this);
  else
    v8 = 0;
  v6->Flags2 |= 1u;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return v6;
}
