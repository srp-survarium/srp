void __usercall Scaleform::GFx::Movie::Release(Scaleform::GFx::Movie *this@<ecx>, int a2@<edi>)
{
  Scaleform::GFx::Resource *v3; // eax
  Scaleform::RefCountVImpl *v4; // edi

  if ( InterlockedExchangeAdd(&this->RefCount, -1) == 1 )
  {
    v3 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::GFx::ASMovieRootBase *, int))this->pASMovieRoot.pObject->GetMemoryContext)(
                                       this->pASMovieRoot.pObject,
                                       a2);
    v4 = (Scaleform::RefCountVImpl *)v3;
    if ( v3 )
      Scaleform::RefCountImpl::AddRef(v3);
    ((void (__thiscall *)(Scaleform::GFx::Movie *, int))this->~Scaleform::GFx::Movie)(this, 1);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
  }
}
