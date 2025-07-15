void __thiscall Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
        Scaleform::GFx::AS3::XMLSupportImpl *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::Instances::fl::XMLElement *xml,
        Scaleform::GFx::AS3::InstanceTraits::UserDefined *tr)
{
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // edi
  Scaleform::GFx::ASStringManager *pStringManager; // ecx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *pObject; // ebx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *AppendChild)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v10; // esi
  const Scaleform::GFx::ASString *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::ASStringNode *pV; // eax
  Scaleform::GFx::ASStringNode *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::ASStringNode *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::ASStringNode *v21; // ecx
  bool v22; // zf
  Scaleform::MemoryHeap *MHeap; // edx
  Scaleform::GFx::AS3::InstanceTraits::UserDefined *v24; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v25; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v26; // eax
  unsigned int RetTypeInd; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v28; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *v29; // ebx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // eax
  int v34; // ecx
  unsigned int v35; // eax
  int v36; // edx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v37)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v38; // bl
  Scaleform::GFx::AS3::WeakProxy *v39; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v40; // esi
  int v41; // ebx
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // edi
  Scaleform::GFx::AS3::VMAppDomain *ParentDomain; // ecx
  Scaleform::GFx::AS3::ClassTraits::Traits **ClassTrait; // eax
  Scaleform::GFx::ASString *ClassTraits; // eax
  Scaleform::GFx::ASString *v46; // eax
  Scaleform::GFx::ASStringNode *v47; // eax
  Scaleform::GFx::ASStringNode *v48; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *pTable; // ebx
  int v50; // eax
  int v51; // ecx
  int v52; // edx
  int v53; // eax
  int v54; // ecx
  unsigned int v55; // eax
  int v56; // edx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v57)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v58; // bl
  Scaleform::GFx::AS3::WeakProxy *v59; // eax
  Scaleform::GFx::ASString *v60; // ecx
  Scaleform::GFx::ASStringNode *v61; // edx
  Scaleform::GFx::ASString *v62; // ecx
  Scaleform::GFx::ASString *v63; // eax
  Scaleform::GFx::ASStringNode *v64; // eax
  Scaleform::GFx::ASStringNode *v65; // eax
  Scaleform::GFx::ASStringNode *v66; // eax
  Scaleform::GFx::ASStringNode *v67; // eax
  int Flags; // eax
  Scaleform::GFx::AS3::VMAbcFile *v69; // eax
  int method_info_ind; // edx
  const Scaleform::GFx::AS3::Abc::MethodInfo *v71; // ecx
  Scaleform::GFx::ASStringNode *v72; // esi
  unsigned int v73; // eax
  Scaleform::GFx::ASStringManager *v74; // ecx
  Scaleform::GFx::ASStringNode *v75; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v76; // ecx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v77)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v78; // bl
  Scaleform::GFx::AS3::WeakProxy *v79; // eax
  Scaleform::GFx::ASStringNode *v80; // eax
  Scaleform::GFx::ASStringNode *v81; // eax
  int v82; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *CTr; // esi
  unsigned int v84; // ebx
  Scaleform::GFx::ASStringNode *v85; // ecx
  Scaleform::GFx::ASStringManager *v86; // ecx
  int v87; // ebx
  Scaleform::GFx::ASStringNode *v88; // esi
  Scaleform::GFx::ASStringNode **p_declaredBy; // eax
  Scaleform::GFx::AS3::GASRefCountBase *v90; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v91; // eax
  Scaleform::GFx::ASString *v92; // ecx
  Scaleform::GFx::ASString *v93; // eax
  Scaleform::GFx::ASStringNode *v94; // eax
  Scaleform::GFx::ASStringNode *v95; // eax
  Scaleform::GFx::ASStringNode *v96; // eax
  Scaleform::GFx::ASStringNode *v97; // ebx
  Scaleform::GFx::AS3::WeakProxy *v98; // eax
  Scaleform::GFx::AS3::StringManager *v99; // edi
  __m128i *v100; // esi
  unsigned int v101; // eax
  Scaleform::GFx::ASStringNode *v102; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v103; // esi
  Scaleform::GFx::ASStringNode *v104; // eax
  Scaleform::GFx::ASString *v105; // eax
  Scaleform::GFx::ASStringNode *v106; // eax
  Scaleform::GFx::ASStringNode *v107; // eax
  int v108; // eax
  Scaleform::GFx::AS3::Slots *v109; // ecx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  Scaleform::GFx::ASStringNode *v111; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v112; // eax
  unsigned int FirstOwnSlotNum; // ecx
  Scaleform::GFx::ASStringNode *SlotNameNode; // eax
  Scaleform::GFx::ASStringNode *pNode; // edx
  const Scaleform::GFx::AS3::Traits *v116; // eax
  Scaleform::GFx::ASStringManager *pManager; // ebx
  $877A9988573213A5FC37040398A8D661 *v118; // esi
  Scaleform::GFx::ASStringNode *v119; // edi
  int v120; // eax
  char *v121; // eax
  unsigned int pFreeStringNodes; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v123; // eax
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // edx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v126; // ecx
  Scaleform::GFx::ASStringNode *v127; // eax
  Scaleform::GFx::ASStringNode *v128; // edi
  Scaleform::GFx::ASString *p_method; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v130; // ebx
  Scaleform::GFx::ASStringNode *v131; // esi
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v132)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::WeakProxy *v133; // eax
  char *v134; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v136; // eax
  Scaleform::GFx::ASStringManager *v137; // eax
  Scaleform::GFx::ASStringManager::TextPage *pTextBufferPages; // ecx
  const Scaleform::GFx::ASString *p_pTextBufferPages; // eax
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::Traits_vtbl *v141; // edx
  Scaleform::GFx::AS3::VMAppDomain *v142; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // ebx
  Scaleform::GFx::ASStringManager *v144; // ecx
  int v145; // ebx
  Scaleform::GFx::ASStringNode *v146; // edi
  unsigned int *p_first_opt_param_num; // eax
  Scaleform::GFx::ASString *(__thiscall *GetQualifiedName)(Scaleform::GFx::AS3::Traits *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Traits::QNameFormat); // edx
  Scaleform::GFx::ASStringNode *v149; // eax
  Scaleform::GFx::AS3::VTable *v150; // eax
  const Scaleform::GFx::AS3::Value *v151; // ecx
  int VInt; // eax
  Scaleform::GFx::AS3::Value::V2U v153; // edi
  Scaleform::GFx::AS3::Object_vtbl *v154; // edx
  unsigned int v155; // eax
  int v156; // ebx
  Scaleform::GFx::ASString *QualifiedName; // eax
  Scaleform::GFx::ASStringNode *Ind; // edx
  Scaleform::GFx::ASStringNode *v159; // eax
  Scaleform::GFx::ASStringNode *v160; // eax
  Scaleform::GFx::ASStringNode *v161; // eax
  Scaleform::GFx::ASStringNode *v162; // eax
  Scaleform::GFx::ASString *p_returnType; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v164; // ebx
  const Scaleform::GFx::ASString *v165; // eax
  Scaleform::GFx::ASStringNode *v166; // eax
  Scaleform::GFx::AS3::Value::V1U v167; // ebx
  const Scaleform::GFx::AS3::Abc::Multiname *(__thiscall *GetMultiname)(Scaleform::GFx::AS3::VMFile *, unsigned int); // ecx
  const Scaleform::GFx::AS3::Value *v169; // eax
  unsigned int v170; // ecx
  unsigned int v171; // edx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v172; // edi
  int (__thiscall *v173)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *); // eax
  bool v174; // bl
  Scaleform::GFx::AS3::StringManager *v175; // edi
  __m128i *ValueStr; // esi
  unsigned int v177; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *StringNode; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v179; // esi
  Scaleform::GFx::ASStringNode *v180; // eax
  Scaleform::GFx::ASStringNode *v181; // ebx
  Scaleform::GFx::ASStringNode *v182; // eax
  Scaleform::GFx::ASStringNode *v183; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v184; // edi
  Scaleform::GFx::ASString *v185; // eax
  Scaleform::GFx::ASStringNode *v186; // eax
  Scaleform::GFx::ASString *p_true; // eax
  Scaleform::GFx::ASString *p_type; // eax
  unsigned int v189; // eax
  Scaleform::GFx::ASStringNode *v190; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v191; // edi
  int (__thiscall *v192)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *); // edx
  bool v193; // bl
  __m128i *v194; // esi
  Scaleform::GFx::AS3::StringManager *v195; // edi
  unsigned int v196; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v197; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v198; // esi
  Scaleform::GFx::ASStringNode *v199; // eax
  Scaleform::GFx::ASString *p_false; // eax
  Scaleform::GFx::ASStringNode *v201; // eax
  _BYTE *HashFlags; // eax
  Scaleform::GFx::ASString *p_const; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v204; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v205; // esi
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v206)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::ASStringNode *v207; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // eax
  const Scaleform::GFx::ASString *v209; // eax
  Scaleform::GFx::ASStringNode *v210; // eax
  const Scaleform::GFx::ASString *v211; // eax
  Scaleform::GFx::ASStringNode *v212; // ecx
  const Scaleform::GFx::ASString *v213; // eax
  Scaleform::GFx::ASStringNode *v214; // eax
  Scaleform::GFx::ASStringNode *v215; // eax
  Scaleform::GFx::ASStringNode *v216; // eax
  Scaleform::GFx::ASStringNode *v217; // eax
  Scaleform::GFx::ASStringNode *v218; // eax
  Scaleform::GFx::ASStringNode *v219; // eax
  Scaleform::GFx::ASStringNode *v220; // eax
  Scaleform::GFx::ASStringNode *v221; // eax
  Scaleform::GFx::ASStringNode *v222; // eax
  Scaleform::GFx::ASStringNode *v223; // eax
  Scaleform::GFx::ASStringNode *v224; // eax
  Scaleform::GFx::ASStringNode *v225; // eax
  Scaleform::GFx::ASStringNode *v226; // eax
  Scaleform::GFx::ASStringNode *v227; // eax
  Scaleform::GFx::ASStringNode *v228; // eax
  Scaleform::GFx::ASStringNode *v229; // eax
  Scaleform::GFx::ASStringNode *v230; // eax
  Scaleform::GFx::ASStringNode *v231; // eax
  Scaleform::GFx::ASStringNode *v232; // eax
  Scaleform::GFx::ASStringNode *v233; // eax
  Scaleform::GFx::ASStringNode *v234; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v235; // edi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v236; // ecx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v237)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v238; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v239; // ebx
  const Scaleform::GFx::ASString *v240; // eax
  Scaleform::GFx::ASStringNode *v241; // eax
  Scaleform::GFx::ASStringNode *v242; // eax
  Scaleform::GFx::ASStringNode *v243; // eax
  Scaleform::GFx::ASStringNode *v244; // eax
  Scaleform::GFx::ASStringNode *v245; // eax
  Scaleform::GFx::ASStringNode *v246; // eax
  Scaleform::GFx::ASStringNode *v247; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v248; // [esp+18h] [ebp-1F0h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v249; // [esp+1Ch] [ebp-1ECh]
  Scaleform::GFx::AS3::Abc::Multiname *v250; // [esp+24h] [ebp-1E4h]
  int v251; // [esp+24h] [ebp-1E4h]
  int v252; // [esp+34h] [ebp-1D4h] BYREF
  Scaleform::GFx::ASString name; // [esp+38h] [ebp-1D0h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> param; // [esp+3Ch] [ebp-1CCh] BYREF
  Scaleform::GFx::AS3::Instances::fl::Namespace *pns; // [esp+40h] [ebp-1C8h]
  unsigned int v256; // [esp+44h] [ebp-1C4h]
  Scaleform::GFx::ASString _type; // [esp+48h] [ebp-1C0h] BYREF
  const Scaleform::GFx::AS3::Traits *t; // [esp+4Ch] [ebp-1BCh] BYREF
  Scaleform::GFx::ASString _access; // [esp+50h] [ebp-1B8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> factory; // [esp+54h] [ebp-1B4h] BYREF
  Scaleform::GFx::ASString _factory; // [esp+58h] [ebp-1B0h] BYREF
  int v262; // [esp+5Ch] [ebp-1ACh] BYREF
  Scaleform::GFx::ASString _method; // [esp+60h] [ebp-1A8h] BYREF
  Scaleform::GFx::ASString _accessor; // [esp+64h] [ebp-1A4h] BYREF
  Scaleform::GFx::AS3::MultinameHash<bool,2> handled; // [esp+68h] [ebp-1A0h] BYREF
  Scaleform::GFx::ASString _true; // [esp+70h] [ebp-198h] BYREF
  Scaleform::GFx::ASString _false; // [esp+74h] [ebp-194h] BYREF
  Scaleform::GFx::ASString _index; // [esp+78h] [ebp-190h] BYREF
  Scaleform::GFx::ASString _parameter; // [esp+7Ch] [ebp-18Ch] BYREF
  Scaleform::GFx::ASString _optional; // [esp+80h] [ebp-188h] BYREF
  Scaleform::GFx::ASString v271; // [esp+84h] [ebp-184h] BYREF
  unsigned int i; // [esp+88h] [ebp-180h]
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *xml_itr; // [esp+8Ch] [ebp-17Ch]
  Scaleform::GFx::AS3::Value v274; // [esp+90h] [ebp-178h] BYREF
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+A4h] [ebp-164h] BYREF
  Scaleform::GFx::ASString _var; // [esp+A8h] [ebp-160h] BYREF
  Scaleform::GFx::ASString _const; // [esp+ACh] [ebp-15Ch] BYREF
  Scaleform::GFx::ASString _declaredBy; // [esp+B0h] [ebp-158h] BYREF
  const Scaleform::GFx::AS3::Abc::MethodInfo *mi; // [esp+B4h] [ebp-154h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+B8h] [ebp-150h]
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [esp+BCh] [ebp-14Ch] BYREF
  Scaleform::GFx::ASString _returnType; // [esp+C0h] [ebp-148h] BYREF
  Scaleform::GFx::ASString _name; // [esp+C4h] [ebp-144h] BYREF
  Scaleform::GFx::ASString type; // [esp+C8h] [ebp-140h] BYREF
  Scaleform::GFx::ASString _uri; // [esp+CCh] [ebp-13Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v286[4]; // [esp+D0h] [ebp-138h] BYREF
  Scaleform::GFx::ASString _access_name; // [esp+D4h] [ebp-134h] BYREF
  unsigned int first_opt_param_num; // [esp+D8h] [ebp-130h] BYREF
  Scaleform::GFx::ASString v289; // [esp+DCh] [ebp-12Ch] BYREF
  Scaleform::GFx::AS3::VMAbcFile *file; // [esp+E0h] [ebp-128h] BYREF
  Scaleform::GFx::AS3::Abc::MiInd method_ind; // [esp+E4h] [ebp-124h]
  Scaleform::GFx::AS3::Value func; // [esp+E8h] [ebp-120h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+F8h] [ebp-110h] BYREF
  Scaleform::GFx::AS3::XMLSupportImpl *v294; // [esp+114h] [ebp-F4h]
  Scaleform::GFx::ASStringNode *v295; // [esp+118h] [ebp-F0h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v296; // [esp+11Ch] [ebp-ECh]
  const Scaleform::GFx::AS3::Value *real_func; // [esp+120h] [ebp-E8h]
  unsigned int size; // [esp+124h] [ebp-E4h]
  Scaleform::GFx::AS3::Value v299; // [esp+128h] [ebp-E0h] BYREF
  Scaleform::GFx::ASStringNode *v300; // [esp+13Ch] [ebp-CCh] BYREF
  Scaleform::GFx::AS3::Slots::CIterator it; // [esp+140h] [ebp-C8h]
  Scaleform::GFx::AS3::Value v302; // [esp+148h] [ebp-C0h] BYREF
  Scaleform::GFx::ASString v303; // [esp+158h] [ebp-B0h] BYREF
  Scaleform::GFx::ASStringNode *v304; // [esp+15Ch] [ebp-ACh]
  Scaleform::GFx::ASStringNode *v305; // [esp+160h] [ebp-A8h] BYREF
  unsigned int v306; // [esp+164h] [ebp-A4h]
  Scaleform::GFx::ASStringNode *v307; // [esp+168h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::VMFile *v308; // [esp+16Ch] [ebp-9Ch]
  Scaleform::GFx::ASString v309; // [esp+170h] [ebp-98h] BYREF
  Scaleform::GFx::ASString v310; // [esp+174h] [ebp-94h] BYREF
  Scaleform::GFx::AS3::Multiname v311; // [esp+178h] [ebp-90h] BYREF
  Scaleform::GFx::AS3::Value v312; // [esp+190h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value v313; // [esp+1A0h] [ebp-68h] BYREF
  Scaleform::LongFormatter f; // [esp+1B0h] [ebp-58h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v315; // [esp+200h] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v316; // [esp+204h] [ebp-4h] BYREF

  StringManagerRef = vm->StringManagerRef;
  pns = vm->PublicNamespace.pObject;
  _true.pNode = StringManagerRef->Builtins[4].pNode;
  ++_true.pNode->RefCount;
  _false.pNode = StringManagerRef->Builtins[5].pNode;
  ++_false.pNode->RefCount;
  pStringManager = StringManagerRef->pStringManager;
  v294 = this;
  v256 = 0;
  sm = StringManagerRef;
  _type.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(pStringManager, "type", 4u, 0);
  ++_type.pNode->RefCount;
  _optional.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      StringManagerRef->pStringManager,
                      "optional",
                      8u,
                      0);
  ++_optional.pNode->RefCount;
  _parameter.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       StringManagerRef->pStringManager,
                       "parameter",
                       9u,
                       0);
  ++_parameter.pNode->RefCount;
  _index.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                   StringManagerRef->pStringManager,
                   "index",
                   5u,
                   0);
  ++_index.pNode->RefCount;
  if ( (tr->Flags & 0x20) != 0 )
    pObject = vm->TraitsClassClass.pObject;
  else
    pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)tr->pParent.pObject;
  xml_itr = (Scaleform::GFx::AS3::InstanceTraits::fl::XML *)this->GetITraitsXML(this);
  if ( pObject )
  {
    param.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                   StringManagerRef->pStringManager,
                                                                   "extendsClass",
                                                                   0xCu,
                                                                   0);
    ++param.pV->pPrev;
    do
    {
      Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
        xml_itr,
        &factory,
        xml_itr,
        pns,
        (const Scaleform::GFx::ASString *)&param,
        0);
      v274.Bonus.pWeakProxy = 0;
      *(_QWORD *)&v274.value.VNumber = (unsigned int)factory.pV;
      AppendChild = xml->AppendChild;
      v274.Flags = 12;
      HIBYTE(v252) = !AppendChild(xml, &result[3], &v274)->Result;
      if ( (v274.Flags & 0x1F) > 9 )
      {
        if ( (v274.Flags & 0x200) != 0 )
        {
          pWeakProxy = v274.Bonus.pWeakProxy;
          --v274.Bonus.pWeakProxy->RefCount;
          if ( !pWeakProxy->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          memset(&v274.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v274);
        }
      }
      if ( HIBYTE(v252) )
      {
        pV = (Scaleform::GFx::ASStringNode *)param.pV;
        goto LABEL_19;
      }
      v10 = factory.pV;
      v11 = pObject->GetQualifiedName(pObject, (Scaleform::GFx::ASString *)&mi, qnfWithColons);
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v10, pns, &_type, v11);
      v12 = (Scaleform::GFx::ASStringNode *)mi;
      --mi->ParamTypes.Data.Data;
      if ( !v12->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      pObject = (Scaleform::GFx::AS3::ClassTraits::ClassClass *)pObject->pParent.pObject;
    }
    while ( pObject );
    v13 = (Scaleform::GFx::ASStringNode *)param.pV;
    --param.pV->pPrev;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  if ( (tr->Flags & 0x20) != 0 )
  {
LABEL_105:
    Flags = tr->Flags;
    if ( (Flags & 0x10) == 0
      || (Flags & 0x20) != 0
      || (v69 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile(tr),
          method_info_ind = tr->class_info->inst_info.method_info_ind,
          file = v69,
          v71 = v69->File.pObject->Methods.Info.Data.Data[method_info_ind],
          v72 = (Scaleform::GFx::ASStringNode *)v71->ParamTypes.Data.Size,
          mi = v71,
          (_access_name.pNode = v72) == 0) )
    {
LABEL_163:
      _access.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        StringManagerRef->pStringManager,
                        "access",
                        6u,
                        0);
      ++_access.pNode->RefCount;
      _accessor.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManagerRef->pStringManager,
                          "accessor",
                          8u,
                          0);
      ++_accessor.pNode->RefCount;
      _method.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        StringManagerRef->pStringManager,
                        "method",
                        6u,
                        0);
      ++_method.pNode->RefCount;
      _declaredBy.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                            StringManagerRef->pStringManager,
                            "declaredBy",
                            0xAu,
                            0);
      ++_declaredBy.pNode->RefCount;
      _const.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                       StringManagerRef->pStringManager,
                       "constant",
                       8u,
                       0);
      ++_const.pNode->RefCount;
      _var.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     StringManagerRef->pStringManager,
                     "variable",
                     8u,
                     0);
      ++_var.pNode->RefCount;
      _returnType.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                            StringManagerRef->pStringManager,
                            "returnType",
                            0xAu,
                            0);
      ++_returnType.pNode->RefCount;
      _uri.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                     StringManagerRef->pStringManager,
                     "uri",
                     3u,
                     0);
      ++_uri.pNode->RefCount;
      _name.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      StringManagerRef->pStringManager,
                      "name",
                      4u,
                      0);
      ++_name.pNode->RefCount;
      handled.Entries.mHash.pHeap = vm->MHeap;
      v108 = tr->VArray.Data.Size + tr->FirstOwnSlotNum - 1;
      handled.Entries.mHash.pTable = 0;
      it.Ind.Index = v108;
      while ( 1 )
      {
        v109 = &tr->Scaleform::GFx::AS3::Slots;
        if ( it.Ind.Index <= -1 )
          break;
        if ( it.Ind.Index >= v109->FirstOwnSlotNum )
          p_Value = &tr->VArray.Data.Data[it.Ind.Index - v109->FirstOwnSlotNum].Value;
        else
          p_Value = (Scaleform::GFx::AS3::SlotInfo *)Scaleform::GFx::AS3::Slots::GetSlotInfo(
                                                       (Scaleform::GFx::AS3::Slots *)tr->Parent,
                                                       it.Ind);
        name.pNode = (Scaleform::GFx::ASStringNode *)p_Value;
        v112 = p_Value->pNs.pObject;
        if ( v112->Uri.pNode == pns->Uri.pNode && ((*((_BYTE *)pns + 20) ^ *((_BYTE *)v112 + 20)) & 0xF) == 0 )
        {
          if ( it.Ind.Index >= 0 && (FirstOwnSlotNum = tr->FirstOwnSlotNum, it.Ind.Index >= FirstOwnSlotNum) )
            SlotNameNode = tr->VArray.Data.Data[it.Ind.Index - FirstOwnSlotNum].Key.pObject;
          else
            SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode((Scaleform::GFx::AS3::Slots *)tr->Parent, it.Ind);
          pNode = name.pNode;
          t = (const Scaleform::GFx::AS3::Traits *)SlotNameNode;
          ++SlotNameNode->RefCount;
          v116 = t;
          pManager = pNode->pManager;
          ++t->pPrev;
          v118 = &v116->12;
          v119 = (Scaleform::GFx::ASStringNode *)v116;
          v299.Flags = (unsigned int)v116;
          v299.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pManager;
          if ( pManager )
            pManager->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)(((int)&pManager->pFreeStringNodes->pData + 1)
                                                                        & 0x8FBFFFFF);
          if ( handled.Entries.mHash.pTable
            && (v120 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
                         &handled.Entries.mHash,
                         (const Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *)&v299,
                         handled.Entries.mHash.pTable->SizeMask
                       & (v116->RefCount
                        & 0xFFFFFF
                        ^ (4 * (*(_DWORD *)&pManager->pTextBufferPages->Entries[1].Buff[4] & 0xFFFFFF))
                        ^ ((int)pManager->pStringNodePages << 28 >> 28))),
                v120 >= 0)
            && (v121 = (char *)&handled.Entries.mHash.pTable[2] + 20 * v120) != 0 )
          {
            _factory.pNode = (Scaleform::GFx::ASStringNode *)(v121 + 8);
          }
          else
          {
            _factory.pNode = 0;
          }
          if ( pManager )
          {
            if ( ((unsigned __int8)pManager & 1) != 0 )
            {
              v299.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)((char *)&pManager[-1].FileName.HeapTypeBits + 3);
            }
            else
            {
              pFreeStringNodes = (unsigned int)pManager->pFreeStringNodes;
              if ( (pFreeStringNodes & 0x3FFFFF) != 0 )
              {
                pManager->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)(pFreeStringNodes - 1);
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pManager);
              }
            }
          }
          v22 = v118->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
          if ( v22 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v119);
          if ( !_factory.pNode )
          {
            v123 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)name.pNode->pManager;
            HIBYTE(v252) = 1;
            v295 = (Scaleform::GFx::ASStringNode *)t;
            ++t->pPrev;
            v296 = v123;
            if ( v123 )
            {
              v123->RefCount = (v123->RefCount + 1) & 0x8FBFFFFF;
              v123 = v296;
            }
            v274.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)((char *)&v252 + 3);
            pNext = v123[1].pNext;
            v274.Flags = (unsigned int)&v295;
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef>(
              &handled.Entries.mHash,
              handled.Entries.mHash.pHeap,
              (const Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef *)&v274,
              v295->HashFlags & 0xFFFFFF ^ (4 * (pNext->RefCount & 0xFFFFFF)) ^ ((int)v123[1].__vftable << 28 >> 28));
            if ( v296 )
            {
              if ( ((unsigned __int8)v296 & 1) != 0 )
              {
                v296 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v296 - 1);
              }
              else
              {
                RefCount = v296->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  v126 = v296;
                  v296->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v126);
                }
              }
            }
            v127 = v295;
            --v295->RefCount;
            if ( !v127->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v127);
            v271.pNode = (Scaleform::GFx::ASStringNode *)((int)name.pNode->pData << 22 >> 27);
            v128 = v271.pNode;
            if ( (int)v271.pNode <= 10 )
            {
              if ( ((int)name.pNode->pData & 1) != 0
                || (HashFlags = (_BYTE *)name.pNode->HashFlags) != 0 && (*HashFlags & 0xF) == 6 )
              {
                p_const = &_const;
              }
              else
              {
                p_const = &_var;
              }
              v204 = pns;
              v205 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                       xml_itr,
                       &v316,
                       xml_itr,
                       pns,
                       p_const,
                       0)->pV;
              v206 = xml->AppendChild;
              mn.Name.Bonus.pWeakProxy = v274.Bonus.pWeakProxy;
              mn.Obj.pObject = 0;
              mn.Kind = 12;
              mn.Name.Flags = (unsigned int)v205;
              HIBYTE(v252) = !v206(xml, &v286[3], (const Scaleform::GFx::AS3::Value *)&mn)->Result;
              Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&mn);
              if ( HIBYTE(v252) )
                goto LABEL_307;
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                v205,
                v204,
                &_name,
                (const Scaleform::GFx::ASString *)&t);
              v207 = name.pNode;
              DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType((Scaleform::GFx::AS3::SlotInfo *)name.pNode, vm);
              if ( DataType )
              {
                v209 = DataType->GetQualifiedName(DataType, (Scaleform::GFx::ASString *)&v300, qnfWithColons);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v205, v204, &_type, v209);
                v210 = v300;
                --v300->RefCount;
                if ( !v210->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v210);
              }
              v211 = (const Scaleform::GFx::ASString *)v207->pManager;
              v212 = v211[7].pNode;
              v213 = v211 + 7;
              if ( v212->Size )
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v205, v204, &_uri, v213);
              if ( v207->HashFlags )
                Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(
                  v294,
                  vm,
                  v205,
                  (const Scaleform::GFx::AS3::VMAbcFile *)v207->RefCount,
                  (const Scaleform::GFx::AS3::Abc::TraitInfo *)v207->HashFlags);
            }
            else
            {
              p_method = &_method;
              if ( v271.pNode != (Scaleform::GFx::ASStringNode *)11 )
                p_method = &_accessor;
              v130 = pns;
              v131 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                                                       xml_itr,
                                                       &v315,
                                                       xml_itr,
                                                       pns,
                                                       p_method,
                                                       0)->pV;
              v132 = xml->AppendChild;
              _factory.pNode = v131;
              v302.Bonus.pWeakProxy = 0;
              v302.Flags = 12;
              *(_QWORD *)&v302.value.VNumber = __PAIR64__((unsigned int)v274.Bonus.pWeakProxy, (unsigned int)v131);
              HIBYTE(v252) = !v132(xml, (Scaleform::GFx::AS3::CheckResult *)&v262 + 3, &v302)->Result;
              if ( (v302.Flags & 0x1F) > 9 )
              {
                if ( (v302.Flags & 0x200) != 0 )
                {
                  v133 = v302.Bonus.pWeakProxy;
                  --v302.Bonus.pWeakProxy->RefCount;
                  if ( !v133->RefCount )
                    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v133);
                  memset(&v302.Bonus, 0, 12);
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v302);
                }
              }
              if ( HIBYTE(v252) )
                goto LABEL_307;
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                v130,
                &_name,
                (const Scaleform::GFx::ASString *)&t);
              if ( ((int)name.pNode->pData & 0x3E0) != 0x160 )
              {
                v134 = 0;
                if ( v128 == (Scaleform::GFx::ASStringNode *)12 )
                {
                  v134 = "readonly";
                }
                else if ( v128 == (Scaleform::GFx::ASStringNode *)13 )
                {
                  v134 = "writeonly";
                }
                else if ( v128 == (Scaleform::GFx::ASStringNode *)14 )
                {
                  v134 = "readwrite";
                }
                ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                    sm->pStringManager,
                                    v134,
                                    strlen(v134),
                                    0);
                v130 = pns;
                _access_name.pNode = ConstStringNode;
                ++ConstStringNode->RefCount;
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                  v130,
                  &_access,
                  &_access_name);
                v136 = _access_name.pNode;
                --_access_name.pNode->RefCount;
                if ( !v136->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v136);
                v128 = v271.pNode;
              }
              v137 = name.pNode->pManager;
              pTextBufferPages = v137->pTextBufferPages;
              p_pTextBufferPages = (const Scaleform::GFx::ASString *)&v137->pTextBufferPages;
              if ( *(_DWORD *)&pTextBufferPages->Entries[1].Buff[8] )
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                  v130,
                  &_uri,
                  p_pTextBufferPages);
              v251 = ((32 * (int)name.pNode->pData) >> 15) + (v128 == (Scaleform::GFx::ASStringNode *)13);
              VT = Scaleform::GFx::AS3::Traits::GetVT(tr);
              Scaleform::GFx::AS3::VTable::GetValue(VT, &func, (Scaleform::GFx::AS3::AbsoluteIndex)v251);
              v141 = (Scaleform::GFx::AS3::Traits_vtbl *)tr->__vftable;
              i = func.Flags & 0x1F;
              v142 = v141->GetAppDomain(tr);
              FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(vm, &func, v142);
              if ( Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(
                     vm->TraitsClassClass.pObject->ITraits.pObject,
                     FunctReturnType) )
              {
                v144 = sm->pStringManager;
                v145 = v256 | 8;
                v256 |= 8u;
                v146 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v144, "*", 1u, 0);
                ++v146->RefCount;
                first_opt_param_num = (unsigned int)v146;
                p_first_opt_param_num = &first_opt_param_num;
              }
              else
              {
                GetQualifiedName = FunctReturnType->GetQualifiedName;
                v256 |= 0x10u;
                p_first_opt_param_num = (unsigned int *)GetQualifiedName(
                                                          FunctReturnType,
                                                          (Scaleform::GFx::ASString *)&v305,
                                                          qnfWithColons);
                v145 = v256;
                v146 = (Scaleform::GFx::ASStringNode *)first_opt_param_num;
              }
              type.pNode = (Scaleform::GFx::ASStringNode *)*p_first_opt_param_num;
              ++type.pNode->RefCount;
              if ( (v145 & 0x10) != 0 )
              {
                v149 = v305;
                --v305->RefCount;
                v145 &= ~0x10u;
                v22 = v149->RefCount == 0;
                v256 = v145;
                if ( v22 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v149);
              }
              if ( (v145 & 8) != 0 )
              {
                v145 &= ~8u;
                v22 = v146->RefCount-- == 1;
                v256 = v145;
                if ( v22 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v146);
              }
              if ( i == 7 )
              {
                v150 = Scaleform::GFx::AS3::Traits::GetVT(func.value.VS._2.pTraits);
                v151 = &v150->VTMethods.Data.Data[func.value.VS._1.VInt];
                VInt = v151->value.VS._1.VInt;
                v153.VObj = (Scaleform::GFx::AS3::Object *)v151->value.VS._2;
                v154 = v153.VObj->__vftable;
                real_func = v151;
                method_ind.Ind = VInt;
                v155 = ((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U))v154->Call)(v153);
                i = v155;
                if ( v271.pNode == (Scaleform::GFx::ASStringNode *)13 )
                {
                  Scaleform::GFx::AS3::Multiname::Multiname(
                    &v311,
                    (Scaleform::GFx::AS3::VMFile *)i,
                    (Scaleform::GFx::AS3::Abc::Multiname *)(*(_DWORD *)(*(_DWORD *)(v155 + 60) + 96)
                                                          + 16
                                                          * **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v155 + 60)
                                                                                                + 120)
                                                                                    + 4 * method_ind.Ind)
                                                                        + 12)));
                  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v311) )
                  {
                    v156 = v145 | 0x20;
                    v256 = v156;
                    QualifiedName = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                                      sm,
                                      &v310,
                                      "*");
                  }
                  else
                  {
                    v289.pNode = v311.Name.value.VS._1.VStr;
                    ++*(_DWORD *)(v311.Name.value.VS._1.VInt + 12);
                    v156 = v145 | 0xC0;
                    v256 = v156;
                    QualifiedName = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                                      &v303,
                                      (Scaleform::GFx::ASStringNode *)v311.Obj.pObject,
                                      &v289,
                                      qnfWithColons);
                  }
                  Ind = QualifiedName->pNode;
                  ++Ind->RefCount;
                  v159 = type.pNode;
                  --type.pNode->RefCount;
                  v22 = v159->RefCount == 0;
                  method_ind.Ind = (int)Ind;
                  if ( v22 )
                  {
                    Scaleform::GFx::ASStringNode::ReleaseNode(v159);
                    Ind = (Scaleform::GFx::ASStringNode *)method_ind.Ind;
                  }
                  type.pNode = Ind;
                  if ( (v156 & 0x80u) != 0 )
                  {
                    v160 = v303.pNode;
                    --v303.pNode->RefCount;
                    v156 &= ~0x80u;
                    v22 = v160->RefCount == 0;
                    v256 = v156;
                    if ( v22 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v160);
                  }
                  if ( (v156 & 0x40) != 0 )
                  {
                    v161 = v289.pNode;
                    --v289.pNode->RefCount;
                    v156 &= ~0x40u;
                    v22 = v161->RefCount == 0;
                    v256 = v156;
                    if ( v22 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v161);
                  }
                  if ( (v156 & 0x20) != 0 )
                  {
                    v162 = v310.pNode;
                    --v310.pNode->RefCount;
                    v22 = v162->RefCount == 0;
                    v256 = v156 & 0xFFFFFFDF;
                    if ( v22 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v162);
                  }
                  Scaleform::GFx::AS3::Multiname::~Multiname(&v311);
                }
                p_returnType = &_returnType;
                if ( ((int)name.pNode->pData & 0x3E0) != 0x160 )
                  p_returnType = &_type;
                v164 = pns;
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                  pns,
                  p_returnType,
                  &type);
                v165 = (const Scaleform::GFx::ASString *)((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U, Scaleform::GFx::ASStringNode **, _DWORD))v153.VObj->GetDynamicProperty)(
                                                           v153,
                                                           &v307,
                                                           0);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                  v164,
                  &_declaredBy,
                  v165);
                v166 = v307;
                --v307->RefCount;
                if ( !v166->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v166);
                if ( ((int)name.pNode->pData & 0x3E0) == 0x160 )
                {
                  v167 = real_func->value.VS._1;
                  v308 = (Scaleform::GFx::AS3::VMFile *)((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U))v153.VObj->Call)(v153);
                  GetMultiname = v308[1].__vftable[2].GetMultiname;
                  method_ind.Ind = (int)v308[1].__vftable;
                  v169 = (const Scaleform::GFx::AS3::Value *)*((_DWORD *)GetMultiname + v167.VInt);
                  v170 = v169[1].Flags;
                  v171 = v170 - (unsigned int)v169[1].value.VS._2.VObj;
                  real_func = v169;
                  size = v170;
                  v306 = v171;
                  v271.pNode = 0;
                  if ( v170 )
                  {
                    while ( 1 )
                    {
                      v172 = xml_itr;
                      v304 = (Scaleform::GFx::ASStringNode *)((char *)&v271.pNode->pData + 1);
                      Scaleform::LongFormatter::LongFormatter(&f, (unsigned int)&v271.pNode->pData + 1);
                      Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                        v172,
                        &param,
                        v172,
                        pns,
                        &_parameter,
                        0);
                      *(_QWORD *)&v313.value.VNumber = __PAIR64__(
                                                         (unsigned int)v274.Bonus.pWeakProxy,
                                                         (unsigned int)param.pV);
                      v173 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *))*((_DWORD *)v131->pData + 22);
                      v313.Bonus.pWeakProxy = 0;
                      v313.Flags = 12;
                      v174 = *(_BYTE *)v173(v131, &v286[2], &v313) == 0;
                      Scaleform::GFx::AS3::Value::~Value(&v313);
                      if ( v174 )
                        break;
                      Scaleform::LongFormatter::Convert(&f);
                      v175 = vm->StringManagerRef;
                      ValueStr = (__m128i *)f.ValueStr;
                      v177 = Scaleform::LongFormatter::GetSize(&f);
                      StringNode = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                                 v175->pStringManager,
                                                                                 ValueStr,
                                                                                 v177);
                      v179 = pns;
                      val = StringNode;
                      ++StringNode->pPrev;
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                        param.pV,
                        v179,
                        &_index,
                        (const Scaleform::GFx::ASString *)&val);
                      v180 = (Scaleform::GFx::ASStringNode *)val;
                      --val->pPrev;
                      if ( !v180->RefCount )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v180);
                      v181 = v271.pNode;
                      Scaleform::GFx::AS3::Multiname::Multiname(
                        &v311,
                        v308,
                        (Scaleform::GFx::AS3::Abc::Multiname *)(*(_DWORD *)(method_ind.Ind + 96)
                                                              + 16
                                                              * *((_DWORD *)&real_func->value.VS._2.VObj->__vftable
                                                                + (int)v271.pNode)));
                      if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v311) )
                      {
                        file = (Scaleform::GFx::AS3::VMAbcFile *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                   sm->pStringManager,
                                                                   "*",
                                                                   1u,
                                                                   0);
                        ++file->pPrev;
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                          param.pV,
                          v179,
                          &_type,
                          (const Scaleform::GFx::ASString *)&file);
                        v182 = (Scaleform::GFx::ASStringNode *)file;
                      }
                      else
                      {
                        v183 = (Scaleform::GFx::ASStringNode *)v311.Obj.pObject;
                        v271.pNode = v311.Name.value.VS._1.VStr;
                        ++*(_DWORD *)(v311.Name.value.VS._1.VInt + 12);
                        v184 = param.pV;
                        v185 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(&v309, v183, &v271, qnfWithColons);
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v184, v179, &_type, v185);
                        v186 = v309.pNode;
                        --v309.pNode->RefCount;
                        if ( !v186->RefCount )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v186);
                        v182 = v271.pNode;
                      }
                      if ( !--v182->RefCount )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v182);
                      p_true = &_true;
                      if ( (unsigned int)v181 < v306 )
                        p_true = &_false;
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(param.pV, v179, &_optional, p_true);
                      Scaleform::GFx::AS3::Multiname::~Multiname(&v311);
                      f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
                      Scaleform::Formatter::~Formatter(&f);
                      v131 = _factory.pNode;
                      v271.pNode = v304;
                      if ( (unsigned int)v304 >= size )
                        goto LABEL_268;
                    }
