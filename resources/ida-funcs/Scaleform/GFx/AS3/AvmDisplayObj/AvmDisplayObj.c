void __thiscall Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
        Scaleform::GFx::AS3::AvmDisplayObj *this,
        Scaleform::GFx::DisplayObject *pdispObj)
{
  Scaleform::GFx::ASMovieRootBase_vtbl *v3; // ecx
  Scaleform::GFx::AS3::VMAppDomain *GenerateMouseEvents; // ecx

  this->__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::AvmDisplayObj::`vftable';
  this->pAS3CollectiblePtr.pObject = 0;
  this->pDispObj = pdispObj;
  this->pClassName = 0;
  pdispObj->pASRoot->CheckAvm(pdispObj->pASRoot);
  v3 = this->pDispObj->pASRoot[2].__vftable;
  if ( v3->Shutdown && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    GenerateMouseEvents = *(Scaleform::GFx::AS3::VMAppDomain **)(*(_DWORD *)(*((_DWORD *)v3->CreateObject
                                                                             + (((unsigned int)v3->Shutdown - 1) >> 6))
                                                                           + 96 * (((int)v3->Shutdown - 1) & 0x3F)
                                                                           + 20)
                                                               + 24);
  else
    GenerateMouseEvents = (Scaleform::GFx::AS3::VMAppDomain *)v3[1].GenerateMouseEvents;
  this->AppDomain = GenerateMouseEvents;
  this->Flags = 0;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(pdispObj, this);
  this->pAS3RawPtr = 0;
}
