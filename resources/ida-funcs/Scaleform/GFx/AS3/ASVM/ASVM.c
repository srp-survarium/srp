void __thiscall Scaleform::GFx::AS3::ASVM::ASVM(
        Scaleform::GFx::AS3::ASVM *this,
        Scaleform::GFx::AS3::MovieRoot *pmr,
        Scaleform::GFx::AS3::FlashUI *_ui,
        Scaleform::GFx::AS3::FileLoader *loader,
        Scaleform::GFx::AS3::StringManager *sm,
        Scaleform::GFx::AS3::ASRefCountCollector *gc)
{
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Class *v8; // eax
  Scaleform::GFx::AS3::Class *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::AS3::Class *v11; // eax
  Scaleform::GFx::AS3::Class *v12; // eax
  Scaleform::GFx::AS3::Class *v13; // eax
  Scaleform::GFx::AS3::Class *v14; // eax
  Scaleform::GFx::AS3::Class *v15; // eax
  Scaleform::GFx::AS3::Class *v16; // eax
  Scaleform::GFx::AS3::Class *v17; // eax
  Scaleform::GFx::AS3::Class *v18; // eax
  Scaleform::GFx::AS3::Class *v19; // eax
  Scaleform::GFx::AS3::Class *v20; // eax
  Scaleform::GFx::AS3::Class *v21; // eax
  Scaleform::GFx::AS3::Class *v22; // eax
  Scaleform::GFx::AS3::Class *v23; // eax
  Scaleform::GFx::AS3::Class *v24; // eax
  Scaleform::GFx::AS3::Class *v25; // eax
  Scaleform::GFx::AS3::Class *v26; // eax
  Scaleform::GFx::AS3::Class *v27; // eax
  Scaleform::GFx::AS3::Class *v28; // eax
  Scaleform::GFx::AS3::Class *v29; // eax
  Scaleform::GFx::ASStringNode *CurrentDomain; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v31; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v32; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v33; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v34; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v35; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v36; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v37; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v38; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v39; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v40; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v41; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v42; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v43; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v44; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v45; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v46; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v47; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v48; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v49; // [esp-4h] [ebp-1Ch]
  Scaleform::GFx::ASStringNode *v50; // [esp-4h] [ebp-1Ch]
  Scaleform::StringDataPtr gname; // [esp+10h] [ebp-8h] BYREF

  Scaleform::GFx::AS3::VM::VM(this, _ui, loader, sm, (const Scaleform::GFx::AS3::Instances::fl::Namespace *)gc);
  this->pMovieRoot = pmr;
  this->__vftable = (Scaleform::GFx::AS3::ASVM_vtbl *)&Scaleform::GFx::AS3::ASVM::`vftable';
  this->GraphicsClass.pObject = 0;
  this->TransformClass.pObject = 0;
  this->MatrixClass.pObject = 0;
  this->Matrix3DClass.pObject = 0;
  this->PerspectiveProjectionClass.pObject = 0;
  this->ColorTransformClass.pObject = 0;
  this->EventClass.pObject = 0;
  this->MouseEventClass.pObject = 0;
  this->MouseEventExClass.pObject = 0;
  this->KeyboardEventClass.pObject = 0;
  this->KeyboardEventExClass.pObject = 0;
  this->FocusEventClass.pObject = 0;
  this->FocusEventExClass.pObject = 0;
  this->TextEventClass.pObject = 0;
  this->TextEventExClass.pObject = 0;
  this->TimerEventClass.pObject = 0;
  this->ProgressEventClass.pObject = 0;
  this->StageOrientationEventClass.pObject = 0;
  this->AppLifecycleEventClass.pObject = 0;
  this->PointClass.pObject = 0;
  this->RectangleClass.pObject = 0;
  this->TextFormatClass.pObject = 0;
  this->EventDispatcherClass.pObject = 0;
  this->Vector3DClass.pObject = 0;
  this->ExtensionsEnabled = 0;
  CurrentDomain = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.display.Graphics";
  gname.Size = 22;
  Class = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, CurrentDomain);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->GraphicsClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)Class);
  v31 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.Transform";
  gname.Size = 20;
  v8 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v31);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->TransformClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v8);
  v32 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.Matrix";
  gname.Size = 17;
  v9 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v32);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->MatrixClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v9);
  v10 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.Matrix3D";
  gname.Size = 19;
  v11 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v10);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Matrix3DClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v11);
  v33 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.PerspectiveProjection";
  gname.Size = 32;
  v12 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v33);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->PerspectiveProjectionClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v12);
  v34 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.ColorTransform";
  gname.Size = 25;
  v13 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v34);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->ColorTransformClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v13);
  v35 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.Event";
  gname.Size = 18;
  v14 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v35);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->EventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v14);
  v36 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.MouseEvent";
  gname.Size = 23;
  v15 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v36);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->MouseEventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v15);
  v37 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.KeyboardEvent";
  gname.Size = 26;
  v16 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v37);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->KeyboardEventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v16);
  v38 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.FocusEvent";
  gname.Size = 23;
  v17 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v38);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->FocusEventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v17);
  v39 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.TextEvent";
  gname.Size = 22;
  v18 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v39);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->TextEventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v18);
  v40 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "scaleform.gfx.MouseEventEx";
  gname.Size = 26;
  v19 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v40);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->MouseEventExClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v19);
  v41 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "scaleform.gfx.KeyboardEventEx";
  gname.Size = 29;
  v20 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v41);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->KeyboardEventExClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v20);
  v42 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "scaleform.gfx.FocusEventEx";
  gname.Size = 26;
  v21 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v42);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->FocusEventExClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v21);
  v43 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "scaleform.gfx.TextEventEx";
  gname.Size = 25;
  v22 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v43);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->TextEventExClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v22);
  v44 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.TimerEvent";
  gname.Size = 23;
  v23 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v44);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->TimerEventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v23);
  v45 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.ProgressEvent";
  gname.Size = 26;
  v24 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v45);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->ProgressEventClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v24);
  v46 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.Point";
  gname.Size = 16;
  v25 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v46);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->PointClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v25);
  v47 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.Rectangle";
  gname.Size = 20;
  v26 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v47);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->RectangleClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v26);
  v48 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.text.TextFormat";
  gname.Size = 21;
  v27 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v48);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->TextFormatClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v27);
  v49 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.events.EventDispatcher";
  gname.Size = 28;
  v28 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v49);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->EventDispatcherClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v28);
  v50 = (Scaleform::GFx::ASStringNode *)this->CurrentDomain;
  gname.pStr = "flash.geom.Vector3D";
  gname.Size = 19;
  v29 = Scaleform::GFx::AS3::VM::GetClass(this, (Scaleform::GFx::ASStringNode *)&gname, v50);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->Vector3DClass,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v29);
}