LABEL_326:
                    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
                    Scaleform::Formatter::~Formatter(&f);
                    v224 = type.pNode;
                    --type.pNode->RefCount;
                    if ( !v224->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v224);
                    Scaleform::GFx::AS3::Value::~Value(&func);
LABEL_307:
                    v215 = (Scaleform::GFx::ASStringNode *)t;
                    --t->pPrev;
                    if ( !v215->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v215);
                    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
                    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
                    v216 = _name.pNode;
                    --_name.pNode->RefCount;
                    if ( !v216->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v216);
                    v217 = _uri.pNode;
                    --_uri.pNode->RefCount;
                    if ( !v217->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v217);
                    v218 = _returnType.pNode;
                    --_returnType.pNode->RefCount;
                    if ( !v218->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v218);
                    v219 = _var.pNode;
                    --_var.pNode->RefCount;
                    if ( !v219->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v219);
                    v220 = _const.pNode;
                    --_const.pNode->RefCount;
                    if ( !v220->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v220);
                    v221 = _declaredBy.pNode;
                    --_declaredBy.pNode->RefCount;
                    if ( !v221->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v221);
                    v222 = _method.pNode;
                    --_method.pNode->RefCount;
                    if ( !v222->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v222);
                    v223 = _accessor.pNode;
                    --_accessor.pNode->RefCount;
                    if ( !v223->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v223);
                    v81 = _access.pNode;
                    goto LABEL_352;
                  }
                }
