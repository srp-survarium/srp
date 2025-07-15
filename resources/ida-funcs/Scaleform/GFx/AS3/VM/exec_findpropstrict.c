void __thiscall Scaleform::GFx::AS3::VM::exec_findpropstrict(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value *v6; // esi
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // [esp-4h] [ebp-50h]
  Scaleform::GFx::AS3::VM::Error v10; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+14h] [ebp-38h] BYREF
  Scaleform::GFx::AS3::ReadMn args; // [esp+2Ch] [ebp-20h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  if ( !this->HandleException )
  {
    AppDomain = file->AppDomain;
    memset(&prop, 0, 16);
    Scaleform::GFx::AS3::VM::FindProperty(this, &prop, &args.ArgMN, ss, AppDomain);
    Flags = prop.This.Flags;
    if ( (prop.This.Flags & 0x1F) != 0
      && (((int)prop.pSI & 1) == 0 || ((int)prop.pSI & 0xFFFFFFFE) != 0)
      && (((int)prop.pSI & 2) == 0 || ((int)prop.pSI & 0xFFFFFFFD) != 0) )
    {
      v6 = ++this->OpStack.pCurrent;
      if ( v6 )
      {
        v6->Flags = Flags;
        v6->Bonus.pWeakProxy = prop.This.Bonus.pWeakProxy;
        v6->value.VNumber = prop.This.value.VNumber;
        if ( (prop.This.Flags & 0x1F) > 9 )
        {
          if ( (prop.This.Flags & 0x200) != 0 )
            ++prop.This.Bonus.pWeakProxy->RefCount;
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(&prop.This);
        }
      }
    }
    else
    {
      Scaleform::GFx::AS3::VM::Error::Error(
        &v10,
        (Scaleform::GFx::AS3::VM_vtbl *)0x429,
        (Scaleform::GFx::ASStringNode *)this,
        &args.ArgMN.Name);
      Scaleform::GFx::AS3::VM::ThrowErrorInternal(
        this,
        v7,
        (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::ReferenceErrorTI);
      pNode = v10.Message.pNode;
      --v10.Message.pNode->RefCount;
      if ( !pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
