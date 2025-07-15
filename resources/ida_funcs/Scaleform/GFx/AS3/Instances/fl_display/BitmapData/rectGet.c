void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::rectGet(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v6; // eax
  int i; // ecx
  unsigned int Flags; // eax
  double Width; // st7
  double v10; // st7
  double Height; // st7
  double v12; // st7
  Scaleform::GFx::AS3::Value *v13; // esi
  int j; // edi
  unsigned int v15; // eax
  Scaleform::GFx::AS3::VM::Error v16; // [esp+10h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value argv[4]; // [esp+18h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+58h] [ebp+0h] BYREF

  if ( this->pImage.pObject )
  {
    v6 = argv;
    for ( i = 3; i >= 0; --i )
    {
      v6->Flags = 0;
      v6->Bonus.pWeakProxy = 0;
      ++v6;
    }
    v16.ID = (int)(0.0 - 0.5);
    Flags = argv[0].Flags;
    if ( (argv[0].Flags & 0x1F) > 9 )
    {
      if ( (argv[0].Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(argv);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(argv);
      Flags = argv[0].Flags;
    }
    argv[0].value.VNumber = (double)(int)v16.ID;
    argv[0].Flags = Flags & 0xFFFFFFE0 | 4;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[1], argv[0].value.VNumber);
    Width = (double)this->Width;
    if ( Width <= 0.0 )
      v10 = Width - 0.5;
    else
      v10 = Width + 0.5;
    v16.ID = (int)v10;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[2], (double)(int)v10);
    Height = (double)this->Height;
    if ( Height <= 0.0 )
      v12 = Height - 0.5;
    else
      v12 = Height + 0.5;
    v16.ID = (int)v12;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[3], (double)(int)v12);
    Scaleform::GFx::AS3::ASVM::_constructInstance(
      (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
      result,
      (Scaleform::GFx::AS3::Object *)this->pTraits.pObject->pVM[1].ScopeStack.Data.Policy.Capacity,
      4u,
      argv);
    v13 = (Scaleform::GFx::AS3::Value *)&retaddr;
    for ( j = 3; j >= 0; --j )
    {
      v15 = v13[-1].Flags;
      --v13;
      if ( (v15 & 0x1F) > 9 )
      {
        if ( (v15 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v13);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v13);
      }
    }
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v4);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