LABEL_268:
                if ( name.pNode->HashFlags )
                  Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(
                    v294,
                    vm,
                    (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                    (const Scaleform::GFx::AS3::VMAbcFile *)i,
                    (const Scaleform::GFx::AS3::Abc::TraitInfo *)name.pNode->HashFlags);
              }
              else
              {
                p_type = &_returnType;
                if ( ((int)name.pNode->pData & 0x3E0) != 0x160 )
                  p_type = &_type;
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v131,
                  pns,
                  p_type,
                  &type);
                if ( ((int)name.pNode->pData & 0x3E0) == 0x160 )
                {
                  v189 = *(_DWORD *)(func.value.VS._1.VInt + 16);
                  if ( ((v189 >> 7) & 7) != 0 || (v189 & 0x3FFC00) != 0x3FFC00 )
                  {
                    v190 = (Scaleform::GFx::ASStringNode *)((v189 >> 10) & 0xFFF);
                    if ( v190 == (Scaleform::GFx::ASStringNode *)4095 )
                      v190 = (Scaleform::GFx::ASStringNode *)((*(_DWORD *)(func.value.VS._1.VInt + 16) >> 7) & 7);
                    v271.pNode = v190;
                    i = 0;
                    if ( v190 )
                    {
                      while ( 1 )
                      {
                        v191 = xml_itr;
                        size = i + 1;
                        Scaleform::LongFormatter::LongFormatter(&f, i + 1);
                        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                          v191,
                          &factory,
                          v191,
                          pns,
                          &_parameter,
                          0);
                        v192 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *))*((_DWORD *)v131->pData + 22);
                        *(_QWORD *)&v312.value.VNumber = __PAIR64__(
                                                           (unsigned int)v274.Bonus.pWeakProxy,
                                                           (unsigned int)factory.pV);
                        v312.Bonus.pWeakProxy = 0;
                        v312.Flags = 12;
                        v193 = *(_BYTE *)v192(v131, &result[3], &v312) == 0;
                        Scaleform::GFx::AS3::Value::~Value(&v312);
                        if ( v193 )
                          goto LABEL_326;
                        Scaleform::LongFormatter::Convert(&f);
                        v194 = (__m128i *)f.ValueStr;
                        v195 = vm->StringManagerRef;
                        v196 = Scaleform::LongFormatter::GetSize(&f);
                        v197 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                               v195->pStringManager,
                                                                               v194,
                                                                               v196);
                        v198 = pns;
                        mi = v197;
                        ++v197->ParamTypes.Data.Data;
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                          factory.pV,
                          v198,
                          &_index,
                          (const Scaleform::GFx::ASString *)&mi);
                        v199 = (Scaleform::GFx::ASStringNode *)mi;
                        --mi->ParamTypes.Data.Data;
                        if ( !v199->RefCount )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v199);
                        p_false = &_true;
                        if ( i < ((*(_DWORD *)(func.value.VS._1.VInt + 16) >> 7) & 7u) )
                          p_false = &_false;
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(factory.pV, v198, &_optional, p_false);
                        f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
                        Scaleform::Formatter::~Formatter(&f);
                        i = size;
                        if ( size >= (unsigned int)v271.pNode )
                          break;
                        v131 = _factory.pNode;
                      }
                    }
                  }
                }
              }
              v201 = type.pNode;
              --type.pNode->RefCount;
              if ( !v201->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v201);
              Scaleform::GFx::AS3::Value::~Value(&func);
            }
          }
          v214 = (Scaleform::GFx::ASStringNode *)t;
          --t->pPrev;
          if ( !v214->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v214);
        }
        if ( it.Ind.Index >= 0 )
          --it.Ind.Index;
      }
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
      v225 = _name.pNode;
      --_name.pNode->RefCount;
      if ( !v225->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v225);
      v226 = _uri.pNode;
      --_uri.pNode->RefCount;
      if ( !v226->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v226);
      v227 = _returnType.pNode;
      --_returnType.pNode->RefCount;
      if ( !v227->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v227);
      v228 = _var.pNode;
      --_var.pNode->RefCount;
      if ( !v228->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v228);
      v229 = _const.pNode;
      --_const.pNode->RefCount;
      if ( !v229->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v229);
      v230 = _declaredBy.pNode;
      --_declaredBy.pNode->RefCount;
      if ( !v230->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v230);
      v231 = _method.pNode;
      --_method.pNode->RefCount;
      if ( !v231->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v231);
      v232 = _accessor.pNode;
      --_accessor.pNode->RefCount;
      if ( !v232->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v232);
      v233 = _access.pNode;
      --_access.pNode->RefCount;
      if ( !v233->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v233);
      if ( (tr->Flags & 0x20) == 0 )
        goto LABEL_354;
      v234 = Scaleform::GFx::ASStringManager::CreateConstStringNode(sm->pStringManager, "factory", 7u, 0);
      v235 = pns;
      v236 = xml_itr;
      v249 = pns;
      v248 = xml_itr;
      _factory.pNode = v234;
      ++v234->RefCount;
      Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v236, &factory, v248, v249, &_factory, xml);
      v237 = xml->AppendChild;
      mn.Name.Flags = (unsigned int)factory.pV;
      mn.Name.Bonus.pWeakProxy = v274.Bonus.pWeakProxy;
      mn.Obj.pObject = 0;
      mn.Kind = 12;
      v238 = !v237(xml, &v286[3], (const Scaleform::GFx::AS3::Value *)&mn)->Result;
      Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&mn);
      if ( !v238 )
      {
        v239 = factory.pV;
        v240 = tr->GetQualifiedName(tr, &v300, 0);
        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v239, v235, &_type, v240);
        v241 = v300;
        --v300->RefCount;
        if ( !v241->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v241);
        Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
          v294,
          vm,
          factory.pV,
          (const Scaleform::GFx::AS3::Traits *)tr->Ns.pObject);
      }
      v81 = _factory.pNode;
