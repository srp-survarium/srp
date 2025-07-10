void __thiscall Scaleform::GFx::AS3::VM::exec_getlex(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  const Scaleform::GFx::AS3::Multiname *v8; // eax
  Scaleform::GFx::AS3::Value *v9; // esi
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // eax
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v12; // [esp-Ch] [ebp-40h]
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // [esp-8h] [ebp-3Ch]
  Scaleform::GFx::AS3::Value value; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+1Ch] [ebp-18h] BYREF

  Kind = mn->Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 )
  {
    Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eIllegalOpMultinameError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v6,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)value.Bonus.pWeakProxy;
    --value.Bonus.pWeakProxy[1].pObject;
    if ( !pWeakProxy->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
  }
  else
  {
    AppDomain = file->AppDomain;
    v12 = ss;
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::Multiname::Multiname((Scaleform::GFx::AS3::Multiname *)&value, file, mn);
    Scaleform::GFx::AS3::VM::FindProperty(this, &prop, v8, v12, AppDomain);
    Scaleform::GFx::AS3::Multiname::~Multiname((Scaleform::GFx::AS3::Multiname *)&value);
    if ( (prop.This.Flags & 0x1F) != 0
      && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
      && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
             &prop,
             (Scaleform::GFx::AS3::CheckResult *)&mn,
             this,
             &value,
             valGet)->Result )
      {
        v9 = ++this->OpStack.pCurrent;
        if ( v9 )
        {
          *v9 = value;
          value.Flags = 0;
        }
      }
      Scaleform::GFx::AS3::Value::~Value(&value);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error((Scaleform::GFx::AS3::VM::Error *)&value, eReadSealedError, this);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v10,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v11 = (Scaleform::GFx::ASStringNode *)value.Bonus.pWeakProxy;
      --value.Bonus.pWeakProxy[1].pObject;
      if ( !v11->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    }
  }
}
