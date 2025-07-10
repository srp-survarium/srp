void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::DisplayObject *pdispObj)
{
  Scaleform::GFx::ASMovieRootBase_vtbl *v3; // ecx
  Scaleform::GFx::AS3::VMAppDomain *ChangeMouseCursorType; // ecx

  this->__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable';
  this->pAS3CollectiblePtr.pObject = 0;
  this->pDispObj = pdispObj;
  this->pClassName = 0;
  pdispObj->pASRoot->CheckAvm(pdispObj->pASRoot);
  v3 = this->pDispObj->pASRoot[2].__vftable;
  if ( v3->SetExternalInterfaceRetVal && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    ChangeMouseCursorType = *(Scaleform::GFx::AS3::VMAppDomain **)(*(_DWORD *)(*((_DWORD *)v3->CreateString
                                                                               + (((unsigned int)v3->SetExternalInterfaceRetVal
                                                                                 - 1) >> 6))
                                                                             + 72
                                                                             * (((int)v3->SetExternalInterfaceRetVal - 1)
                                                                              & 0x3F)
                                                                             + 20)
                                                                 + 24);
  else
    ChangeMouseCursorType = (Scaleform::GFx::AS3::VMAppDomain *)v3[1].ChangeMouseCursorType;
  this->AppDomain = ChangeMouseCursorType;
  this->Flags = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(pdispObj, this);
  this->pAS3RawPtr = 0;
}
