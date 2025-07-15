Scaleform::Ptr<Scaleform::GFx::ASSupport> *__thiscall Scaleform::GFx::MovieDefImpl::GetASSupport(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::Ptr<Scaleform::GFx::ASSupport> *result)
{
  Scaleform::GFx::State *(__thiscall *GetStateAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // edx
  Scaleform::RefCountVImpl *v3; // eax
  Scaleform::GFx::Resource *v4; // esi
  Scaleform::Ptr<Scaleform::GFx::ASSupport> *v5; // eax

  GetStateAddRef = this->GetStateAddRef;
  if ( (char)((this->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes & 8 | 0x10) >> 3) > 2 )
    v3 = (Scaleform::RefCountVImpl *)((int (__stdcall *)(int))GetStateAddRef)(36);
  else
    v3 = (Scaleform::RefCountVImpl *)((int (__stdcall *)(int))GetStateAddRef)(35);
  v4 = (Scaleform::GFx::Resource *)v3;
  if ( v3 )
  {
    Scaleform::RefCountImpl::Release(v3);
    Scaleform::RefCountImpl::AddRef(v4);
    v5 = result;
    result->pObject = (Scaleform::GFx::ASSupport *)v4;
  }
  else
  {
    v5 = result;
    result->pObject = 0;
  }
  return v5;
}
