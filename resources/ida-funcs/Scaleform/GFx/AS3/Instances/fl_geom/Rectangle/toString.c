void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Rectangle::toString(
        Scaleform::GFx::AS3::Instances::fl_geom::Rectangle *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::Traits *v5; // edx
  Scaleform::GFx::AS3::VM *v6; // ebp
  Scaleform::GFx::AS3::Traits *v7; // ecx
  Scaleform::GFx::AS3::VM *v8; // ebx
  Scaleform::GFx::AS3::Traits *v9; // eax
  Scaleform::GFx::AS3::VM *v10; // esi
  const Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::ASString *v12; // eax
  Scaleform::GFx::ASString *v13; // eax
  Scaleform::GFx::ASString *v14; // eax
  Scaleform::GFx::ASString *v15; // eax
  Scaleform::GFx::ASString *v16; // eax
  Scaleform::GFx::ASString *v17; // eax
  Scaleform::GFx::ASString *v18; // eax
  Scaleform::GFx::ASString *v19; // eax
  Scaleform::GFx::ASString *v20; // eax
  Scaleform::GFx::ASString *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  Scaleform::GFx::ASStringNode *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // eax
  Scaleform::GFx::ASStringNode *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::ASStringNode *v41; // eax
  Scaleform::GFx::ASStringNode *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::GFx::ASStringNode *v44; // eax
  Scaleform::GFx::ASStringNode *v45; // eax
  const Scaleform::GFx::ASString *v46; // [esp-3Ch] [ebp-E8h]
  const Scaleform::GFx::ASString *v47; // [esp-24h] [ebp-D0h]
  const Scaleform::GFx::ASString *v48; // [esp-Ch] [ebp-B8h]
  Scaleform::GFx::ASString v49; // [esp+10h] [ebp-9Ch] BYREF
  Scaleform::GFx::ASString v50; // [esp+14h] [ebp-98h] BYREF
  Scaleform::GFx::ASString str; // [esp+18h] [ebp-94h] BYREF
  Scaleform::GFx::ASString v52; // [esp+1Ch] [ebp-90h] BYREF
  Scaleform::GFx::ASString v53; // [esp+20h] [ebp-8Ch] BYREF
  Scaleform::GFx::ASString v54; // [esp+24h] [ebp-88h] BYREF
  Scaleform::GFx::ASString v55; // [esp+28h] [ebp-84h] BYREF
  Scaleform::GFx::ASString v56; // [esp+2Ch] [ebp-80h] BYREF
  Scaleform::GFx::ASString v57; // [esp+30h] [ebp-7Ch] BYREF
  Scaleform::GFx::ASString v58; // [esp+34h] [ebp-78h] BYREF
  Scaleform::GFx::ASString v59; // [esp+38h] [ebp-74h] BYREF
  Scaleform::GFx::ASString v60; // [esp+3Ch] [ebp-70h] BYREF
  Scaleform::GFx::ASString v61; // [esp+40h] [ebp-6Ch] BYREF
  Scaleform::GFx::ASString v62; // [esp+44h] [ebp-68h] BYREF
  Scaleform::GFx::ASString v63; // [esp+48h] [ebp-64h] BYREF
  Scaleform::GFx::ASString v64; // [esp+4Ch] [ebp-60h] BYREF
  Scaleform::GFx::ASString v65; // [esp+50h] [ebp-5Ch] BYREF
  Scaleform::GFx::ASString v66; // [esp+54h] [ebp-58h] BYREF
  Scaleform::GFx::ASString v67; // [esp+58h] [ebp-54h] BYREF
  Scaleform::GFx::ASString v68; // [esp+5Ch] [ebp-50h] BYREF
  Scaleform::GFx::ASString v69; // [esp+60h] [ebp-4Ch] BYREF
  Scaleform::GFx::ASString v70; // [esp+64h] [ebp-48h] BYREF
  Scaleform::GFx::ASString v71; // [esp+68h] [ebp-44h] BYREF
  Scaleform::GFx::AS3::Value v72; // [esp+6Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v73; // [esp+7Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v74; // [esp+8Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+9Ch] [ebp-10h] BYREF

  v56.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                ")",
                1u,
                0);
  ++v56.pNode->RefCount;
  pObject = this->pTraits.pObject;
  value.value.VNumber = this->height;
  value.Flags = 4;
  value.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v54.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pVM->StringManagerRef->pStringManager, "h=", 2u, 0);
  ++v54.pNode->RefCount;
  v52.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                ", ",
                2u,
                0);
  ++v52.pNode->RefCount;
  v5 = this->pTraits.pObject;
  v73.value.VNumber = this->width;
  v73.Flags = 4;
  v73.Bonus.pWeakProxy = 0;
  v6 = v5->pVM;
  v50.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v6->StringManagerRef->pStringManager, "w=", 2u, 0);
  ++v50.pNode->RefCount;
  v49.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                ", ",
                2u,
                0);
  ++v49.pNode->RefCount;
  v7 = this->pTraits.pObject;
  v74.value.VNumber = this->y;
  v74.Flags = 4;
  v74.Bonus.pWeakProxy = 0;
  v8 = v7->pVM;
  v55.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v8->StringManagerRef->pStringManager, "y=", 2u, 0);
  ++v55.pNode->RefCount;
  str.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                ", ",
                2u,
                0);
  ++str.pNode->RefCount;
  v9 = this->pTraits.pObject;
  v72.value.VNumber = this->x;
  v72.Flags = 4;
  v72.Bonus.pWeakProxy = 0;
  v10 = v9->pVM;
  v53.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                v10->StringManagerRef->pStringManager,
                "(x=",
                3u,
                0);
  ++v53.pNode->RefCount;
  v48 = Scaleform::GFx::AS3::VM::AsString(pVM, &v67, &value);
  v47 = Scaleform::GFx::AS3::VM::AsString(v6, &v65, &v73);
  v46 = Scaleform::GFx::AS3::VM::AsString(v8, &v63, &v74);
  v11 = Scaleform::GFx::AS3::VM::AsString(v10, &v61, &v72);
  v12 = Scaleform::GFx::ASString::operator+(&v53, &v59, v11);
  v13 = Scaleform::GFx::ASString::operator+(v12, &v58, &str);
  v14 = Scaleform::GFx::ASString::operator+(v13, &v66, &v55);
  v15 = Scaleform::GFx::ASString::operator+(v14, &v70, v46);
  v16 = Scaleform::GFx::ASString::operator+(v15, &v64, &v49);
  v17 = Scaleform::GFx::ASString::operator+(v16, &v57, &v50);
  v18 = Scaleform::GFx::ASString::operator+(v17, &v62, v47);
  v19 = Scaleform::GFx::ASString::operator+(v18, &v68, &v52);
  v20 = Scaleform::GFx::ASString::operator+(v19, &v60, &v54);
  v21 = Scaleform::GFx::ASString::operator+(v20, &v69, v48);
  v22 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::ASString::operator+(v21, &v71, &v56);
  Scaleform::GFx::ASString::Append(result, v22);
  pNode = v71.pNode;
  --v71.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v24 = v69.pNode;
  --v69.pNode->RefCount;
  if ( !v24->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  v25 = v60.pNode;
  --v60.pNode->RefCount;
  if ( !v25->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  v26 = v68.pNode;
  --v68.pNode->RefCount;
  if ( !v26->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  v27 = v62.pNode;
  --v62.pNode->RefCount;
  if ( !v27->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  v28 = v57.pNode;
  --v57.pNode->RefCount;
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  v29 = v64.pNode;
  --v64.pNode->RefCount;
  if ( !v29->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  v30 = v70.pNode;
  --v70.pNode->RefCount;
  if ( !v30->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  v31 = v66.pNode;
  --v66.pNode->RefCount;
  if ( !v31->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  v32 = v58.pNode;
  --v58.pNode->RefCount;
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  v33 = v59.pNode;
  --v59.pNode->RefCount;
  if ( !v33->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  v34 = v53.pNode;
  --v53.pNode->RefCount;
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  v35 = v61.pNode;
  --v61.pNode->RefCount;
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( (v72.Flags & 0x1F) > 9 )
  {
    if ( (v72.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v72);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v72);
  }
  v36 = str.pNode;
  --str.pNode->RefCount;
  if ( !v36->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  v37 = v55.pNode;
  --v55.pNode->RefCount;
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  v38 = v63.pNode;
  --v63.pNode->RefCount;
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  if ( (v74.Flags & 0x1F) > 9 )
  {
    if ( (v74.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v74);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v74);
  }
  v39 = v49.pNode;
  --v49.pNode->RefCount;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  v40 = v50.pNode;
  --v50.pNode->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  v41 = v65.pNode;
  --v65.pNode->RefCount;
  if ( !v41->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( (v73.Flags & 0x1F) > 9 )
  {
    if ( (v73.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v73);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v73);
  }
  v42 = v52.pNode;
  --v52.pNode->RefCount;
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  v43 = v54.pNode;
  --v54.pNode->RefCount;
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  v44 = v67.pNode;
  --v67.pNode->RefCount;
  if ( !v44->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
  }
  v45 = v56.pNode;
  --v56.pNode->RefCount;
  if ( !v45->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
}