LABEL_352:
      if ( !--v81->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v81);
LABEL_354:
      v242 = _index.pNode;
      --_index.pNode->RefCount;
      if ( !v242->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v242);
      v243 = _parameter.pNode;
      --_parameter.pNode->RefCount;
      if ( !v243->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v243);
      v244 = _optional.pNode;
      --_optional.pNode->RefCount;
      if ( !v244->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v244);
      v245 = _type.pNode;
      --_type.pNode->RefCount;
      if ( !v245->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v245);
      v246 = _false.pNode;
      --_false.pNode->RefCount;
      if ( !v246->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v246);
      v247 = _true.pNode;
      --_true.pNode->RefCount;
      v21 = v247;
      v22 = v247->RefCount == 0;
      goto LABEL_365;
    }
    v73 = (unsigned int)v72 - v71->OptionalParams.Data.Size;
    v74 = StringManagerRef->pStringManager;
    first_opt_param_num = v73;
    v75 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v74, "constructor", 0xBu, 0);
    v76 = xml_itr;
    _method.pNode = v75;
    ++v75->RefCount;
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v76, &factory, v76, pns, &_method, 0);
    v77 = xml->AppendChild;
    *(_QWORD *)&func.value.VNumber = __PAIR64__((unsigned int)v274.Bonus.pWeakProxy, (unsigned int)factory.pV);
    func.Bonus.pWeakProxy = 0;
    func.Flags = 12;
    v78 = !v77(xml, (Scaleform::GFx::AS3::CheckResult *)&v262 + 3, &func)->Result;
    if ( (func.Flags & 0x1F) > 9 )
    {
      if ( (func.Flags & 0x200) != 0 )
      {
        v79 = func.Bonus.pWeakProxy;
        --func.Bonus.pWeakProxy->RefCount;
        if ( !v79->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v79);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
      }
    }
    if ( v78 )
    {
      v81 = _method.pNode;
      goto LABEL_352;
    }
    _accessor.pNode = 0;
    while ( 1 )
    {
      Scaleform::GFx::AS3::Multiname::Multiname(
        &mn,
        file,
        &file->File.pObject->Const_Pool.const_multiname.Data.Data[mi->ParamTypes.Data.Data[(int)_accessor.pNode]]);
      v82 = mn.Name.Flags & 0x1F;
      CTr = mn.Name.value.VS._1.CTr;
      if ( (mn.Name.Flags & 0x1F) == 0 || (unsigned int)(v82 - 12) <= 3 && !mn.Name.value.VS._1.VInt )
        break;
      v84 = v256;
      if ( v82 == 10 )
      {
        ++*(_DWORD *)(mn.Name.value.VS._1.VInt + 12);
        v84 |= 0x100u;
        v22 = CTr->FirstOwnSlotNum == 0;
        val = CTr;
        if ( v22 )
          goto LABEL_127;
      }
      HIBYTE(v252) = 0;
LABEL_128:
      if ( (v84 & 0x100) != 0 )
      {
        v85 = (Scaleform::GFx::ASStringNode *)val;
        v84 &= ~0x100u;
        v22 = val->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v85);
      }
      if ( HIBYTE(v252) )
      {
        v86 = sm->pStringManager;
        v87 = v84 | 1;
        v256 = v87;
        v88 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v86, "*", 1u, 0);
        ++v88->RefCount;
        _declaredBy.pNode = v88;
        p_declaredBy = (Scaleform::GFx::ASStringNode **)&_declaredBy;
      }
      else
      {
        v90 = mn.Obj.pObject;
        _const.pNode = (Scaleform::GFx::ASStringNode *)CTr;
        ++CTr->pPrev;
        v91 = v90[1].pNext;
        v92 = (Scaleform::GFx::ASString *)&v90[1].8;
        v87 = v84 | 6;
        v22 = v91[1].__vftable == 0;
        v256 = v87;
        if ( v22 )
        {
          param.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)_const.pNode;
          ++_const.pNode->RefCount;
        }
        else
        {
          v93 = Scaleform::GFx::ASString::operator+(v92, &v289, (const __m128i *)"::");
          Scaleform::GFx::ASString::operator+(v93, (Scaleform::GFx::ASString *)&param, &_const);
          v94 = v289.pNode;
          --v289.pNode->RefCount;
          if ( !v94->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v94);
        }
        v88 = _declaredBy.pNode;
        p_declaredBy = (Scaleform::GFx::ASStringNode **)&param;
      }
      _var.pNode = *p_declaredBy;
      ++_var.pNode->RefCount;
      if ( (v87 & 4) != 0 )
      {
        v95 = (Scaleform::GFx::ASStringNode *)param.pV;
        --param.pV->pPrev;
        v87 &= ~4u;
        v22 = v95->RefCount == 0;
        v256 = v87;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v95);
      }
      if ( (v87 & 2) != 0 )
      {
        v96 = _const.pNode;
        --_const.pNode->RefCount;
        v87 &= ~2u;
        v22 = v96->RefCount == 0;
        v256 = v87;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v96);
      }
      if ( (v87 & 1) != 0 )
      {
        v22 = v88->RefCount-- == 1;
        v256 = v87 & 0xFFFFFFFE;
        if ( v22 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v88);
      }
      v97 = (Scaleform::GFx::ASStringNode *)((char *)&_accessor.pNode->pData + 1);
      Scaleform::LongFormatter::LongFormatter(&f, (unsigned int)&_accessor.pNode->pData + 1);
      Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
        xml_itr,
        (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&_access,
        xml_itr,
        pns,
        &_parameter,
        0);
      *(_QWORD *)&v274.value.VNumber = (unsigned int)_access.pNode;
      v274.Bonus.pWeakProxy = 0;
      v274.Flags = 12;
      HIBYTE(v252) = !factory.pV->AppendChild(factory.pV, (char *)&v262 + 3, &v274)->Result;
      if ( (v274.Flags & 0x1F) > 9 )
      {
        if ( (v274.Flags & 0x200) != 0 )
        {
          v98 = v274.Bonus.pWeakProxy;
          --v274.Bonus.pWeakProxy->RefCount;
          if ( !v98->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v98);
          memset(&v274.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v274);
        }
      }
      if ( HIBYTE(v252) )
      {
        f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Formatter::~Formatter(&f);
        v111 = _var.pNode;
        --_var.pNode->RefCount;
        if ( !v111->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v111);
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        pV = _method.pNode;
        goto LABEL_19;
      }
      Scaleform::LongFormatter::Convert(&f);
      v99 = vm->StringManagerRef;
      v100 = (__m128i *)f.ValueStr;
      v101 = Scaleform::LongFormatter::GetSize(&f);
      v102 = Scaleform::GFx::ASStringManager::CreateStringNode(v99->pStringManager, v100, v101);
      v103 = pns;
      _factory.pNode = v102;
      ++v102->RefCount;
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
        (Scaleform::GFx::AS3::Instances::fl::XMLElement *)_access.pNode,
        v103,
        &_index,
        &_factory);
      v104 = _factory.pNode;
      --_factory.pNode->RefCount;
      if ( !v104->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v104);
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
        (Scaleform::GFx::AS3::Instances::fl::XMLElement *)_access.pNode,
        v103,
        &_type,
        &_var);
      v105 = &_true;
      if ( (unsigned int)_accessor.pNode < first_opt_param_num )
        v105 = &_false;
      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
        (Scaleform::GFx::AS3::Instances::fl::XMLElement *)_access.pNode,
        v103,
        &_optional,
        v105);
      f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
      Scaleform::Formatter::~Formatter(&f);
      v106 = _var.pNode;
      --_var.pNode->RefCount;
      if ( !v106->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v106);
      Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
      _accessor.pNode = v97;
      if ( v97 >= _access_name.pNode )
      {
        StringManagerRef = sm;
        v107 = _method.pNode;
        --_method.pNode->RefCount;
        if ( !v107->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v107);
        goto LABEL_163;
      }
    }
    v84 = v256;
