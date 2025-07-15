void __thiscall Scaleform::GFx::AS3::VM::exec_getlex(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  Scaleform::GFx::AS3::Abc::Multiname *v4; // edi
  Scaleform::GFx::AS3::Abc::MultinameKind Kind; // eax
  Scaleform::GFx::ASString *InternedString; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pWeakProxy; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::VMFile *v11; // ebp
  const Scaleform::GFx::AS3::Multiname *v12; // eax
  Scaleform::GFx::AS3::Value *v13; // esi
  Scaleform::GFx::ASString *v14; // eax
  const Scaleform::GFx::AS3::VM::Error *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::StringDataPtr v18; // [esp-8h] [ebp-58h]
  const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *v19; // [esp-8h] [ebp-58h]
  Scaleform::StringDataPtr v20; // [esp-8h] [ebp-58h]
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // [esp-4h] [ebp-54h]
  Scaleform::GFx::AS3::Value value; // [esp+10h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Multiname arg1; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+38h] [ebp-18h] BYREF

  v4 = mn;
  Kind = mn->Kind;
  if ( (Kind & 3) == 1 || (Kind & 4) != 0 )
  {
    InternedString = Scaleform::GFx::AS3::VMFile::GetInternedString(
                       file,
                       (Scaleform::GFx::ASString *)&file,
                       (Scaleform::GFx::ASStringNode *)mn->NameIndex);
    Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&arg1, InternedString);
    v18.pStr = "compile time";
    v18.Size = 12;
    Scaleform::GFx::AS3::VM::Error::Error(
      (Scaleform::GFx::AS3::VM::Error *)&value,
      (Scaleform::GFx::AS3::VM_vtbl *)0x436,
      (Scaleform::GFx::ASStringNode *)this,
      (Scaleform::GFx::AS3::Value *)&arg1,
      v18);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v8,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pWeakProxy = (Scaleform::GFx::ASStringNode *)value.Bonus.pWeakProxy;
    --value.Bonus.pWeakProxy[1].pObject;
    if ( !pWeakProxy->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pWeakProxy);
    Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&arg1);
    v10 = (Scaleform::GFx::ASStringNode *)file;
    --file->pPrev;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  else
  {
    v11 = file;
    AppDomain = file->AppDomain;
    v19 = ss;
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::Multiname::Multiname(&arg1, file, mn);
    Scaleform::GFx::AS3::VM::FindProperty(this, &prop, v12, v19, AppDomain);
    Scaleform::GFx::AS3::Multiname::~Multiname(&arg1);
    if ( (prop.This.Flags & 0x1F) != 0
      && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
      && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
    {
      value.Flags = 0;
      value.Bonus.pWeakProxy = 0;
      if ( Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
             &prop,
             (Scaleform::GFx::AS3::CheckResult *)&file,
             this,
             &value,
             valGet)->Result )
      {
        v13 = ++this->OpStack.pCurrent;
        if ( v13 )
        {
          *v13 = value;
          value.Flags = 0;
        }
      }
      Scaleform::GFx::AS3::Value::~Value(&value);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    }
    else
    {
      v14 = Scaleform::GFx::AS3::VMFile::GetInternedString(
              v11,
              (Scaleform::GFx::ASString *)&file,
              (Scaleform::GFx::ASStringNode *)v4->NameIndex);
      Scaleform::GFx::AS3::Value::Value((Scaleform::GFx::AS3::Value *)&arg1, v14);
      v20.pStr = "any object on the scope stack";
      v20.Size = 29;
      Scaleform::GFx::AS3::VM::Error::Error(
        (Scaleform::GFx::AS3::VM::Error *)&value,
        (Scaleform::GFx::AS3::VM_vtbl *)0x42D,
        (Scaleform::GFx::ASStringNode *)this,
        (Scaleform::GFx::AS3::Value *)&arg1,
        v20);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v15,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      v16 = (Scaleform::GFx::ASStringNode *)value.Bonus.pWeakProxy;
      --value.Bonus.pWeakProxy[1].pObject;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&arg1);
      v17 = (Scaleform::GFx::ASStringNode *)file;
      --file->pPrev;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
    }
  }
}
