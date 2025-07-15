void __thiscall Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::blendModeGet(
        Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v3; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString *v5; // eax
  Scaleform::GFx::ASString *v6; // eax
  Scaleform::GFx::ASString *v7; // eax
  Scaleform::GFx::ASString *v8; // eax
  Scaleform::GFx::ASString *v9; // eax
  Scaleform::GFx::ASString *v10; // eax
  Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::ASString *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASString *v14; // eax
  Scaleform::GFx::ASString *v15; // eax
  Scaleform::GFx::ASString *v16; // eax
  Scaleform::GFx::ASString *v17; // eax
  Scaleform::GFx::ASString v18; // [esp+4h] [ebp-38h] BYREF
  Scaleform::GFx::ASString v19; // [esp+8h] [ebp-34h] BYREF
  Scaleform::GFx::ASString v20; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::ASString v21; // [esp+10h] [ebp-2Ch] BYREF
  Scaleform::GFx::ASString v22; // [esp+14h] [ebp-28h] BYREF
  Scaleform::GFx::ASString v23; // [esp+18h] [ebp-24h] BYREF
  Scaleform::GFx::ASString v24; // [esp+1Ch] [ebp-20h] BYREF
  Scaleform::GFx::ASString v25; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::GFx::ASString v26; // [esp+24h] [ebp-18h] BYREF
  Scaleform::GFx::ASString v27; // [esp+28h] [ebp-14h] BYREF
  Scaleform::GFx::ASString v28; // [esp+2Ch] [ebp-10h] BYREF
  Scaleform::GFx::ASString v29; // [esp+30h] [ebp-Ch] BYREF
  Scaleform::GFx::ASString v30; // [esp+34h] [ebp-8h] BYREF
  Scaleform::GFx::ASString v31; // [esp+38h] [ebp-4h] BYREF

  switch ( this->pDispObj.pObject->GetBlendMode(this->pDispObj.pObject) )
  {
    case Blend_None:
    case Blend_Normal:
      v3 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v18,
             "normal");
      Scaleform::GFx::ASString::operator=(result, v3);
      pNode = v18.pNode;
      goto LABEL_16;
    case Blend_Layer:
      v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v19,
             "layer");
      Scaleform::GFx::ASString::operator=(result, v5);
      pNode = v19.pNode;
      goto LABEL_16;
    case Blend_Multiply:
      v6 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v20,
             "multiply");
      Scaleform::GFx::ASString::operator=(result, v6);
      pNode = v20.pNode;
      goto LABEL_16;
    case Blend_Screen:
      v7 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v21,
             "screen");
      Scaleform::GFx::ASString::operator=(result, v7);
      pNode = v21.pNode;
      goto LABEL_16;
    case Blend_Lighten:
      v8 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v22,
             "lighten");
      Scaleform::GFx::ASString::operator=(result, v8);
      pNode = v22.pNode;
      goto LABEL_16;
    case Blend_Darken:
      v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
             this->pTraits.pObject->pVM->StringManagerRef,
             &v23,
             "darken");
      Scaleform::GFx::ASString::operator=(result, v9);
      pNode = v23.pNode;
      goto LABEL_16;
    case Blend_Difference:
      v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v24,
              "difference");
      Scaleform::GFx::ASString::operator=(result, v10);
      pNode = v24.pNode;
      goto LABEL_16;
    case Blend_Add:
      v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v25,
              "add");
      Scaleform::GFx::ASString::operator=(result, v11);
      pNode = v25.pNode;
      goto LABEL_16;
    case Blend_Subtract:
      v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v26,
              "subtract");
      Scaleform::GFx::ASString::operator=(result, v12);
      pNode = v26.pNode;
      goto LABEL_16;
    case Blend_Invert:
      v13 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v27,
              "invert");
      Scaleform::GFx::ASString::operator=(result, v13);
      pNode = v27.pNode;
      goto LABEL_16;
    case Blend_Alpha:
      v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v28,
              "alpha");
      Scaleform::GFx::ASString::operator=(result, v14);
      pNode = v28.pNode;
      goto LABEL_16;
    case Blend_Erase:
      v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v29,
              "erase");
      Scaleform::GFx::ASString::operator=(result, v15);
      pNode = v29.pNode;
      goto LABEL_16;
    case Blend_Overlay:
      v16 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v30,
              "overlay");
      Scaleform::GFx::ASString::operator=(result, v16);
      pNode = v30.pNode;
      goto LABEL_16;
    case Blend_HardLight:
      v17 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
              this->pTraits.pObject->pVM->StringManagerRef,
              &v31,
              "hardlight");
      Scaleform::GFx::ASString::operator=(result, v17);
      pNode = v31.pNode;
LABEL_16:
      if ( !--pNode->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      break;
    default:
      return;
  }
}