LABEL_127:
    HIBYTE(v252) = 1;
    goto LABEL_128;
  }
  _access.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                    StringManagerRef->pStringManager,
                    "implementsInterface",
                    0x13u,
                    0);
  ++_access.pNode->RefCount;
  MHeap = vm->MHeap;
  name.pNode = &StringManagerRef->pStringManager->EmptyStringNode;
  handled.Entries.mHash.pTable = 0;
  handled.Entries.mHash.pHeap = MHeap;
  ++name.pNode->RefCount;
  v24 = tr;
  t = tr;
  while ( (v24->Flags & 0x10) == 0 )
  {
    mi = (const Scaleform::GFx::AS3::Abc::MethodInfo *)v24->class_info;
    i = 0;
    if ( mi )
    {
      param.pV = 0;
      while ( 1 )
      {
        if ( Scaleform::GFx::AS3::Value::Convert2String(
               (Scaleform::GFx::AS3::Value *)((char *)&param.pV->8 + (unsigned int)v24->Script.pObject),
               &v286[2],
               &name)->Result )
        {
          pTable = handled.Entries.mHash.pTable;
          if ( !handled.Entries.mHash.pTable )
            goto LABEL_83;
          v50 = 4;
          v51 = 5381;
          do
          {
            v52 = *((unsigned __int8 *)&v252 + v50-- + 3);
            v51 = v52 + 65599 * v51;
          }
          while ( v50 );
          v53 = Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::findIndexCore<Scaleform::GFx::ASString>(
                  (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
                  &name,
                  v51 & handled.Entries.mHash.pTable->SizeMask);
          if ( v53 < 0
            || (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)pTable + 12 * v53) == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)-16 )
          {
LABEL_83:
            v54 = 4;
            v55 = 5381;
            do
            {
              v56 = *((unsigned __int8 *)&v252 + v54-- + 3);
              v55 = v56 + 65599 * v55;
            }
            while ( v54 );
            Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
              (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
              handled.Entries.mHash.pHeap,
              &name,
              v55);
            Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
              xml_itr,
              (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&_factory,
              xml_itr,
              pns,
              &_access,
              0);
            v57 = xml->AppendChild;
            *(_QWORD *)&v299.value.VNumber = __PAIR64__(
                                               (unsigned int)v274.Bonus.pWeakProxy,
                                               (unsigned int)_factory.pNode);
            v299.Bonus.pWeakProxy = 0;
            v299.Flags = 12;
            v58 = !v57(xml, (Scaleform::GFx::AS3::CheckResult *)&v262 + 3, &v299)->Result;
            if ( (v299.Flags & 0x1F) > 9 )
            {
              if ( (v299.Flags & 0x200) != 0 )
              {
                v59 = v299.Bonus.pWeakProxy;
                --v299.Bonus.pWeakProxy->RefCount;
                if ( !v59->RefCount )
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v59);
                memset(&v299.Bonus, 0, 12);
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&v299);
              }
            }
            if ( v58 )
              goto LABEL_113;
            v60 = *(Scaleform::GFx::ASString **)((char *)&param.pV->_pRCC + (unsigned int)t[1].pNext);
            v61 = v60[7].pNode;
            v62 = v60 + 7;
            if ( v61->Size )
            {
              v63 = Scaleform::GFx::ASString::operator+(v62, &_access_name, (const __m128i *)"::");
              Scaleform::GFx::ASString::operator+(v63, &_method, &name);
              v64 = _access_name.pNode;
              --_access_name.pNode->RefCount;
              if ( !v64->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v64);
            }
            else
            {
              _method.pNode = name.pNode;
              ++name.pNode->RefCount;
            }
            Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
              (Scaleform::GFx::AS3::Instances::fl::XMLElement *)_factory.pNode,
              pns,
              &_type,
              &_method);
            v65 = _method.pNode;
            --_method.pNode->RefCount;
            if ( !v65->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v65);
          }
        }
        param.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)param.pV + 24);
        if ( ++i >= (unsigned int)mi )
          goto LABEL_99;
        v24 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t;
      }
    }
