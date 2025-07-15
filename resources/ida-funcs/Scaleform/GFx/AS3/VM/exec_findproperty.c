void __thiscall Scaleform::GFx::AS3::VM::exec_findproperty(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn,
        const Scaleform::ArrayDH<Scaleform::GFx::AS3::Value,2,Scaleform::ArrayDefaultPolicy> *ss,
        Scaleform::GFx::AS3::Instances::fl::GlobalObject *go)
{
  unsigned int Flags; // ecx
  Scaleform::GFx::AS3::Value *v7; // esi
  Scaleform::GFx::AS3::Value *v8; // esi
  Scaleform::GFx::AS3::Value::V2U v9; // eax
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // [esp-4h] [ebp-58h]
  Scaleform::GFx::AS3::Value v11; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::GFx::AS3::PropRef prop; // [esp+1Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS3::ReadMn args; // [esp+34h] [ebp-20h] BYREF

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
      v7 = ++this->OpStack.pCurrent;
      if ( v7 )
      {
        v7->Flags = Flags;
        v7->Bonus.pWeakProxy = prop.This.Bonus.pWeakProxy;
        v7->value.VNumber = prop.This.value.VNumber;
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
      v11.Flags = 12;
      v11.Bonus.pWeakProxy = 0;
      v11.value.VS._1.VInt = (int)go;
      if ( go )
        go->RefCount = (go->RefCount + 1) & 0x8FBFFFFF;
      v8 = ++this->OpStack.pCurrent;
      if ( v8 )
      {
        v8->value.VS._1.VInt = (int)go;
        v9.VObj = (Scaleform::GFx::AS3::Object *)v11.value.VS._2;
        v8->Flags = 12;
        v8->Bonus.pWeakProxy = 0;
        v8->value.VS._2 = v9;
        Scaleform::GFx::AS3::Value::AddRefInternal(&v11);
      }
      Scaleform::GFx::AS3::Value::~Value(&v11);
    }
    Scaleform::GFx::AS3::PropRef::~PropRef(&prop);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
