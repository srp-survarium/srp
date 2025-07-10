void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::Matrix::toString(
        Scaleform::GFx::AS3::Instances::fl_geom::Matrix *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // edi
  Scaleform::GFx::AS3::Traits *v5; // edx
  Scaleform::GFx::AS3::VM *v6; // ebp
  Scaleform::GFx::AS3::Traits *v7; // ecx
  Scaleform::GFx::AS3::VM *v8; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::AS3::Traits *v10; // eax
  Scaleform::GFx::AS3::VM *v11; // eax
  Scaleform::GFx::ASStringManager *v12; // ecx
  Scaleform::GFx::AS3::Traits *v13; // edx
  Scaleform::GFx::AS3::Traits *v14; // ecx
  Scaleform::GFx::AS3::VM *v15; // esi
  const Scaleform::GFx::ASString *v16; // eax
  Scaleform::GFx::ASString *v17; // eax
  Scaleform::GFx::ASString *v18; // eax
  Scaleform::GFx::ASString *v19; // eax
  Scaleform::GFx::ASString *v20; // eax
  Scaleform::GFx::ASString *v21; // eax
  Scaleform::GFx::ASString *v22; // eax
  Scaleform::GFx::ASString *v23; // eax
  Scaleform::GFx::ASString *v24; // eax
  Scaleform::GFx::ASString *v25; // eax
  Scaleform::GFx::ASString *v26; // eax
  Scaleform::GFx::ASString *v27; // eax
  Scaleform::GFx::ASString *v28; // eax
  Scaleform::GFx::ASString *v29; // eax
  Scaleform::GFx::ASString *v30; // eax
  Scaleform::GFx::ASString *v31; // eax
  Scaleform::GFx::ASString *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
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
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // eax
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::GFx::ASStringNode *v49; // eax
  Scaleform::GFx::ASStringNode *v50; // eax
  Scaleform::GFx::ASStringNode *v51; // eax
  Scaleform::GFx::ASStringNode *v52; // eax
  Scaleform::GFx::ASStringNode *v53; // eax
  Scaleform::GFx::ASStringNode *v54; // eax
  Scaleform::GFx::ASStringNode *v55; // eax
  Scaleform::GFx::ASStringNode *v56; // eax
  Scaleform::GFx::ASStringNode *v57; // eax
  Scaleform::GFx::ASStringNode *v58; // eax
  Scaleform::GFx::ASStringNode *v59; // eax
  Scaleform::GFx::ASStringNode *v60; // eax
  Scaleform::GFx::ASStringNode *v61; // eax
  Scaleform::GFx::ASStringNode *v62; // eax
  Scaleform::GFx::ASStringNode *v63; // eax
  Scaleform::GFx::ASStringNode *v64; // eax
  Scaleform::GFx::ASStringNode *v65; // eax
  Scaleform::GFx::ASStringNode *v66; // eax
  Scaleform::GFx::ASStringNode *v67; // eax
  Scaleform::GFx::ASStringNode *v68; // eax
  const Scaleform::GFx::ASString *v69; // [esp-6Ch] [ebp-174h]
  const Scaleform::GFx::ASString *v70; // [esp-54h] [ebp-15Ch]
  const Scaleform::GFx::ASString *v71; // [esp-3Ch] [ebp-144h]
  const Scaleform::GFx::ASString *v72; // [esp-24h] [ebp-12Ch]
  const Scaleform::GFx::ASString *v73; // [esp-Ch] [ebp-114h]
  Scaleform::GFx::ASString v74; // [esp+10h] [ebp-F8h] BYREF
  Scaleform::GFx::ASString v75; // [esp+14h] [ebp-F4h] BYREF
  Scaleform::GFx::ASString str; // [esp+18h] [ebp-F0h] BYREF
  Scaleform::GFx::ASString v77; // [esp+1Ch] [ebp-ECh] BYREF
  Scaleform::GFx::ASString v78; // [esp+20h] [ebp-E8h] BYREF
  Scaleform::GFx::ASString v79; // [esp+24h] [ebp-E4h] BYREF
  Scaleform::GFx::ASString v80; // [esp+28h] [ebp-E0h] BYREF
  Scaleform::GFx::ASString v81; // [esp+2Ch] [ebp-DCh] BYREF
  Scaleform::GFx::ASString v82; // [esp+30h] [ebp-D8h] BYREF
  Scaleform::GFx::ASString v83; // [esp+34h] [ebp-D4h] BYREF
  Scaleform::GFx::ASString v84; // [esp+38h] [ebp-D0h] BYREF
  Scaleform::GFx::ASString v85; // [esp+3Ch] [ebp-CCh] BYREF
  Scaleform::GFx::ASString v86; // [esp+40h] [ebp-C8h] BYREF
  Scaleform::GFx::ASString v87; // [esp+44h] [ebp-C4h] BYREF
  Scaleform::GFx::AS3::VM *v88; // [esp+48h] [ebp-C0h]
  Scaleform::GFx::ASString v89; // [esp+4Ch] [ebp-BCh] BYREF
  Scaleform::GFx::ASString v90; // [esp+50h] [ebp-B8h] BYREF
  Scaleform::GFx::ASString v91; // [esp+54h] [ebp-B4h] BYREF
  Scaleform::GFx::ASString v92; // [esp+58h] [ebp-B0h] BYREF
  Scaleform::GFx::ASString v93; // [esp+5Ch] [ebp-ACh] BYREF
  Scaleform::GFx::ASString v94; // [esp+60h] [ebp-A8h] BYREF
  Scaleform::GFx::ASString v95; // [esp+64h] [ebp-A4h] BYREF
  Scaleform::GFx::AS3::VM *v96; // [esp+68h] [ebp-A0h]
  Scaleform::GFx::ASString v97; // [esp+6Ch] [ebp-9Ch] BYREF
  Scaleform::GFx::ASString v98; // [esp+70h] [ebp-98h] BYREF
  Scaleform::GFx::ASString v99; // [esp+74h] [ebp-94h] BYREF
  Scaleform::GFx::ASString v100; // [esp+78h] [ebp-90h] BYREF
  Scaleform::GFx::ASString v101; // [esp+7Ch] [ebp-8Ch] BYREF
  Scaleform::GFx::ASString v102; // [esp+80h] [ebp-88h] BYREF
  Scaleform::GFx::ASString v103; // [esp+84h] [ebp-84h] BYREF
  Scaleform::GFx::ASString v104; // [esp+88h] [ebp-80h] BYREF
  Scaleform::GFx::ASString v105; // [esp+8Ch] [ebp-7Ch] BYREF
  Scaleform::GFx::ASString v106; // [esp+90h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::VM *v107; // [esp+94h] [ebp-74h]
  Scaleform::GFx::ASString v108; // [esp+98h] [ebp-70h] BYREF
  Scaleform::GFx::ASString v109; // [esp+9Ch] [ebp-6Ch] BYREF
  Scaleform::GFx::ASString v110; // [esp+A0h] [ebp-68h] BYREF
  Scaleform::GFx::ASString v111; // [esp+A4h] [ebp-64h] BYREF
  Scaleform::GFx::AS3::Value v112; // [esp+A8h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value v113; // [esp+B8h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value v114; // [esp+C8h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v115; // [esp+D8h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v116; // [esp+E8h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+F8h] [ebp-10h] BYREF

  v85.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                ")",
                1u,
                0);
  ++v85.pNode->RefCount;
  pObject = this->pTraits.pObject;
  value.value.VNumber = this->ty;
  value.Flags = 4;
  value.Bonus.pWeakProxy = 0;
  pVM = pObject->pVM;
  v83.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                pVM->StringManagerRef->pStringManager,
                "ty=",
                3u,
                0);
  ++v83.pNode->RefCount;
  v81.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++v81.pNode->RefCount;
  v5 = this->pTraits.pObject;
  v115.value.VNumber = this->tx;
  v115.Flags = 4;
  v115.Bonus.pWeakProxy = 0;
  v6 = v5->pVM;
  v79.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v6->StringManagerRef->pStringManager, "tx=", 3u, 0);
  ++v79.pNode->RefCount;
  v77.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++v77.pNode->RefCount;
  v7 = this->pTraits.pObject;
  v113.value.VNumber = this->d;
  v113.Flags = 4;
  v113.Bonus.pWeakProxy = 0;
  v8 = v7->pVM;
  pStringManager = v8->StringManagerRef->pStringManager;
  v96 = v8;
  v75.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "d=", 2u, 0);
  ++v75.pNode->RefCount;
  v74.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++v74.pNode->RefCount;
  v10 = this->pTraits.pObject;
  v116.value.VNumber = this->c;
  v116.Flags = 4;
  v116.Bonus.pWeakProxy = 0;
  v11 = v10->pVM;
  v12 = v11->StringManagerRef->pStringManager;
  v88 = v11;
  v82.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v12, "c=", 2u, 0);
  ++v82.pNode->RefCount;
  v78.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++v78.pNode->RefCount;
  v13 = this->pTraits.pObject;
  v114.value.VNumber = this->b;
  v114.Flags = 4;
  v114.Bonus.pWeakProxy = 0;
  v107 = v13->pVM;
  v84.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                v107->StringManagerRef->pStringManager,
                "b=",
                2u,
                0);
  ++v84.pNode->RefCount;
  str.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++str.pNode->RefCount;
  v14 = this->pTraits.pObject;
  v112.value.VNumber = this->a;
  v112.Flags = 4;
  v112.Bonus.pWeakProxy = 0;
  v15 = v14->pVM;
  v80.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                v15->StringManagerRef->pStringManager,
                "(a=",
                3u,
                0);
  ++v80.pNode->RefCount;
  v73 = Scaleform::GFx::AS3::VM::AsString(pVM, &v105, &value);
  v72 = Scaleform::GFx::AS3::VM::AsString(v6, &v103, &v115);
  v71 = Scaleform::GFx::AS3::VM::AsString(v96, &v101, &v113);
  v70 = Scaleform::GFx::AS3::VM::AsString(v88, &v99, &v116);
  v69 = Scaleform::GFx::AS3::VM::AsString(v107, &v97, &v114);
  v16 = Scaleform::GFx::AS3::VM::AsString(v15, &v95, &v112);
  v17 = Scaleform::GFx::ASString::operator+(&v80, &v93, v16);
  v18 = Scaleform::GFx::ASString::operator+(v17, &v91, &str);
  v19 = Scaleform::GFx::ASString::operator+(v18, &v89, &v84);
  v20 = Scaleform::GFx::ASString::operator+(v19, &v87, v69);
  v21 = Scaleform::GFx::ASString::operator+(v20, &v102, &v78);
  v22 = Scaleform::GFx::ASString::operator+(v21, &v110, &v82);
  v23 = Scaleform::GFx::ASString::operator+(v22, &v100, v70);
  v24 = Scaleform::GFx::ASString::operator+(v23, &v108, &v74);
  v25 = Scaleform::GFx::ASString::operator+(v24, &v98, &v75);
  v26 = Scaleform::GFx::ASString::operator+(v25, &v111, v71);
  v27 = Scaleform::GFx::ASString::operator+(v26, &v86, &v77);
  v28 = Scaleform::GFx::ASString::operator+(v27, &v106, &v79);
  v29 = Scaleform::GFx::ASString::operator+(v28, &v94, v72);
  v30 = Scaleform::GFx::ASString::operator+(v29, &v109, &v81);
  v31 = Scaleform::GFx::ASString::operator+(v30, &v92, &v83);
  v32 = Scaleform::GFx::ASString::operator+(v31, &v104, v73);
  v33 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::ASString::operator+(v32, &v90, &v85);
  Scaleform::GFx::ASString::Append(result, v33);
  pNode = v90.pNode;
  --v90.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v35 = v104.pNode;
  --v104.pNode->RefCount;
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  v36 = v92.pNode;
  --v92.pNode->RefCount;
  if ( !v36->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  v37 = v109.pNode;
  --v109.pNode->RefCount;
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  v38 = v94.pNode;
  --v94.pNode->RefCount;
  if ( !v38->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
  v39 = v106.pNode;
  --v106.pNode->RefCount;
  if ( !v39->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  v40 = v86.pNode;
  --v86.pNode->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  v41 = v111.pNode;
  --v111.pNode->RefCount;
  if ( !v41->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  v42 = v98.pNode;
  --v98.pNode->RefCount;
  if ( !v42->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  v43 = v108.pNode;
  --v108.pNode->RefCount;
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  v44 = v100.pNode;
  --v100.pNode->RefCount;
  if ( !v44->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  v45 = v110.pNode;
  --v110.pNode->RefCount;
  if ( !v45->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  v46 = v102.pNode;
  --v102.pNode->RefCount;
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  v47 = v87.pNode;
  --v87.pNode->RefCount;
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = v89.pNode;
  --v89.pNode->RefCount;
  if ( !v48->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  v49 = v91.pNode;
  --v91.pNode->RefCount;
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  v50 = v93.pNode;
  --v93.pNode->RefCount;
  if ( !v50->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  v51 = v80.pNode;
  --v80.pNode->RefCount;
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  v52 = v95.pNode;
  --v95.pNode->RefCount;
  if ( !v52->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
  if ( (v112.Flags & 0x1F) > 9 )
  {
    if ( (v112.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v112);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v112);
  }
  v53 = str.pNode;
  --str.pNode->RefCount;
  if ( !v53->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  v54 = v84.pNode;
  --v84.pNode->RefCount;
  if ( !v54->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  v55 = v97.pNode;
  --v97.pNode->RefCount;
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  if ( (v114.Flags & 0x1F) > 9 )
  {
    if ( (v114.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v114);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v114);
  }
  v56 = v78.pNode;
  --v78.pNode->RefCount;
  if ( !v56->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v56);
  v57 = v82.pNode;
  --v82.pNode->RefCount;
  if ( !v57->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  v58 = v99.pNode;
  --v99.pNode->RefCount;
  if ( !v58->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v58);
  if ( (v116.Flags & 0x1F) > 9 )
  {
    if ( (v116.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v116);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v116);
  }
  v59 = v74.pNode;
  --v74.pNode->RefCount;
  if ( !v59->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  v60 = v75.pNode;
  --v75.pNode->RefCount;
  if ( !v60->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  v61 = v101.pNode;
  --v101.pNode->RefCount;
  if ( !v61->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
  if ( (v113.Flags & 0x1F) > 9 )
  {
    if ( (v113.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v113);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v113);
  }
  v62 = v77.pNode;
  --v77.pNode->RefCount;
  if ( !v62->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v62);
  v63 = v79.pNode;
  --v79.pNode->RefCount;
  if ( !v63->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  v64 = v103.pNode;
  --v103.pNode->RefCount;
  if ( !v64->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  if ( (v115.Flags & 0x1F) > 9 )
  {
    if ( (v115.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v115);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v115);
  }
  v65 = v81.pNode;
  --v81.pNode->RefCount;
  if ( !v65->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v65);
  v66 = v83.pNode;
  --v83.pNode->RefCount;
  if ( !v66->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  v67 = v105.pNode;
  --v105.pNode->RefCount;
  if ( !v67->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v67);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
  }
  v68 = v85.pNode;
  --v85.pNode->RefCount;
  if ( !v68->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v68);
}
