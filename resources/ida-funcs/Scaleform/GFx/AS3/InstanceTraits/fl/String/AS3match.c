void __cdecl Scaleform::GFx::AS3::InstanceTraits::fl::String::AS3match(
        const Scaleform::GFx::AS3::ThunkInfo *ti,
        Scaleform::GFx::AS3::Object *vm,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::VM *v6; // ebx
  Scaleform::GFx::AS3::StringManager *pPrev; // edi
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v9; // esi
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Instances::fl::RegExp *VInt; // esi
  Scaleform::GFx::AS3::Instances::fl::RegExp *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl::RegExp *v13; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // esi
  Scaleform::GFx::AS3::Object *v19; // ebx
  unsigned int Length; // ecx
  unsigned int v21; // eax
  const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v22; // eax
  Scaleform::GFx::ASStringNode *v23; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::RegExp> pre; // [esp+Ch] [ebp-24h] BYREF
  Scaleform::GFx::ASString str; // [esp+10h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> parr; // [esp+14h] [ebp-1Ch] BYREF
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+18h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value args[1]; // [esp+20h] [ebp-10h] BYREF

  v6 = (Scaleform::GFx::AS3::VM *)vm;
  pPrev = (Scaleform::GFx::AS3::StringManager *)vm->pPrev;
  str.pNode = &pPrev->pStringManager->EmptyStringNode;
  ++str.pNode->RefCount;
  if ( !Scaleform::GFx::AS3::Value::Convert2String(_this, (Scaleform::GFx::AS3::CheckResult *)&vm, &str)->Result )
  {
    pNode = str.pNode;
    --str.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  if ( argc )
  {
    v9 = argv;
    v10 = argv->Flags & 0x1F;
    if ( v10 )
    {
      if ( v10 - 12 > 3 || argv->value.VS._1.VInt )
      {
        pre.pObject = 0;
        if ( v10 - 12 <= 3 && Scaleform::GFx::AS3::VM::IsOfType(v6, argv, "RegExp", v6->CurrentDomain) )
        {
          VInt = (Scaleform::GFx::AS3::Instances::fl::RegExp *)v9->value.VS._1.VInt;
          pObject = pre.pObject;
          if ( VInt != pre.pObject )
          {
            VInt->RefCount = (VInt->RefCount + 1) & 0x8FBFFFFF;
            v13 = pre.pObject;
            if ( pre.pObject )
            {
              if ( ((int)pre.pObject & 1) == 0 )
              {
                RefCount = pre.pObject->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  pre.pObject->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
                }
              }
            }
            pObject = VInt;
            pre.pObject = VInt;
          }
LABEL_27:
          if ( pObject->IsGlobal )
          {
            pV = Scaleform::GFx::AS3::VM::MakeArray(
                   v6,
                   (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)&vm)->pV;
            parr.pObject = pV;
            while ( 1 )
            {
              vm = 0;
              Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
                pre.pObject,
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)&vm,
                &str);
              v19 = vm;
              if ( !vm )
                break;
              args[0].Flags = 0;
              args[0].Bonus.pWeakProxy = 0;
              Scaleform::GFx::AS3::Value::AssignUnsafe(args, vm);
              Length = pV->SA.Length;
              if ( Length == pV->SA.ValueA.Data.Size )
              {
                Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
                  &pV->SA.ValueA.Data,
                  args);
              }
              else
              {
                pV->SA.ValueHHighInd = Length;
                key.pFirst = &pV->SA.ValueHHighInd;
                key.pSecond = args;
                Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
                  &pV->SA.ValueH.mHash,
                  pV->SA.ValueH.mHash.pHeap,
                  &key);
              }
              ++pV->SA.Length;
              if ( (args[0].Flags & 0x1F) > 9 )
              {
                if ( (args[0].Flags & 0x200) != 0 )
                  Scaleform::GFx::AS3::Value::ReleaseWeakRef(args);
                else
                  Scaleform::GFx::AS3::Value::ReleaseInternal(args);
              }
              if ( ((unsigned __int8)v19 & 1) == 0 )
              {
                v21 = v19->RefCount;
                if ( (v21 & 0x3FFFFF) != 0 )
                {
                  v19->RefCount = v21 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
                }
              }
            }
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&vm);
            Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::Object>(result, &parr);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&parr);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pre);
          }
          else
          {
            v22 = (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *)Scaleform::GFx::AS3::Instances::fl::RegExp::AS3exec(
                                                                                                  pObject,
                                                                                                  (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Object> *)&vm,
                                                                                                  &str);
            Scaleform::GFx::AS3::Value::operator=<Scaleform::GFx::AS3::Instances::fl::Object>(result, v22);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&vm);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pre);
          }
          goto LABEL_42;
        }
        parr.pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)&pPrev->pStringManager->EmptyStringNode;
        ++parr.pObject->pPrev;
        if ( Scaleform::GFx::AS3::Value::Convert2String(
               v9,
               (Scaleform::GFx::AS3::CheckResult *)&vm,
               (Scaleform::GFx::ASString *)&parr)->Result )
        {
          Scaleform::GFx::AS3::Value::Value(args, (const Scaleform::GFx::ASString *)&parr);
          Scaleform::GFx::AS3::VM::constructBuiltinObject(
            v6,
            (Scaleform::GFx::AS3::CheckResult *)&vm,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&pre,
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
            v17 = (Scaleform::GFx::ASStringNode *)parr.pObject;
            --parr.pObject->pPrev;
            if ( !v17->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v17);
            pObject = pre.pObject;
            goto LABEL_27;
          }
          `vector destructor iterator'(
            (char *)args,
            0x10u,
            1,
            (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
          v16 = (Scaleform::GFx::ASStringNode *)parr.pObject;
          --parr.pObject->pPrev;
          if ( !v16->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
        else
        {
          v15 = (Scaleform::GFx::ASStringNode *)parr.pObject;
          --parr.pObject->pPrev;
          if ( !v15->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&pre);
      }
    }
  }
LABEL_42:
  v23 = str.pNode;
  --str.pNode->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
}
