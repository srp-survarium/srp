void __thiscall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::toString(
        Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // eax
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::AS3::Traits *v6; // edx
  Scaleform::GFx::AS3::Traits *v7; // ecx
  Scaleform::GFx::AS3::VM *v8; // eax
  Scaleform::GFx::ASStringManager *v9; // ecx
  Scaleform::GFx::AS3::Traits *v10; // eax
  Scaleform::GFx::AS3::VM *v11; // eax
  Scaleform::GFx::ASStringManager *v12; // ecx
  Scaleform::GFx::AS3::Traits *v13; // edx
  Scaleform::GFx::AS3::Traits *v14; // ecx
  Scaleform::GFx::AS3::VM *v15; // eax
  Scaleform::GFx::ASStringManager *v16; // ecx
  Scaleform::GFx::AS3::Traits *v17; // eax
  Scaleform::GFx::AS3::VM *v18; // eax
  Scaleform::GFx::ASStringManager *v19; // ecx
  Scaleform::GFx::AS3::Traits *v20; // edx
  Scaleform::GFx::AS3::VM *v21; // esi
  const Scaleform::GFx::ASString *v22; // eax
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
  Scaleform::GFx::ASString *v33; // eax
  Scaleform::GFx::ASString *v34; // eax
  Scaleform::GFx::ASString *v35; // eax
  Scaleform::GFx::ASString *v36; // eax
  Scaleform::GFx::ASString *v37; // eax
  Scaleform::GFx::ASString *v38; // eax
  Scaleform::GFx::ASString *v39; // eax
  Scaleform::GFx::ASString *v40; // eax
  Scaleform::GFx::ASString *v41; // eax
  Scaleform::GFx::ASString *v42; // eax
  Scaleform::GFx::ASString *v43; // eax
  Scaleform::GFx::ASString *v44; // eax
  Scaleform::GFx::ASStringNode *v45; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
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
  Scaleform::GFx::ASStringNode *v69; // eax
  Scaleform::GFx::ASStringNode *v70; // eax
  Scaleform::GFx::ASStringNode *v71; // eax
  Scaleform::GFx::ASStringNode *v72; // eax
  Scaleform::GFx::ASStringNode *v73; // eax
  Scaleform::GFx::ASStringNode *v74; // eax
  Scaleform::GFx::ASStringNode *v75; // eax
  Scaleform::GFx::ASStringNode *v76; // eax
  Scaleform::GFx::ASStringNode *v77; // eax
  Scaleform::GFx::ASStringNode *v78; // eax
  Scaleform::GFx::ASStringNode *v79; // eax
  Scaleform::GFx::ASStringNode *v80; // eax
  Scaleform::GFx::ASStringNode *v81; // eax
  Scaleform::GFx::ASStringNode *v82; // eax
  Scaleform::GFx::ASStringNode *v83; // eax
  Scaleform::GFx::ASStringNode *v84; // eax
  Scaleform::GFx::ASStringNode *v85; // eax
  Scaleform::GFx::ASStringNode *v86; // eax
  Scaleform::GFx::ASStringNode *v87; // eax
  Scaleform::GFx::ASStringNode *v88; // eax
  Scaleform::GFx::ASStringNode *v89; // eax
  Scaleform::GFx::ASStringNode *v90; // eax
  Scaleform::GFx::ASStringNode *v91; // eax
  Scaleform::GFx::ASStringNode *v92; // eax
  const Scaleform::GFx::ASString *v93; // [esp-9Ch] [ebp-204h]
  const Scaleform::GFx::ASString *v94; // [esp-84h] [ebp-1ECh]
  const Scaleform::GFx::ASString *v95; // [esp-6Ch] [ebp-1D4h]
  const Scaleform::GFx::ASString *v96; // [esp-54h] [ebp-1BCh]
  const Scaleform::GFx::ASString *v97; // [esp-3Ch] [ebp-1A4h]
  const Scaleform::GFx::ASString *v98; // [esp-24h] [ebp-18Ch]
  const Scaleform::GFx::ASString *v99; // [esp-Ch] [ebp-174h]
  Scaleform::GFx::ASString v100; // [esp+10h] [ebp-158h] BYREF
  Scaleform::GFx::ASString v101; // [esp+14h] [ebp-154h] BYREF
  Scaleform::GFx::ASString str; // [esp+18h] [ebp-150h] BYREF
  Scaleform::GFx::ASString v103; // [esp+1Ch] [ebp-14Ch] BYREF
  Scaleform::GFx::ASString v104; // [esp+20h] [ebp-148h] BYREF
  Scaleform::GFx::ASString v105; // [esp+24h] [ebp-144h] BYREF
  Scaleform::GFx::ASString v106; // [esp+28h] [ebp-140h] BYREF
  Scaleform::GFx::ASString v107; // [esp+2Ch] [ebp-13Ch] BYREF
  Scaleform::GFx::ASString v108; // [esp+30h] [ebp-138h] BYREF
  Scaleform::GFx::ASString v109; // [esp+34h] [ebp-134h] BYREF
  Scaleform::GFx::ASString v110; // [esp+38h] [ebp-130h] BYREF
  Scaleform::GFx::ASString v111; // [esp+3Ch] [ebp-12Ch] BYREF
  Scaleform::GFx::ASString v112; // [esp+40h] [ebp-128h] BYREF
  Scaleform::GFx::ASString v113; // [esp+44h] [ebp-124h] BYREF
  Scaleform::GFx::ASString v114; // [esp+48h] [ebp-120h] BYREF
  Scaleform::GFx::ASString v115; // [esp+4Ch] [ebp-11Ch] BYREF
  Scaleform::GFx::ASString v116; // [esp+50h] [ebp-118h] BYREF
  Scaleform::GFx::ASString v117; // [esp+54h] [ebp-114h] BYREF
  Scaleform::GFx::AS3::VM *v118; // [esp+58h] [ebp-110h]
  Scaleform::GFx::ASString v119; // [esp+5Ch] [ebp-10Ch] BYREF
  Scaleform::GFx::AS3::VM *v120; // [esp+60h] [ebp-108h]
  Scaleform::GFx::ASString v121; // [esp+64h] [ebp-104h] BYREF
  Scaleform::GFx::AS3::VM *v122; // [esp+68h] [ebp-100h]
  Scaleform::GFx::ASString v123; // [esp+6Ch] [ebp-FCh] BYREF
  Scaleform::GFx::ASString v124; // [esp+70h] [ebp-F8h] BYREF
  Scaleform::GFx::ASString v125; // [esp+74h] [ebp-F4h] BYREF
  Scaleform::GFx::ASString v126; // [esp+78h] [ebp-F0h] BYREF
  Scaleform::GFx::ASString v127; // [esp+7Ch] [ebp-ECh] BYREF
  Scaleform::GFx::ASString v128; // [esp+80h] [ebp-E8h] BYREF
  Scaleform::GFx::ASString v129; // [esp+84h] [ebp-E4h] BYREF
  Scaleform::GFx::ASString v130; // [esp+88h] [ebp-E0h] BYREF
  Scaleform::GFx::ASString v131; // [esp+8Ch] [ebp-DCh] BYREF
  Scaleform::GFx::ASString v132; // [esp+90h] [ebp-D8h] BYREF
  Scaleform::GFx::ASString v133; // [esp+94h] [ebp-D4h] BYREF
  Scaleform::GFx::ASString v134; // [esp+98h] [ebp-D0h] BYREF
  Scaleform::GFx::ASString v135; // [esp+9Ch] [ebp-CCh] BYREF
  Scaleform::GFx::ASString v136; // [esp+A0h] [ebp-C8h] BYREF
  Scaleform::GFx::ASString v137; // [esp+A4h] [ebp-C4h] BYREF
  Scaleform::GFx::ASString v138; // [esp+A8h] [ebp-C0h] BYREF
  Scaleform::GFx::ASString v139; // [esp+ACh] [ebp-BCh] BYREF
  Scaleform::GFx::AS3::VM *v140; // [esp+B0h] [ebp-B8h]
  Scaleform::GFx::ASString v141; // [esp+B4h] [ebp-B4h] BYREF
  Scaleform::GFx::AS3::VM *v142; // [esp+B8h] [ebp-B0h]
  Scaleform::GFx::ASString v143; // [esp+BCh] [ebp-ACh] BYREF
  Scaleform::GFx::ASString v144; // [esp+C0h] [ebp-A8h] BYREF
  Scaleform::GFx::ASString v145; // [esp+C4h] [ebp-A4h] BYREF
  Scaleform::GFx::AS3::VM *v146; // [esp+C8h] [ebp-A0h]
  Scaleform::GFx::AS3::VM *v147; // [esp+CCh] [ebp-9Ch]
  Scaleform::GFx::ASString v148; // [esp+D0h] [ebp-98h] BYREF
  Scaleform::GFx::ASString v149; // [esp+D4h] [ebp-94h] BYREF
  Scaleform::GFx::ASString v150; // [esp+D8h] [ebp-90h] BYREF
  Scaleform::GFx::ASString v151; // [esp+DCh] [ebp-8Ch] BYREF
  Scaleform::GFx::ASString v152; // [esp+E0h] [ebp-88h] BYREF
  Scaleform::GFx::ASString v153; // [esp+E4h] [ebp-84h] BYREF
  Scaleform::GFx::AS3::Value v154; // [esp+E8h] [ebp-80h] BYREF
  Scaleform::GFx::AS3::Value v155; // [esp+F8h] [ebp-70h] BYREF
  Scaleform::GFx::AS3::Value v156; // [esp+108h] [ebp-60h] BYREF
  Scaleform::GFx::AS3::Value v157; // [esp+118h] [ebp-50h] BYREF
  Scaleform::GFx::AS3::Value v158; // [esp+128h] [ebp-40h] BYREF
  Scaleform::GFx::AS3::Value v159; // [esp+138h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::Value v160; // [esp+148h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::Value value; // [esp+158h] [ebp-10h] BYREF

  v115.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 ")",
                 1u,
                 0);
  ++v115.pNode->RefCount;
  pObject = this->pTraits.pObject;
  value.value.VNumber = this->alphaOffset;
  value.Bonus.pWeakProxy = 0;
  value.Flags = 4;
  pVM = pObject->pVM;
  pStringManager = pVM->StringManagerRef->pStringManager;
  v146 = pVM;
  v113.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "alphaOffset=", 0xCu, 0);
  ++v113.pNode->RefCount;
  v111.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)&stru_95AF78.m_key_bindings[32],
                 2u,
                 0);
  ++v111.pNode->RefCount;
  v6 = this->pTraits.pObject;
  v159.value.VNumber = this->blueOffset;
  v159.Flags = 4;
  v159.Bonus.pWeakProxy = 0;
  v118 = v6->pVM;
  v109.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 v118->StringManagerRef->pStringManager,
                 "blueOffset=",
                 0xBu,
                 0);
  ++v109.pNode->RefCount;
  v107.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)&stru_95AF78.m_key_bindings[32],
                 2u,
                 0);
  ++v107.pNode->RefCount;
  v7 = this->pTraits.pObject;
  v157.value.VNumber = this->greenOffset;
  v157.Flags = 4;
  v157.Bonus.pWeakProxy = 0;
  v8 = v7->pVM;
  v9 = v8->StringManagerRef->pStringManager;
  v140 = v8;
  v105.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v9, "greenOffset=", 0xCu, 0);
  ++v105.pNode->RefCount;
  v103.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)&stru_95AF78.m_key_bindings[32],
                 2u,
                 0);
  ++v103.pNode->RefCount;
  v10 = this->pTraits.pObject;
  v155.value.VNumber = this->redOffset;
  v155.Flags = 4;
  v155.Bonus.pWeakProxy = 0;
  v11 = v10->pVM;
  v12 = v11->StringManagerRef->pStringManager;
  v120 = v11;
  v101.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v12, "redOffset=", 0xAu, 0);
  ++v101.pNode->RefCount;
  v100.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)&stru_95AF78.m_key_bindings[32],
                 2u,
                 0);
  ++v100.pNode->RefCount;
  v13 = this->pTraits.pObject;
  v158.value.VNumber = this->alphaMultiplier;
  v158.Flags = 4;
  v158.Bonus.pWeakProxy = 0;
  v147 = v13->pVM;
  v114.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 v147->StringManagerRef->pStringManager,
                 "alphaMultiplier=",
                 0x10u,
                 0);
  ++v114.pNode->RefCount;
  v106.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)&stru_95AF78.m_key_bindings[32],
                 2u,
                 0);
  ++v106.pNode->RefCount;
  v14 = this->pTraits.pObject;
  v160.value.VNumber = this->blueMultiplier;
  v160.Flags = 4;
  v160.Bonus.pWeakProxy = 0;
  v15 = v14->pVM;
  v16 = v15->StringManagerRef->pStringManager;
  v122 = v15;
  v110.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v16, "blueMultiplier=", 0xFu, 0);
  ++v110.pNode->RefCount;
  v104.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                 (char *)&stru_95AF78.m_key_bindings[32],
                 2u,
                 0);
  ++v104.pNode->RefCount;
  v17 = this->pTraits.pObject;
  v156.value.VNumber = this->greenMultiplier;
  v156.Flags = 4;
  v156.Bonus.pWeakProxy = 0;
  v18 = v17->pVM;
  v19 = v18->StringManagerRef->pStringManager;
  v142 = v18;
  v112.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v19, "greenMultiplier=", 0x10u, 0);
  ++v112.pNode->RefCount;
  str.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                this->pTraits.pObject->pVM->StringManagerRef->pStringManager,
                (char *)&stru_95AF78.m_key_bindings[32],
                2u,
                0);
  ++str.pNode->RefCount;
  v20 = this->pTraits.pObject;
  v154.value.VNumber = this->redMultiplier;
  v154.Flags = 4;
  v154.Bonus.pWeakProxy = 0;
  v21 = v20->pVM;
  v108.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                 v21->StringManagerRef->pStringManager,
                 "(redMultiplier=",
                 0xFu,
                 0);
  ++v108.pNode->RefCount;
  v99 = Scaleform::GFx::AS3::VM::AsString(v146, &v145, &value);
  v98 = Scaleform::GFx::AS3::VM::AsString(v118, &v143, &v159);
  v97 = Scaleform::GFx::AS3::VM::AsString(v140, &v141, &v157);
  v96 = Scaleform::GFx::AS3::VM::AsString(v120, &v139, &v155);
  v95 = Scaleform::GFx::AS3::VM::AsString(v147, &v137, &v158);
  v94 = Scaleform::GFx::AS3::VM::AsString(v122, &v135, &v160);
  v93 = Scaleform::GFx::AS3::VM::AsString(v142, &v133, &v156);
  v22 = Scaleform::GFx::AS3::VM::AsString(v21, &v131, &v154);
  v23 = Scaleform::GFx::ASString::operator+(&v108, &v129, v22);
  v24 = Scaleform::GFx::ASString::operator+(v23, &v127, &str);
  v25 = Scaleform::GFx::ASString::operator+(v24, &v125, &v112);
  v26 = Scaleform::GFx::ASString::operator+(v25, &v123, v93);
  v27 = Scaleform::GFx::ASString::operator+(v26, &v121, &v104);
  v28 = Scaleform::GFx::ASString::operator+(v27, &v119, &v110);
  v29 = Scaleform::GFx::ASString::operator+(v28, &v117, v94);
  v30 = Scaleform::GFx::ASString::operator+(v29, &v150, &v106);
  v31 = Scaleform::GFx::ASString::operator+(v30, &v138, &v114);
  v32 = Scaleform::GFx::ASString::operator+(v31, &v152, v95);
  v33 = Scaleform::GFx::ASString::operator+(v32, &v136, &v100);
  v34 = Scaleform::GFx::ASString::operator+(v33, &v148, &v101);
  v35 = Scaleform::GFx::ASString::operator+(v34, &v134, v96);
  v36 = Scaleform::GFx::ASString::operator+(v35, &v153, &v103);
  v37 = Scaleform::GFx::ASString::operator+(v36, &v132, &v105);
  v38 = Scaleform::GFx::ASString::operator+(v37, &v116, v97);
  v39 = Scaleform::GFx::ASString::operator+(v38, &v130, &v107);
  v40 = Scaleform::GFx::ASString::operator+(v39, &v151, &v109);
  v41 = Scaleform::GFx::ASString::operator+(v40, &v128, v98);
  v42 = Scaleform::GFx::ASString::operator+(v41, &v144, &v111);
  v43 = Scaleform::GFx::ASString::operator+(v42, &v126, &v113);
  v44 = Scaleform::GFx::ASString::operator+(v43, &v149, v99);
  v45 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::ASString::operator+(v44, &v124, &v115);
  Scaleform::GFx::ASString::Append(result, v45);
  pNode = v124.pNode;
  --v124.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v47 = v149.pNode;
  --v149.pNode->RefCount;
  if ( !v47->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = v126.pNode;
  --v126.pNode->RefCount;
  if ( !v48->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  v49 = v144.pNode;
  --v144.pNode->RefCount;
  if ( !v49->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  v50 = v128.pNode;
  --v128.pNode->RefCount;
  if ( !v50->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  v51 = v151.pNode;
  --v151.pNode->RefCount;
  if ( !v51->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  v52 = v130.pNode;
  --v130.pNode->RefCount;
  if ( !v52->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
  v53 = v116.pNode;
  --v116.pNode->RefCount;
  if ( !v53->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  v54 = v132.pNode;
  --v132.pNode->RefCount;
  if ( !v54->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  v55 = v153.pNode;
  --v153.pNode->RefCount;
  if ( !v55->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  v56 = v134.pNode;
  --v134.pNode->RefCount;
  if ( !v56->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v56);
  v57 = v148.pNode;
  --v148.pNode->RefCount;
  if ( !v57->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  v58 = v136.pNode;
  --v136.pNode->RefCount;
  if ( !v58->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v58);
  v59 = v152.pNode;
  --v152.pNode->RefCount;
  if ( !v59->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  v60 = v138.pNode;
  --v138.pNode->RefCount;
  if ( !v60->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  v61 = v150.pNode;
  --v150.pNode->RefCount;
  if ( !v61->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
  v62 = v117.pNode;
  --v117.pNode->RefCount;
  if ( !v62->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v62);
  v63 = v119.pNode;
  --v119.pNode->RefCount;
  if ( !v63->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  v64 = v121.pNode;
  --v121.pNode->RefCount;
  if ( !v64->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  v65 = v123.pNode;
  --v123.pNode->RefCount;
  if ( !v65->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v65);
  v66 = v125.pNode;
  --v125.pNode->RefCount;
  if ( !v66->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  v67 = v127.pNode;
  --v127.pNode->RefCount;
  if ( !v67->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v67);
  v68 = v129.pNode;
  --v129.pNode->RefCount;
  if ( !v68->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v68);
  v69 = v108.pNode;
  --v108.pNode->RefCount;
  if ( !v69->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v69);
  v70 = v131.pNode;
  --v131.pNode->RefCount;
  if ( !v70->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v70);
  if ( (v154.Flags & 0x1F) > 9 )
  {
    if ( (v154.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v154);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v154);
  }
  v71 = str.pNode;
  --str.pNode->RefCount;
  if ( !v71->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v71);
  v72 = v112.pNode;
  --v112.pNode->RefCount;
  if ( !v72->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v72);
  v73 = v133.pNode;
  --v133.pNode->RefCount;
  if ( !v73->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v73);
  if ( (v156.Flags & 0x1F) > 9 )
  {
    if ( (v156.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v156);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v156);
  }
  v74 = v104.pNode;
  --v104.pNode->RefCount;
  if ( !v74->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v74);
  v75 = v110.pNode;
  --v110.pNode->RefCount;
  if ( !v75->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v75);
  v76 = v135.pNode;
  --v135.pNode->RefCount;
  if ( !v76->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v76);
  if ( (v160.Flags & 0x1F) > 9 )
  {
    if ( (v160.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v160);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v160);
  }
  v77 = v106.pNode;
  --v106.pNode->RefCount;
  if ( !v77->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v77);
  v78 = v114.pNode;
  --v114.pNode->RefCount;
  if ( !v78->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v78);
  v79 = v137.pNode;
  --v137.pNode->RefCount;
  if ( !v79->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v79);
  if ( (v158.Flags & 0x1F) > 9 )
  {
    if ( (v158.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v158);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v158);
  }
  v80 = v100.pNode;
  --v100.pNode->RefCount;
  if ( !v80->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v80);
  v81 = v101.pNode;
  --v101.pNode->RefCount;
  if ( !v81->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v81);
  v82 = v139.pNode;
  --v139.pNode->RefCount;
  if ( !v82->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v82);
  if ( (v155.Flags & 0x1F) > 9 )
  {
    if ( (v155.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v155);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v155);
  }
  v83 = v103.pNode;
  --v103.pNode->RefCount;
  if ( !v83->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v83);
  v84 = v105.pNode;
  --v105.pNode->RefCount;
  if ( !v84->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v84);
  v85 = v141.pNode;
  --v141.pNode->RefCount;
  if ( !v85->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v85);
  if ( (v157.Flags & 0x1F) > 9 )
  {
    if ( (v157.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v157);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v157);
  }
  v86 = v107.pNode;
  --v107.pNode->RefCount;
  if ( !v86->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v86);
  v87 = v109.pNode;
  --v109.pNode->RefCount;
  if ( !v87->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v87);
  v88 = v143.pNode;
  --v143.pNode->RefCount;
  if ( !v88->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v88);
  if ( (v159.Flags & 0x1F) > 9 )
  {
    if ( (v159.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v159);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v159);
  }
  v89 = v111.pNode;
  --v111.pNode->RefCount;
  if ( !v89->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v89);
  v90 = v113.pNode;
  --v113.pNode->RefCount;
  if ( !v90->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v90);
  v91 = v145.pNode;
  --v145.pNode->RefCount;
  if ( !v91->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v91);
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&value);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
  }
  v92 = v115.pNode;
  --v115.pNode->RefCount;
  if ( !v92->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v92);
}