LABEL_100:
    v24 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)v24->pParent.pObject;
    t = v24;
    if ( !v24 )
    {
      v66 = name.pNode;
      --name.pNode->RefCount;
      if ( !v66->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v66);
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled);
      v67 = _access.pNode;
      --_access.pNode->RefCount;
      if ( !v67->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v67);
      goto LABEL_105;
    }
  }
  mi = (const Scaleform::GFx::AS3::Abc::MethodInfo *)&t[1].pPrev[1].12;
  v25 = mi;
  v26 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t);
  RetTypeInd = v25->RetTypeInd;
  file = (Scaleform::GFx::AS3::VMAbcFile *)&v26->File.pObject->Const_Pool;
  first_opt_param_num = RetTypeInd;
  param.pV = 0;
  if ( !RetTypeInd )
  {
LABEL_99:
    v24 = (Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t;
    goto LABEL_100;
  }
  while ( 1 )
  {
    v250 = (Scaleform::GFx::AS3::Abc::Multiname *)&file->GlobalObjects.pTable[2
                                                                            * *(_DWORD *)(*(_DWORD *)&mi->Flags
                                                                                        + 4 * (int)param.pV)];
    v28 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t);
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, v28, v250);
    if ( Scaleform::GFx::AS3::Value::Convert2String(&mn.Name, &result[3], &name)->Result )
    {
      v29 = handled.Entries.mHash.pTable;
      if ( !handled.Entries.mHash.pTable )
        break;
      v30 = 4;
      v31 = 5381;
      do
      {
        v32 = *((unsigned __int8 *)&v252 + v30-- + 3);
        v31 = v32 + 65599 * v31;
      }
      while ( v30 );
      v33 = Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::findIndexCore<Scaleform::GFx::ASString>(
              (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
              &name,
              v31 & handled.Entries.mHash.pTable->SizeMask);
      if ( v33 < 0
        || (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)v29 + 12 * v33) == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)-16 )
      {
        break;
      }
    }
