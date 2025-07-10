void __thiscall Scaleform::GFx::AS3::Instances::fl_text::TextField::getLineMetrics(
        Scaleform::GFx::AS3::Instances::fl_text::TextField *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        int lineIndex)
{
  Scaleform::GFx::AS3::Value *v4; // eax
  int i; // ecx
  double v6; // st7
  double v7; // st7
  unsigned int Flags; // eax
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Class *v21; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *v23; // esi
  int j; // edi
  unsigned int v25; // eax
  Scaleform::GFx::AS3::VMAppDomain *v_4; // [esp+4h] [ebp-C4h]
  Scaleform::StringDataPtr gname; // [esp+48h] [ebp-80h] BYREF
  Scaleform::Render::Text::DocView::LineMetrics metrics; // [esp+50h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value argv[6]; // [esp+68h] [ebp-60h] BYREF
  char vars0; // [esp+C8h] [ebp+0h] BYREF

  if ( Scaleform::Render::Text::DocView::GetLineMetrics(
         (Scaleform::Render::Text::DocView *)this->pDispObj.pObject[1].pRenNode.pObject,
         lineIndex,
         &metrics) )
  {
    v4 = argv;
    for ( i = 5; i >= 0; --i )
    {
      v4->Flags = 0;
      v4->Bonus.pWeakProxy = 0;
      ++v4;
    }
    gname.pStr = (const char *)(metrics.Ascent / 0x14);
    v6 = (double)(metrics.Ascent / 0x14);
    if ( v6 <= 0.0 )
      v7 = v6 - 0.5;
    else
      v7 = v6 + 0.5;
    gname.pStr = (const char *)(int)v7;
    Flags = argv[0].Flags;
    if ( (argv[0].Flags & 0x1F) > 9 )
    {
      if ( (argv[0].Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(argv);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(argv);
      Flags = argv[0].Flags;
    }
    argv[0].Flags = Flags & 0xFFFFFFE0 | 4;
    argv[0].value.VNumber = (double)(int)gname.pStr;
    gname.pStr = (const char *)(metrics.Descent / 0x14);
    v9 = (double)(metrics.Descent / 0x14);
    if ( v9 <= 0.0 )
      v10 = v9 - 0.5;
    else
      v10 = v9 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[1], (double)(int)v10);
    gname.pStr = (const char *)(metrics.Height / 0x14);
    v11 = (double)(metrics.Height / 0x14);
    if ( v11 <= 0.0 )
      v12 = v11 - 0.5;
    else
      v12 = v11 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[2], (double)(int)v12);
    gname.pStr = (const char *)(metrics.Leading / 20);
    v13 = (double)(metrics.Leading / 20);
    if ( v13 <= 0.0 )
      v14 = v13 - 0.5;
    else
      v14 = v13 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[3], (double)(int)v14);
    gname.pStr = (const char *)(metrics.Width / 0x14);
    v15 = (double)(metrics.Width / 0x14);
    if ( v15 <= 0.0 )
      v16 = v15 - 0.5;
    else
      v16 = v15 + 0.5;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[4], (double)(int)v16);
    gname.pStr = (const char *)(metrics.FirstCharXOff / 20);
    v17 = (double)(metrics.FirstCharXOff / 20);
    if ( v17 <= 0.0 )
      v18 = v17 - 0.5;
    else
      v18 = v17 + 0.5;
    gname.pStr = (const char *)(int)v18;
    Scaleform::GFx::AS3::Value::SetNumber(&argv[5], (double)(int)v18);
    pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
    v_4 = pVM->CurrentDomain;
    gname.pStr = "flash.text.TextLineMetrics";
    gname.Size = 26;
    Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, v_4);
    v21 = Class;
    if ( Class )
      Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 6u, argv);
    if ( v21 )
    {
      if ( ((unsigned __int8)v21 & 1) == 0 )
      {
        RefCount = v21->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
        {
          v21->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
        }
      }
    }
    v23 = (Scaleform::GFx::AS3::Value *)&vars0;
    for ( j = 5; j >= 0; --j )
    {
      v25 = v23[-1].Flags;
      --v23;
      if ( (v25 & 0x1F) > 9 )
      {
        if ( (v25 & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(v23);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(v23);
      }
    }
  }
}
