void __usercall Scaleform::GFx::AS3::ASVM::~ASVM(Scaleform::GFx::AS3::ASVM *this@<ecx>, int a2@<edi>)
{
  Scaleform::GFx::AS3::Class *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Class *v5; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS3::Class *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Class *v9; // ecx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Class *v11; // ecx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::Class *v13; // ecx
  unsigned int v14; // eax
  Scaleform::GFx::AS3::Class *v15; // ecx
  unsigned int v16; // eax
  Scaleform::GFx::AS3::Class *v17; // ecx
  unsigned int v18; // eax
  Scaleform::GFx::AS3::Class *v19; // ecx
  unsigned int v20; // eax
  Scaleform::GFx::AS3::Class *v21; // ecx
  unsigned int v22; // eax
  Scaleform::GFx::AS3::Class *v23; // ecx
  unsigned int v24; // eax
  Scaleform::GFx::AS3::Class *v25; // ecx
  unsigned int v26; // eax
  Scaleform::GFx::AS3::Class *v27; // ecx
  unsigned int v28; // eax
  Scaleform::GFx::AS3::Class *v29; // ecx
  unsigned int v30; // eax
  Scaleform::GFx::AS3::Class *v31; // ecx
  unsigned int v32; // eax
  Scaleform::GFx::AS3::Class *v33; // ecx
  unsigned int v34; // eax
  Scaleform::GFx::AS3::Class *v35; // ecx
  unsigned int v36; // eax
  Scaleform::GFx::AS3::Class *v37; // ecx
  unsigned int v38; // eax
  Scaleform::GFx::AS3::Class *v39; // ecx
  unsigned int v40; // eax
  Scaleform::GFx::AS3::Class *v41; // ecx
  unsigned int v42; // eax
  Scaleform::GFx::AS3::Class *v43; // ecx
  unsigned int v44; // eax
  Scaleform::GFx::AS3::Class *v45; // ecx
  unsigned int v46; // eax
  Scaleform::GFx::AS3::Class *v47; // ecx
  unsigned int v48; // eax
  Scaleform::GFx::AS3::Class *v49; // ecx
  unsigned int v50; // eax

  pObject = this->Vector3DClass.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Vector3DClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  v5 = this->EventDispatcherClass.pObject;
  if ( v5 )
  {
    if ( ((unsigned __int8)v5 & 1) != 0 )
    {
      this->EventDispatcherClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v5 - 1);
    }
    else
    {
      v6 = v5->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v6) != 0 )
      {
        v5->RefCount = v6 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
      }
    }
  }
  v7 = this->TextFormatClass.pObject;
  if ( v7 )
  {
    if ( ((unsigned __int8)v7 & 1) != 0 )
    {
      this->TextFormatClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v7 - 1);
    }
    else
    {
      v8 = v7->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v8) != 0 )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
      }
    }
  }
  v9 = this->RectangleClass.pObject;
  if ( v9 )
  {
    if ( ((unsigned __int8)v9 & 1) != 0 )
    {
      this->RectangleClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v9 - 1);
    }
    else
    {
      v10 = v9->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v10) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
  v11 = this->PointClass.pObject;
  if ( v11 )
  {
    if ( ((unsigned __int8)v11 & 1) != 0 )
    {
      this->PointClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v11 - 1);
    }
    else
    {
      v12 = v11->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v12) != 0 )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
      }
    }
  }
  v13 = this->AppLifecycleEventClass.pObject;
  if ( v13 )
  {
    if ( ((unsigned __int8)v13 & 1) != 0 )
    {
      this->AppLifecycleEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v13 - 1);
    }
    else
    {
      v14 = v13->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v14) != 0 )
      {
        v13->RefCount = v14 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v13);
      }
    }
  }
  v15 = this->StageOrientationEventClass.pObject;
  if ( v15 )
  {
    if ( ((unsigned __int8)v15 & 1) != 0 )
    {
      this->StageOrientationEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v15 - 1);
    }
    else
    {
      v16 = v15->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v16) != 0 )
      {
        v15->RefCount = v16 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v15);
      }
    }
  }
  v17 = this->ProgressEventClass.pObject;
  if ( v17 )
  {
    if ( ((unsigned __int8)v17 & 1) != 0 )
    {
      this->ProgressEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v17 - 1);
    }
    else
    {
      v18 = v17->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v18) != 0 )
      {
        v17->RefCount = v18 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v17);
      }
    }
  }
  v19 = this->TimerEventClass.pObject;
  if ( v19 )
  {
    if ( ((unsigned __int8)v19 & 1) != 0 )
    {
      this->TimerEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v19 - 1);
    }
    else
    {
      v20 = v19->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v20) != 0 )
      {
        v19->RefCount = v20 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
      }
    }
  }
  v21 = this->TextEventExClass.pObject;
  if ( v21 )
  {
    if ( ((unsigned __int8)v21 & 1) != 0 )
    {
      this->TextEventExClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v21 - 1);
    }
    else
    {
      v22 = v21->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v22) != 0 )
      {
        v21->RefCount = v22 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
      }
    }
  }
  v23 = this->TextEventClass.pObject;
  if ( v23 )
  {
    if ( ((unsigned __int8)v23 & 1) != 0 )
    {
      this->TextEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v23 - 1);
    }
    else
    {
      v24 = v23->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v24) != 0 )
      {
        v23->RefCount = v24 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
      }
    }
  }
  v25 = this->FocusEventExClass.pObject;
  if ( v25 )
  {
    if ( ((unsigned __int8)v25 & 1) != 0 )
    {
      this->FocusEventExClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v25 - 1);
    }
    else
    {
      v26 = v25->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v26) != 0 )
      {
        v25->RefCount = v26 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
      }
    }
  }
  v27 = this->FocusEventClass.pObject;
  if ( v27 )
  {
    if ( ((unsigned __int8)v27 & 1) != 0 )
    {
      this->FocusEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v27 - 1);
    }
    else
    {
      v28 = v27->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v28) != 0 )
      {
        v27->RefCount = v28 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
      }
    }
  }
  v29 = this->KeyboardEventExClass.pObject;
  if ( v29 )
  {
    if ( ((unsigned __int8)v29 & 1) != 0 )
    {
      this->KeyboardEventExClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v29 - 1);
    }
    else
    {
      v30 = v29->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v30) != 0 )
      {
        v29->RefCount = v30 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
      }
    }
  }
  v31 = this->KeyboardEventClass.pObject;
  if ( v31 )
  {
    if ( ((unsigned __int8)v31 & 1) != 0 )
    {
      this->KeyboardEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v31 - 1);
    }
    else
    {
      v32 = v31->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v32) != 0 )
      {
        v31->RefCount = v32 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v31);
      }
    }
  }
  v33 = this->MouseEventExClass.pObject;
  if ( v33 )
  {
    if ( ((unsigned __int8)v33 & 1) != 0 )
    {
      this->MouseEventExClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v33 - 1);
    }
    else
    {
      v34 = v33->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v34) != 0 )
      {
        v33->RefCount = v34 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v33);
      }
    }
  }
  v35 = this->MouseEventClass.pObject;
  if ( v35 )
  {
    if ( ((unsigned __int8)v35 & 1) != 0 )
    {
      this->MouseEventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v35 - 1);
    }
    else
    {
      v36 = v35->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v36) != 0 )
      {
        v35->RefCount = v36 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v35);
      }
    }
  }
  v37 = this->EventClass.pObject;
  if ( v37 )
  {
    if ( ((unsigned __int8)v37 & 1) != 0 )
    {
      this->EventClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v37 - 1);
    }
    else
    {
      v38 = v37->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v38) != 0 )
      {
        v37->RefCount = v38 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v37);
      }
    }
  }
  v39 = this->ColorTransformClass.pObject;
  if ( v39 )
  {
    if ( ((unsigned __int8)v39 & 1) != 0 )
    {
      this->ColorTransformClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v39 - 1);
    }
    else
    {
      v40 = v39->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v40) != 0 )
      {
        v39->RefCount = v40 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v39);
      }
    }
  }
  v41 = this->PerspectiveProjectionClass.pObject;
  if ( v41 )
  {
    if ( ((unsigned __int8)v41 & 1) != 0 )
    {
      this->PerspectiveProjectionClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v41 - 1);
    }
    else
    {
      v42 = v41->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v42) != 0 )
      {
        v41->RefCount = v42 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v41);
      }
    }
  }
  v43 = this->Matrix3DClass.pObject;
  if ( v43 )
  {
    if ( ((unsigned __int8)v43 & 1) != 0 )
    {
      this->Matrix3DClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v43 - 1);
    }
    else
    {
      v44 = v43->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v44) != 0 )
      {
        v43->RefCount = v44 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v43);
      }
    }
  }
  v45 = this->MatrixClass.pObject;
  if ( v45 )
  {
    if ( ((unsigned __int8)v45 & 1) != 0 )
    {
      this->MatrixClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v45 - 1);
    }
    else
    {
      v46 = v45->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v46) != 0 )
      {
        v45->RefCount = v46 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
      }
    }
  }
  v47 = this->TransformClass.pObject;
  if ( v47 )
  {
    if ( ((unsigned __int8)v47 & 1) != 0 )
    {
      this->TransformClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v47 - 1);
    }
    else
    {
      v48 = v47->RefCount;
      if ( ((unsigned int)&byte_3FFFFF & v48) != 0 )
      {
        v47->RefCount = v48 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v47);
      }
    }
  }
  v49 = this->GraphicsClass.pObject;
  if ( v49 )
  {
    if ( ((unsigned __int8)v49 & 1) != 0 )
    {
      this->GraphicsClass.pObject = (Scaleform::GFx::AS3::Class *)((char *)v49 - 1);
      Scaleform::GFx::AS3::VM::~VM(this, a2);
      return;
    }
    v50 = v49->RefCount;
    if ( ((unsigned int)&byte_3FFFFF & v50) != 0 )
    {
      v49->RefCount = v50 - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v49);
    }
  }
  Scaleform::GFx::AS3::VM::~VM(this, a2);
}
