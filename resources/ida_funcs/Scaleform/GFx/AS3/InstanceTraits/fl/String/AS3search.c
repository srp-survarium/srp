void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3search(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *v6; // ebx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // ebp
  Scaleform::GFx::AS3::Value *v8; // edi
  unsigned int Flags; // edx
  Scaleform::GFx::AS3::Value::V2U v10; // eax
  Scaleform::GFx::AS3::Value *v11; // ecx
  Scaleform::GFx::AS3::Value *v12; // esi
  unsigned int v13; // eax
  Scaleform::GFx::AS3::Value *VInt; // esi
  Scaleform::GFx::AS3::Instances::fl::RegExp *v15; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM *v20; // esi
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::ASString str; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString pattern; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value::V2U v24; // [esp+18h] [ebp-14h]
  Scaleform::GFx::AS3::Value args[1]; // [esp+1Ch] [ebp-10h] BYREF

  v6 = vm;
  StringManagerRef = vm->StringManagerRef;
  v8 = result;
  if ( (result->Flags & 0x1F) > 9 )
  {
    if ( (result->Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(result);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(result);
  }
  Flags = v8->Flags;
  v8->value.VS._1.VInt = -1;
  v10.VObj = v24.VObj;
  v8->Flags = Flags & 0xFFFFFFE0 | 2;
  v8->value.VS._2 = v10;
  v11 = _this;
  str.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  ++str.pNode->RefCount;
  if ( Scaleform::GFx::AS3::Value::Convert2String(v11, (Scaleform::GFx::AS3::CheckResult *)&vm, &str)->Result )
  {
    if ( argc )
    {
      v12 = argv;
      v13 = argv->Flags & 0x1F;
      if ( v13 )
      {
        if ( v13 - 12 > 3 || argv->value.VS._1.VInt )
        {
          result = 0;
          if ( v13 - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(v6, argv, "RegExp", v6->CurrentDomain) )
          {
            VInt = (Scaleform::GFx::AS3::Value *)v12->value.VS._1.VInt;
            v15 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)result;
            if ( VInt != result )
            {
              if ( VInt )
              {
                VInt[1].Flags = (VInt[1].Flags + 1) & 0x8FBFFFFF;
                v15 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)result;
              }
              if ( v15 )
              {
                if ( ((unsigned __int8)v15 & 1) == 0 )
                {
                  RefCount = v15->RefCount;
                  if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
                  {
                    v15->RefCount = RefCount - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
                  }
                }
              }
              v15 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)VInt;
              result = VInt;
            }
LABEL_28:
            vm = 0;
            Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
              v15,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)&vm,
              &str);
            v20 = vm;
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&vm);
            if ( v20 )
              Scaleform::GFx::AS3::Value::SetSInt32(v8, (int)result[2].Bonus.pWeakProxy);
LABEL_30:
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&result);
            goto LABEL_31;
          }
          pStringManager = StringManagerRef->pStringManager;
          pattern.pNode = &pStringManager->EmptyStringNode;
          ++pStringManager->EmptyStringNode.RefCount;
          if ( Scaleform::GFx::AS3::Value::Convert2String(v12, (Scaleform::GFx::AS3::CheckResult *)&vm, &pattern)->Result )
          {
            Scaleform::GFx::AS3::Value::Value(args, &pattern);
            Scaleform::GFx::AS3::VM::constructBuiltinObject(
              v6,
              (Scaleform::GFx::AS3::CheckResult *)&vm,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
              "RegExp",
              1u,
              args);
            if ( (_BYTE)vm )
            {
              `vector destructor iterator'(
                (char *)args,
                0x10u,
                1,
                (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
              pNode = pattern.pNode;
              --pattern.pNode->RefCount;
              if ( !pNode->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              v15 = (Scaleform::GFx::AS3::Instances::fl::RegExp *)result;
              goto LABEL_28;
            }
            `vector destructor iterator'(
              (char *)args,
              0x10u,
              1,
              (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
          }
          v18 = pattern.pNode;
          --pattern.pNode->RefCount;
          if ( !v18->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v18);
          goto LABEL_30;
        }
      }
    }
  }
LABEL_31:
  v21 = str.pNode;
  --str.pNode->RefCount;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}
