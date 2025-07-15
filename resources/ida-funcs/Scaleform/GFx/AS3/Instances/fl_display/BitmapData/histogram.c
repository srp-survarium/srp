void __thiscall Scaleform::GFx::AS3::Instances::fl_display::BitmapData::histogram(
        Scaleform::GFx::AS3::Instances::fl_display::BitmapData *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *result,
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *hRect)
{
  Scaleform::GFx::AS3::Instances::fl_display::BitmapData *ID; // ebp
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::Render::Rect<long> *p_x; // edi
  int y; // ebp
  int v9; // eax
  long double v10; // st7
  Scaleform::Render::DrawableImage *DrawableImageFromBitmapData; // eax
  Scaleform::GFx::AS3::Traits *pObject; // edx
  Scaleform::GFx::AS3::Traits *v13; // ecx
  int v14; // edi
  Scaleform::GFx::AS3::Value::V1U *v15; // edi
  Scaleform::GFx::AS3::Value::V1U v16; // esi
  Scaleform::GFx::AS3::Traits *v17; // eax
  Scaleform::GFx::AS3::Object *v18; // ecx
  bool v19; // bl
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v21; // ecx
  Scaleform::GFx::AS3::Traits *v22; // edx
  Scaleform::GFx::AS3::Instances::fl::Object *v23; // esi
  bool v24; // bl
  unsigned int v25; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v26; // ecx
  unsigned int *v27; // esi
  int j; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v29; // ecx
  unsigned int *v30; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v34; // ecx
  unsigned int *v35; // esi
  int k; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v37; // ecx
  unsigned int v38; // eax
  unsigned int v39; // edx
  Scaleform::GFx::AS3::GASRefCountBase *v40; // ecx
  unsigned int *v41; // esi
  int i; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v43; // ecx
  unsigned int v44; // eax
  unsigned int v45; // eax
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
  char __t[16]; // [esp+DCh] [ebp-1010h] BYREF
  unsigned int colors[256]; // [esp+ECh] [ebp-1000h] BYREF

  ID = this;
  v55.ID = (Scaleform::GFx::AS3::VM::ErrorID)this;
  if ( !this->pImage.pObject )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v55, eArgumentError, pVM);
    Scaleform::GFx::AS3::VM::ThrowArgumentError(pVM, v5);
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
    v9 = (int)(hRect->width + hRect->x);
    v10 = hRect->height + hRect->y;
    x = (int)hRect->x;
    v57 = y;
    v58 = v9;
    ID = (Scaleform::GFx::AS3::Instances::fl_display::BitmapData *)v55.ID;
    v59 = (int)v10;
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
    __t,
    4u,
    4,
    (void *(__thiscall *)(void *))Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_double>::`default constructor closure');
  v52.VInt = 0;
  pobj = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)__t;
  v55.ID = (Scaleform::GFx::AS3::VM::ErrorID)colors;
LABEL_13:
  v13 = ID->pTraits.pObject;
  v14 = 3;
  v51.Flags = 3;
  v51.Bonus.pWeakProxy = 0;
  v51.value.VS._1.VInt = 256;
  Scaleform::GFx::AS3::VM::constructBuiltinObject(v13->pVM, &resulta, pobj, "Vector.<Number>", 1u, &v51);
  if ( resulta.Result )
  {
    v15 = (Scaleform::GFx::AS3::Value::V1U *)v55.ID;
    v16.VInt = 0;
    while ( 1 )
    {
      v17 = ID->pTraits.pObject;
      name.Flags = 3;
      name.Bonus.pWeakProxy = 0;
      name.value.VS._1 = v16;
      Scaleform::GFx::AS3::Multiname::Multiname(&v61, v17->pVM->PublicNamespace.pObject, &name);
      if ( (name.Flags & 0x1F) > 9 )
      {
        if ( (name.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&name);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&name);
      }
      v18 = pobj->pObject;
      v62.value.VS._1 = *v15;
      v62.Flags = 3;
      v62.Bonus.pWeakProxy = 0;
      v19 = !v18->SetProperty(v18, (Scaleform::GFx::AS3::CheckResult *)&v54, &v61, &v62)->Result;
      if ( (v62.Flags & 0x1F) > 9 )
      {
        if ( (v62.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v62);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v62);
      }
      if ( v19 )
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
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v21 = v61.Obj.pObject;
            v61.Obj.pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
          }
        }
      }
      ++v16.VInt;
      ++v15;
      if ( v16.VInt >= 0x100u )
      {
        v22 = ID->pTraits.pObject;
        v65.Flags = 3;
        v65.Bonus.pWeakProxy = 0;
        v65.value.VS._1 = v52;
        Scaleform::GFx::AS3::Multiname::Multiname(&v60, v22->pVM->PublicNamespace.pObject, &v65);
        if ( (v65.Flags & 0x1F) > 9 )
        {
          if ( (v65.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v65);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v65);
        }
        v23 = result->pObject;
        v46 = pobj->pObject;
        v64.Flags = 0;
        v64.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v64, v46);
        v24 = !v23->SetProperty(v23, (Scaleform::GFx::AS3::CheckResult *)&v53, &v60, &v64)->Result;
        if ( (v64.Flags & 0x1F) > 9 )
        {
          if ( (v64.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v64);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v64);
        }
        if ( v24 )
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
              v39 = v60.Obj.pObject->RefCount;
              if ( ((unsigned int)&byte_3FFFFF & v39) != 0 )
              {
                v40 = v60.Obj.pObject;
                v60.Obj.pObject->RefCount = v39 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v40);
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
          v41 = colors;
          for ( i = 3; i >= 0; --i )
          {
            v43 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v41;
            if ( v43 )
            {
              if ( ((unsigned __int8)v43 & 1) != 0 )
              {
                *v41 = (unsigned int)&v43[-1].RefCount + 3;
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
              v25 = v60.Obj.pObject->RefCount;
              v26 = v60.Obj.pObject;
              if ( ((unsigned int)&byte_3FFFFF & v25) != 0 )
              {
                v60.Obj.pObject->RefCount = v25 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
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
          v27 = colors;
          for ( j = 3; j >= 0; --j )
          {
            v29 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v27;
            if ( v29 )
            {
              if ( ((unsigned __int8)v29 & 1) != 0 )
              {
                *v27 = (unsigned int)&v29[-1].RefCount + 3;
              }
              else
              {
                v45 = v29->RefCount;
                if ( ((unsigned int)&byte_3FFFFF & v45) != 0 )
                {
                  v29->RefCount = v45 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
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
        v33 = v61.Obj.pObject->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v33) != 0 )
        {
          v34 = v61.Obj.pObject;
          v61.Obj.pObject->RefCount = v33 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v34);
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
    v35 = colors;
    for ( k = 3; k >= 0; --k )
    {
      v37 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v35;
      if ( v37 )
      {
        if ( ((unsigned __int8)v37 & 1) != 0 )
        {
          *v35 = (unsigned int)&v37[-1].RefCount + 3;
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
  v30 = colors;
  do
  {
    v31 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*--v30;
    if ( v31 )
    {
      if ( ((unsigned __int8)v31 & 1) != 0 )
      {
        *v30 = (unsigned int)&v31[-1].RefCount + 3;
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
    --v14;
  }
  while ( v14 >= 0 );
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
