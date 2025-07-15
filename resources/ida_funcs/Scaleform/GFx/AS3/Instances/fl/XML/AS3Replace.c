void __thiscall Scaleform::GFx::AS3::Instances::fl::XML::AS3replace(
        Scaleform::GFx::AS3::Instances::fl::XML *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML> *result,
        const Scaleform::GFx::AS3::Value *propertyName,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // edi
  const Scaleform::GFx::AS3::Value *v6; // edi
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Class *Constructor; // eax
  Scaleform::GFx::AS3::Value xmlValue; // [esp+1Ch] [ebp-28h] BYREF
  Scaleform::GFx::AS3::Multiname prop_name; // [esp+2Ch] [ebp-18h] BYREF

  pVM = this->pTraits.pObject->pVM;
  Scaleform::GFx::AS3::Multiname::Multiname(&prop_name, pVM, propertyName);
  if ( pVM->HandleException )
    goto LABEL_13;
  v6 = value;
  if ( Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, value)->TraitsType == Traits_String )
  {
    pObject = this->pTraits.pObject;
    xmlValue.Flags = 0;
    xmlValue.Bonus.pWeakProxy = 0;
    Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
    Constructor->Construct(Constructor, &xmlValue, 1u, v6, 0);
    if ( this->pTraits.pObject->pVM->HandleException )
    {
      if ( (xmlValue.Flags & 0x1F) > 9 )
      {
        if ( (xmlValue.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&xmlValue);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&xmlValue);
      }
      goto LABEL_13;
    }
    if ( !this->AS3Replace(this, &propertyName, &prop_name, &xmlValue)->Result )
    {
      Scaleform::GFx::AS3::Value::~Value(&xmlValue);
      Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
      return;
    }
    Scaleform::GFx::AS3::Value::~Value(&xmlValue);
    goto LABEL_12;
  }
  if ( this->AS3Replace(this, &propertyName, &prop_name, v6)->Result )
LABEL_12:
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)result,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
LABEL_13:
  Scaleform::GFx::AS3::Multiname::~Multiname(&prop_name);
}
