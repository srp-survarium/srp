void __thiscall Scaleform::GFx::AS3::MovieRoot::CreateObject(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const char *className,
        Scaleform::GFx::Value *pargs,
        unsigned int nargs)
{
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::Value *v7; // esi
  Scaleform::GFx::AS3::Value *v9; // eax
  const char *v10; // edx
  Scaleform::GFx::AS3::ASVM *pObject; // ecx
  Scaleform::GFx::ASStringNode *AppDomain; // eax
  bool v13; // al
  Scaleform::GFx::AS3::ASVM *v14; // ecx
  Scaleform::GFx::AS3::Value *v15; // esi
  unsigned int v16; // ebp
  Scaleform::GFx::AS3::WeakProxy *v17; // eax
  bool v18; // zf
  Scaleform::GFx::AS3::ASVM *v19; // ecx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::WeakProxy *v22; // eax
  Scaleform::GFx::ASStringNode *VStr; // eax
  int VInt; // eax
  int v25; // edx
  Scaleform::GFx::AS3::Value *pargArray; // [esp+10h] [ebp-12Ch]
  Scaleform::GFx::AS3::Value obj; // [esp+14h] [ebp-128h] BYREF
  void *argArrayOnStack[70]; // [esp+24h] [ebp-118h] BYREF

  v5 = nargs;
  if ( nargs <= 0xA )
    pargArray = (Scaleform::GFx::AS3::Value *)argArrayOnStack;
  else
    pargArray = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                16 * nargs,
                                                0);
  if ( nargs )
  {
    v7 = pargArray;
    do
    {
      v9 = 0;
      if ( v7 )
      {
        v7->Flags = 0;
        v7->Bonus.pWeakProxy = 0;
        v9 = v7;
      }
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, (Scaleform::GFx::ASStringNode *)pargs++, v9);
      ++v7;
      --v5;
    }
    while ( v5 );
    v5 = nargs;
  }
  obj.Flags = 0;
  obj.Bonus.pWeakProxy = 0;
  v10 = className;
  if ( !className )
    v10 = "Object";
  pObject = this->pAVM.pObject;
  if ( pObject->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
  {
    v5 = nargs;
    AppDomain = (Scaleform::GFx::ASStringNode *)pObject->CallStack.Pages[(pObject->CallStack.Size - 1) >> 6][(pObject->CallStack.Size - 1) & 0x3F].pFile->AppDomain;
  }
  else
  {
    AppDomain = (Scaleform::GFx::ASStringNode *)pObject->CurrentDomain;
  }
  v13 = Scaleform::GFx::AS3::VM::Construct(pObject, v10, AppDomain, &obj, v5, pargArray, 0);
  v14 = this->pAVM.pObject;
  if ( !v14->HandleException )
  {
    if ( v13 )
      Scaleform::GFx::AS3::VM::ExecuteCode(v14, 1u);
    goto LABEL_19;
  }
  printf(v5, (int)&obj, "Exception in CreateObject(\"%s\"):\n\t", className);
  v19 = this->pAVM.pObject;
  p_ExceptionObj = &v19->ExceptionObj;
  v19->HandleException = 0;
  Scaleform::GFx::AS3::VM::OutputError(v19, &v19->ExceptionObj);
  if ( (p_ExceptionObj->Flags & 0x1F) <= 9 )
  {
LABEL_32:
    p_ExceptionObj->Flags &= 0xFFFFFFE0;
    goto LABEL_19;
  }
  if ( (p_ExceptionObj->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
    goto LABEL_32;
  }
  pWeakProxy = p_ExceptionObj->Bonus.pWeakProxy;
  v18 = pWeakProxy->RefCount-- == 1;
  if ( v18 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  p_ExceptionObj->Flags &= 0xFFFFFDE0;
  p_ExceptionObj->Flags &= 0xFFFFFFE0;
  p_ExceptionObj->Bonus.pWeakProxy = 0;
  p_ExceptionObj->value.VS._1.VInt = 0;
  p_ExceptionObj->value.VS._2.VObj = 0;
LABEL_19:
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &obj, (Scaleform::GFx::ASStringNode *)pvalue);
  if ( v5 )
  {
    v15 = pargArray;
    v16 = v5;
    do
    {
      if ( (v15->Flags & 0x1F) > 9 )
      {
        if ( (v15->Flags & 0x200) != 0 )
        {
          v17 = v15->Bonus.pWeakProxy;
          v18 = v17->RefCount-- == 1;
          if ( v18 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v17);
          v15->Flags &= 0xFFFFFDE0;
          v15->Bonus.pWeakProxy = 0;
          v15->value.VS._1.VInt = 0;
          v15->value.VS._2.VObj = 0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v15);
        }
      }
      ++v15;
      --v16;
    }
    while ( v16 );
  }
  if ( v5 > 0x46 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pargArray);
  if ( (obj.Flags & 0x1F) > 9 )
  {
    if ( (obj.Flags & 0x200) != 0 )
    {
      v22 = obj.Bonus.pWeakProxy;
      --obj.Bonus.pWeakProxy->RefCount;
      if ( !v22->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
    }
    else
    {
      switch ( obj.Flags & 0x1F )
      {
        case 0xA:
          VStr = obj.value.VS._1.VStr;
          --*(_DWORD *)(obj.value.VS._1.VInt + 12);
          if ( !VStr->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          VInt = obj.value.VS._1.VInt;
          goto LABEL_46;
        case 0x10:
        case 0x11:
          VInt = (int)obj.value.VS._2.VObj;
LABEL_46:
          if ( (VInt & 1) == 0 )
          {
            if ( VInt )
            {
              v25 = *(_DWORD *)(VInt + 16);
              if ( (v25 & 0x3FFFFF) != 0 )
              {
                *(_DWORD *)(VInt + 16) = v25 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)VInt);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}
