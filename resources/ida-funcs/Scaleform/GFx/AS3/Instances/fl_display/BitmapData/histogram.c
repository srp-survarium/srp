void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::histogram(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *hRect)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *ID; // ebp
  const Scaleform::GFx::AS3::VM::Error *v4; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::Rect<long> *p_x; // edi
  int y; // ebp
  int v8; // eax
  long double v9; // st7
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Traits *v12; // ecx
  int v13; // edi
  Scaleform::GFx::AS3::Value::V1U *v14; // edi
  Scaleform::GFx::AS3::Value::V1U v15; // esi
  Scaleform::GFx::AS3::Traits *v16; // eax
  Scaleform::GFx::AS3::Object *v17; // ecx
  bool v18; // bl
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v20; // ecx
  Scaleform::GFx::AS3::Traits *v21; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *v22; // esi
  bool v23; // bl
  unsigned int v24; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v25; // ecx
  unsigned int *v26; // esi
  int j; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v28; // ecx
  unsigned int *v29; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v33; // ecx
  unsigned int *v34; // esi
  int k; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v36; // ecx
  unsigned int v37; // eax
  unsigned int v38; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v39; // ecx
  unsigned int *v40; // esi
  int i; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // eax
  Scaleform::StringDataPtr v45; // [esp-4h] [ebp-10F0h]
  Scaleform::GFx::AS3::Object *v46; // [esp+0h] [ebp-10ECh]
  Scaleform::GFx::AS3::CheckResult resulta; // [esp+17h] [ebp-10D5h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *pobj; // [esp+18h] [ebp-10D4h]
  Scaleform::GFx::AS3::Value v; // [esp+1Ch] [ebp-10D0h] BYREF
  Scaleform::GFx::AS3::Value argv; // [esp+2Ch] [ebp-10C0h] BYREF
  Scaleform::GFx::AS3::Value v51; // [esp+3Ch] [ebp-10B0h] BYREF
  Scaleform::GFx::AS3::Value::V1U v52; // [esp+4Ch] [ebp-10A0h]
  char v53; // [esp+52h] [ebp-109Ah] BYREF
  char v54; // [esp+53h] [ebp-1099h] BYREF
  Scaleform::GFx::AS3::VM::Error v55; // [esp+54h] [ebp-1098h] BYREF
  int x; // [esp+5Ch] [ebp-1090h] BYREF
  int v57; // [esp+60h] [ebp-108Ch]
  int v58; // [esp+64h] [ebp-1088h]
  int v59; // [esp+68h] [ebp-1084h]
  Scaleform::GFx::AS3::Multiname v60; // [esp+6Ch] [ebp-1080h] BYREF
  Scaleform::GFx::AS3::Multiname v61; // [esp+84h] [ebp-1068h] BYREF
  Scaleform::GFx::AS3::Value v62; // [esp+9Ch] [ebp-1050h] BYREF
  Scaleform::GFx::AS3::Value name; // [esp+ACh] [ebp-1040h] BYREF
  Scaleform::GFx::AS3::Value v64; // [esp+BCh] [ebp-1030h] BYREF
  Scaleform::GFx::AS3::Value v65; // [esp+CCh] [ebp-1020h] BYREF
  char v66[16]; // [esp+DCh] [ebp-1010h] BYREF
  unsigned int colors[256]; // [esp+ECh] [ebp-1000h] BYREF

  ID = this;
  v55.ID = (Scaleform::GFx::AS3::VM::ErrorID)this;
  if ( !this->pImage.pObject )
  {
    v45.pStr = "Invalid BitmapData";
    v45.Size = 18;
    Scaleform::GFx::AS3::VM::Error::Error(&v55, eArgumentError, this->pTraits.pObject->pVM, v45);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(ID->pTraits.pObject->pVM, v4);
    pNode = v55.Message.pNode;
    --v55.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return;
  }
  p_x = 0;
  x = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  if ( hRect )
  {
    y = (int)hRect->y;
    v8 = (int)(hRect->width + hRect->x);
    v9 = hRect->height + hRect->y;
    x = (int)hRect->x;
    v57 = y;
    v58 = v8;
    ID = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v55.ID;
    v59 = (int)v9;
    p_x = (Scaleform::Render::Rect<long> *)&x;
  }
  DrawableImageFromBitmapData = Scaleform::GFx::AS3::Instances::fl_display::BitmapData::getDrawableImageFromBitmapData(
                                  ID,
                                  ID);
  Scaleform::Render::DrawableImage::Histogram(DrawableImageFromBitmapData, p_x, (unsigned int (*)[256])colors);
  pObject = ID->pTraits.pObject;
  argv.Flags = 3;
  argv.Bonus.pWeakProxy = 0;
  argv.value.VS._1.VInt = 4;
  v.Flags = 0;
  v.Bonus.pWeakProxy = 0;
  if ( !Scaleform::GFx::AS3::VM::ConstructBuiltinValue(
          pObject->pVM,
          &resulta,
          &v,
          "Vector.<Vector.<Number>>",
          1u,
          &argv)->Result )
  {
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    `vector destructor iterator'(
      (char *)&argv,
      0x10u,
      1,
      (void (__thiscall *)(void *))Scaleform::GFx::AS3::Value::~Value);
    return;
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    result,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v.value.VS._1.VInt);
  `vector constructor iterator'(
    v66,
    4u,
    4,
    (void *(__thiscall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure');
  v52.VInt = 0;
  pobj = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)v66;
  v55.ID = (Scaleform::GFx::AS3::VM::ErrorID)colors;
LABEL_13:
  v12 = ID->pTraits.pObject;
  v13 = 3;
  v51.Flags = 3;
  v51.Bonus.pWeakProxy = 0;
  v51.value.VS._1.VInt = 256;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(v12->pVM, &resulta, pobj, "Vector.<Number>", 1u, &v51);
  if ( resulta.Result )
  {
    v14 = (Scaleform::GFx::AS3::Value::V1U *)v55.ID;
    v15.VInt = 0;
    while ( 1 )
    {
      v16 = ID->pTraits.pObject;
      name.Flags = 3;
      name.Bonus.pWeakProxy = 0;
      name.value.VS._1 = v15;
      Scaleform::GFx::AS3::Multiname::Multiname(&v61, v16->pVM->PublicNamespace.pObject, &name);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v17 = pobj->pObject;
      v62.value.VS._1 = *v14;
      v62.Flags = 3;
      v62.Bonus.pWeakProxy = 0;
      v18 = !v17->SetProperty(v17, (Scaleform::GFx::AS3::CheckResult *)&v54, &v61, &v62)->Result;
      if ( (v62.Flags & 0x1F) > 9 )
      {
        if ( (v62.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v62);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v62);
      }
      if ( v18 )
        break;
      if ( (v61.Name.Flags & 0x1F) > 9 )
      {
        if ( (v61.Name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v61.Name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v61.Name);
      }
      if ( v61.Obj.pObject )
      {
        if ( ((int)v61.Obj.pObject & 1) == 0 )
        {
          RefCount = v61.Obj.pObject->RefCount;
          if ( (RefCount & 0x3FFFFF) != 0 )
          {
            v20 = v61.Obj.pObject;
            v61.Obj.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
          }
        }
      }
      ++v15.VInt;
      ++v14;
      if ( v15.VInt >= 0x100u )
      {
        v21 = ID->pTraits.pObject;
        v65.Flags = 3;
        v65.Bonus.pWeakProxy = 0;
        v65.value.VS._1 = v52;
        Scaleform::GFx::AS3::Multiname::Multiname(&v60, v21->pVM->PublicNamespace.pObject, &v65);
        if ( (v65.Flags & 0x1F) > 9 )
        {
          if ( (v65.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v65);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v65);
        }
        v22 = result->pObject;
        v46 = pobj->pObject;
        v64.Flags = 0;
        v64.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v64, v46);
        v23 = !v22->SetProperty(v22, (Scaleform::GFx::AS3::CheckResult *)&v53, &v60, &v64)->Result;
        if ( (v64.Flags & 0x1F) > 9 )
        {
          if ( (v64.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v64);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
        }
        if ( v23 )
        {
          if ( (v60.Name.Flags & 0x1F) > 9 )
          {
            if ( (v60.Name.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v60.Name);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v60.Name);
          }
          if ( v60.Obj.pObject )
          {
            if ( ((int)v60.Obj.pObject & 1) != 0 )
            {
              --v60.Obj.pObject;
            }
            else
            {
              v38 = v60.Obj.pObject->RefCount;
              if ( (v38 & 0x3FFFFF) != 0 )
              {
                v39 = v60.Obj.pObject;
                v60.Obj.pObject->RefCount = v38 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v39);
              }
            }
          }
          if ( (v51.Flags & 0x1F) > 9 )
          {
            if ( (v51.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
          }
          v40 = colors;
          for ( i = 3; i >= 0; --i )
          {
            v42 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v40;
            if ( v42 )
            {
              if ( ((unsigned __int8)v42 & 1) != 0 )
              {
                *v40 = (unsigned int)&v42[-1].RefCount + 3;
              }
              else
              {
                v43 = v42->RefCount;
                if ( (v43 & 0x3FFFFF) != 0 )
                {
                  v42->RefCount = v43 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v42);
                }
              }
            }
          }
          if ( (v.Flags & 0x1F) <= 9 )
            goto LABEL_127;
          if ( (v.Flags & 0x200) == 0 )
            goto LABEL_126;
        }
        else
        {
          if ( (v60.Name.Flags & 0x1F) > 9 )
          {
            if ( (v60.Name.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v60.Name);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v60.Name);
          }
          if ( v60.Obj.pObject )
          {
            if ( ((int)v60.Obj.pObject & 1) != 0 )
            {
              --v60.Obj.pObject;
            }
            else
            {
              v24 = v60.Obj.pObject->RefCount;
              v25 = v60.Obj.pObject;
              if ( (v24 & 0x3FFFFF) != 0 )
              {
                v60.Obj.pObject->RefCount = v24 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
              }
            }
          }
          if ( (v51.Flags & 0x1F) > 9 )
          {
            if ( (v51.Flags & 0x200) != 0 )
              Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
            else
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
          }
          v55.ID += 1024;
          ++pobj;
          if ( ++v52.VInt < 4u )
            goto LABEL_13;
          v26 = colors;
          for ( j = 3; j >= 0; --j )
          {
            v28 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v26;
            if ( v28 )
            {
              if ( ((unsigned __int8)v28 & 1) != 0 )
              {
                *v26 = (unsigned int)&v28[-1].RefCount + 3;
              }
              else
              {
                v44 = v28->RefCount;
                if ( (v44 & 0x3FFFFF) != 0 )
                {
                  v28->RefCount = v44 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v28);
                }
              }
            }
          }
          if ( (v.Flags & 0x1F) <= 9 )
            goto LABEL_127;
          if ( (v.Flags & 0x200) == 0 )
            goto LABEL_126;
        }
        goto LABEL_125;
      }
    }
    if ( (v61.Name.Flags & 0x1F) > 9 )
    {
      if ( (v61.Name.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v61.Name);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v61.Name);
    }
    if ( v61.Obj.pObject )
    {
      if ( ((int)v61.Obj.pObject & 1) != 0 )
      {
        --v61.Obj.pObject;
      }
      else
      {
        v32 = v61.Obj.pObject->RefCount;
        if ( (v32 & 0x3FFFFF) != 0 )
        {
          v33 = v61.Obj.pObject;
          v61.Obj.pObject->RefCount = v32 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v33);
        }
      }
    }
    if ( (v51.Flags & 0x1F) > 9 )
    {
      if ( (v51.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
    }
    v34 = colors;
    for ( k = 3; k >= 0; --k )
    {
      v36 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v34;
      if ( v36 )
      {
        if ( ((unsigned __int8)v36 & 1) != 0 )
        {
          *v34 = (unsigned int)&v36[-1].RefCount + 3;
        }
        else
        {
          v37 = v36->RefCount;
          if ( (v37 & 0x3FFFFF) != 0 )
          {
            v36->RefCount = v37 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v36);
          }
        }
      }
    }
    if ( (v.Flags & 0x1F) <= 9 )
      goto LABEL_127;
    if ( (v.Flags & 0x200) == 0 )
      goto LABEL_126;
LABEL_125:
    Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
    goto LABEL_127;
  }
  if ( (v51.Flags & 0x1F) > 9 )
  {
    if ( (v51.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v51);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v51);
  }
  v29 = colors;
  do
  {
    v30 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v29;
    if ( v30 )
    {
      if ( ((unsigned __int8)v30 & 1) != 0 )
      {
        *v29 = (unsigned int)&v30[-1].RefCount + 3;
      }
      else
      {
        v31 = v30->RefCount;
        if ( (v31 & 0x3FFFFF) != 0 )
        {
          v30->RefCount = v31 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
        }
      }
    }
    --v13;
  }
  while ( v13 >= 0 );
  if ( (v.Flags & 0x1F) <= 9 )
    goto LABEL_127;
  if ( (v.Flags & 0x200) != 0 )
    goto LABEL_125;
LABEL_126:
  Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
LABEL_127:
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&argv);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
  }
}