LABEL_72:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    if ( (unsigned int)++param.pV >= first_opt_param_num )
      goto LABEL_99;
  }
  v34 = 4;
  v35 = 5381;
  do
  {
    v36 = *((unsigned __int8 *)&v252 + v34-- + 3);
    v35 = v36 + 65599 * v35;
  }
  while ( v34 );
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
    (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
    handled.Entries.mHash.pHeap,
    &name,
    v35);
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(xml_itr, &factory, xml_itr, pns, &_access, 0);
  v37 = xml->AppendChild;
  *(_QWORD *)&v274.value.VNumber = (unsigned int)factory.pV;
  v274.Bonus.pWeakProxy = 0;
  v274.Flags = 12;
  v38 = !v37(xml, (Scaleform::GFx::AS3::CheckResult *)&v252 + 3, &v274)->Result;
  if ( (v274.Flags & 0x1F) > 9 )
  {
    if ( (v274.Flags & 0x200) != 0 )
    {
      v39 = v274.Bonus.pWeakProxy;
      --v274.Bonus.pWeakProxy->RefCount;
      if ( !v39->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v39);
      memset(&v274.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v274);
    }
  }
  if ( !v38 )
  {
    if ( (mn.Kind & 3) == 0 || (mn.Kind & 3) == 1 )
    {
      v40 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)mn.Obj.pObject;
      goto LABEL_64;
    }
    v41 = 0;
    val = (Scaleform::GFx::AS3::ClassTraits::Traits *)mn.Obj.pObject[1]._pRCC;
    if ( !val )
      goto LABEL_65;
    while ( 1 )
    {
      if ( (v40 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*((_DWORD *)&mn.Obj.pObject[1].ForEachChild_GC + v41),
            AppDomain = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t)->AppDomain,
            (ParentDomain = AppDomain->ParentDomain) != 0)
        && (ClassTrait = Scaleform::GFx::AS3::VMAppDomain::GetClassTrait(ParentDomain, &name, v40)) != 0
        || (ClassTrait = Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Get(
                           &AppDomain->ClassTraitsSet,
                           &name,
                           v40)) != 0 )
      {
        if ( *ClassTrait )
          break;
      }
      ClassTraits = Scaleform::GFx::AS3::Instances::fl::GlobalObjectCPP::GetClassTraits(
                      vm->GlobalObject.pObject,
                      &name,
                      v40);
      if ( ClassTraits )
      {
        val = (Scaleform::GFx::AS3::ClassTraits::Traits *)ClassTraits;
        Scaleform::GFx::AS3::MultinameHash<Scaleform::GFx::AS3::ClassTraits::Traits *,329>::Add(
          &vm->SystemDomain->ClassTraitsSet,
          &name,
          v40,
          &val);
        break;
      }
      if ( ++v41 >= (unsigned int)val )
        goto LABEL_65;
    }
    StringManagerRef = sm;
