void __thiscall Scaleform::GFx::MovieImpl::GetRetValHolder(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v2; // edi
  Scaleform::GFx::ASStringManager *v3; // eax
  Scaleform::GFx::MovieImpl::ReturnValueHolder *v4; // eax

  if ( !this->pRetValHolder )
  {
    v2 = (Scaleform::GFx::MovieImpl::ReturnValueHolder *)this->pHeap->Alloc(this->pHeap, 28, 0);
    if ( v2 )
    {
      v3 = this->pASMovieRoot.pObject->GetStringManager(this->pASMovieRoot.pObject);
      Scaleform::GFx::MovieImpl::ReturnValueHolder::ReturnValueHolder(v2, v3);
      this->pRetValHolder = v4;
    }
    else
    {
      this->pRetValHolder = 0;
    }
  }
}