LABEL_64:
    if ( !v40 )
    {
LABEL_65:
      v40 = pns;
      StringManagerRef = sm;
    }
    if ( v40->Uri.pNode->Size )
    {
      v46 = Scaleform::GFx::ASString::operator+(&v40->Uri, &v289, (const __m128i *)"::");
      Scaleform::GFx::ASString::operator+(v46, &_accessor, &name);
      v47 = v289.pNode;
      --v289.pNode->RefCount;
      if ( !v47->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v47);
    }
    else
    {
      _accessor.pNode = name.pNode;
      ++name.pNode->RefCount;
    }
    Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(factory.pV, pns, &_type, &_accessor);
    v48 = _accessor.pNode;
    --_accessor.pNode->RefCount;
    if ( !v48->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v48);
    goto LABEL_72;
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
LABEL_113:
  v80 = name.pNode;
  --name.pNode->RefCount;
  if ( !v80->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v80);
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled);
  pV = _access.pNode;
LABEL_19:
  if ( !--pV->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pV);
  v15 = _index.pNode;
  --_index.pNode->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v16 = _parameter.pNode;
  --_parameter.pNode->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  v17 = _optional.pNode;
  --_optional.pNode->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  v18 = _type.pNode;
  --_type.pNode->RefCount;
  if ( !v18->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = _false.pNode;
  --_false.pNode->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  v20 = _true.pNode;
  --_true.pNode->RefCount;
  v21 = v20;
  v22 = v20->RefCount == 0;
LABEL_365:
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}
