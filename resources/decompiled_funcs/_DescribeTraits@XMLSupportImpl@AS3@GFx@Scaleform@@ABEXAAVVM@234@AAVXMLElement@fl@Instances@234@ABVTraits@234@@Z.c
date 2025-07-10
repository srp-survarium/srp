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
  Scaleform::MemoryHeap *MHeap; // ecx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v16; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v17; // eax
  unsigned int RetTypeInd; // ebx
  Scaleform::GFx::AS3::VMAbcFile *v19; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *v20; // ebx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  int v24; // eax
  int v25; // ecx
  unsigned int v26; // eax
  int v27; // edx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v28)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v29; // bl
  Scaleform::GFx::AS3::WeakProxy *v30; // eax
  Scaleform::GFx::ASStringNode *pV; // eax
  Scaleform::GFx::ASStringNode *v32; // eax
  Scaleform::GFx::ASStringNode *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::ASStringNode *v38; // ecx
  bool v39; // zf
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
  int v52; // eax
  int v53; // ecx
  unsigned int v54; // eax
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v55)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v56; // bl
  Scaleform::GFx::AS3::WeakProxy *v57; // eax
  Scaleform::GFx::ASString *v58; // ecx
  Scaleform::GFx::ASStringNode *v59; // edx
  Scaleform::GFx::ASString *v60; // ecx
  Scaleform::GFx::ASString *v61; // eax
  Scaleform::GFx::ASStringNode *v62; // eax
  Scaleform::GFx::ASStringNode *v63; // eax
  Scaleform::GFx::ASStringNode *v64; // eax
  Scaleform::GFx::ASStringNode *v65; // eax
  Scaleform::GFx::ASStringNode *v66; // eax
  Scaleform::GFx::ASStringNode *v67; // eax
  Scaleform::GFx::ASStringNode *v68; // eax
  int Flags; // eax
  Scaleform::GFx::AS3::VMAbcFile *v70; // eax
  int method_info_ind; // ecx
  Scaleform::GFx::AS3::Abc::File *v72; // edx
  const Scaleform::GFx::AS3::Abc::MethodInfo *v73; // ecx
  Scaleform::GFx::ASStringNode *v74; // ebx
  unsigned int v75; // eax
  Scaleform::GFx::ASStringManager *v76; // ecx
  Scaleform::GFx::ASStringNode *v77; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v78; // edx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v79; // ecx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v80)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::WeakProxy *v81; // eax
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
  char *v100; // esi
  unsigned int v101; // eax
  Scaleform::GFx::ASStringNode *v102; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v103; // esi
  Scaleform::GFx::ASStringNode *v104; // eax
  Scaleform::GFx::ASString *v105; // eax
  Scaleform::GFx::ASStringNode *v106; // eax
  Scaleform::GFx::ASStringNode *v107; // eax
  int v108; // eax
  Scaleform::GFx::AS3::Slots *v109; // edx
  Scaleform::GFx::AS3::SlotInfo *p_Value; // eax
  Scaleform::GFx::ASStringNode *v111; // eax
  const Scaleform::GFx::AS3::Instances::fl::Namespace *v112; // eax
  unsigned int FirstOwnSlotNum; // edx
  Scaleform::GFx::ASStringNode *SlotNameNode; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  const Scaleform::GFx::AS3::Traits *v116; // eax
  Scaleform::GFx::ASStringManager *pManager; // ebx
  $6995B294EB399C8E7199C0A182ACF77B *v118; // esi
  Scaleform::GFx::ASStringNode *v119; // edi
  int v120; // eax
  char *v121; // eax
  unsigned int pFreeStringNodes; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v123; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *v124; // edx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pNext; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v127; // ecx
  Scaleform::GFx::ASStringNode *v128; // eax
  Scaleform::GFx::ASStringNode *v129; // edi
  Scaleform::GFx::ASString *p_method; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v131; // ebx
  Scaleform::GFx::ASStringNode *v132; // esi
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v133)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::AS3::WeakProxy *v134; // eax
  char *v135; // edx
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v137; // eax
  Scaleform::GFx::ASStringManager *v138; // eax
  Scaleform::GFx::ASStringManager::TextPage *pTextBufferPages; // ecx
  const Scaleform::GFx::ASString *p_pTextBufferPages; // eax
  Scaleform::GFx::AS3::VTable *VT; // eax
  Scaleform::GFx::AS3::Traits_vtbl *v142; // edx
  Scaleform::GFx::AS3::VMAppDomain *v143; // eax
  const Scaleform::GFx::AS3::InstanceTraits::Traits *FunctReturnType; // ebx
  Scaleform::GFx::ASStringManager *v145; // ecx
  int v146; // ebx
  Scaleform::GFx::ASStringNode *v147; // edi
  unsigned int *p_first_opt_param_num; // eax
  Scaleform::GFx::ASString *(__thiscall *GetQualifiedName)(struct Scaleform::GFx::AS3::InstanceTraits::Traits *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Traits::QNameFormat); // edx
  Scaleform::GFx::ASStringNode *v150; // eax
  Scaleform::GFx::AS3::VTable *v151; // eax
  const Scaleform::GFx::AS3::Value *v152; // ecx
  int VInt; // eax
  Scaleform::GFx::AS3::Value::V2U v154; // edi
  Scaleform::GFx::AS3::Object_vtbl *v155; // edx
  unsigned int v156; // eax
  int v157; // ebx
  Scaleform::GFx::ASString *QualifiedName; // eax
  Scaleform::GFx::ASStringNode *Ind; // edx
  Scaleform::GFx::ASStringNode *v160; // eax
  Scaleform::GFx::ASStringNode *v161; // eax
  Scaleform::GFx::ASStringNode *v162; // eax
  Scaleform::GFx::ASStringNode *v163; // eax
  Scaleform::GFx::ASString *p_returnType; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v165; // ebx
  const Scaleform::GFx::ASString *v166; // eax
  Scaleform::GFx::ASStringNode *v167; // eax
  Scaleform::GFx::AS3::Value::V1U v168; // ebx
  void (__thiscall *v169)(struct Scaleform::GFx::AS3::VMFile *); // ecx
  const Scaleform::GFx::AS3::Value *v170; // eax
  unsigned int v171; // ecx
  unsigned int v172; // edx
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v173; // edi
  int (__thiscall *v174)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *); // eax
  bool v175; // bl
  Scaleform::GFx::AS3::StringManager *v176; // edi
  char *ValueStr; // esi
  unsigned int v178; // eax
  Scaleform::GFx::AS3::ClassTraits::Traits *StringNode; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v180; // esi
  Scaleform::GFx::ASStringNode *v181; // eax
  Scaleform::GFx::ASStringNode *v182; // ebx
  Scaleform::GFx::ASStringNode *v183; // eax
  Scaleform::GFx::ASStringNode *v184; // ecx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v185; // edi
  Scaleform::GFx::ASString *v186; // eax
  Scaleform::GFx::ASStringNode *v187; // eax
  Scaleform::GFx::ASString *p_true; // eax
  Scaleform::GFx::ASString *p_type; // eax
  unsigned int v190; // eax
  Scaleform::GFx::ASStringNode *v191; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v192; // edi
  int (__thiscall *v193)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *); // edx
  bool v194; // bl
  char *v195; // esi
  Scaleform::GFx::AS3::StringManager *v196; // edi
  unsigned int v197; // eax
  const Scaleform::GFx::AS3::Abc::MethodInfo *v198; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v199; // esi
  Scaleform::GFx::ASStringNode *v200; // eax
  Scaleform::GFx::ASString *p_false; // eax
  Scaleform::GFx::ASStringNode *v202; // eax
  _BYTE *HashFlags; // eax
  Scaleform::GFx::ASString *p_const; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v205; // ebx
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v206; // esi
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v207)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  Scaleform::GFx::ASStringNode *v208; // edi
  const Scaleform::GFx::AS3::ClassTraits::Traits *DataType; // eax
  const Scaleform::GFx::ASString *v210; // eax
  Scaleform::GFx::ASStringNode *v211; // eax
  const Scaleform::GFx::ASString *v212; // eax
  Scaleform::GFx::ASStringNode *v213; // ecx
  const Scaleform::GFx::ASString *v214; // eax
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
  Scaleform::GFx::ASStringNode *v235; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *v236; // edi
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v237; // ecx
  Scaleform::GFx::AS3::CheckResult *(__thiscall *v238)(struct Scaleform::GFx::AS3::Instances::fl::XMLElement *, Scaleform::GFx::AS3::CheckResult *, const Scaleform::GFx::AS3::Value *); // edx
  bool v239; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLElement *v240; // ebx
  const Scaleform::GFx::ASString *v241; // eax
  Scaleform::GFx::ASStringNode *v242; // eax
  Scaleform::GFx::ASStringNode *v243; // eax
  Scaleform::GFx::ASStringNode *v244; // eax
  Scaleform::GFx::ASStringNode *v245; // eax
  Scaleform::GFx::ASStringNode *v246; // eax
  Scaleform::GFx::ASStringNode *v247; // eax
  Scaleform::GFx::ASStringNode *v248; // eax
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *v249; // [esp+20h] [ebp-1F0h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v250; // [esp+24h] [ebp-1ECh]
  Scaleform::GFx::AS3::Abc::Multiname *v251; // [esp+2Ch] [ebp-1E4h]
  int v252; // [esp+2Ch] [ebp-1E4h]
  int v253; // [esp+3Ch] [ebp-1D4h] BYREF
  Scaleform::GFx::ASString name; // [esp+40h] [ebp-1D0h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> param; // [esp+44h] [ebp-1CCh] BYREF
  Scaleform::GFx::AS3::Instances::fl::Namespace *pns; // [esp+48h] [ebp-1C8h]
  unsigned int v257; // [esp+4Ch] [ebp-1C4h]
  Scaleform::GFx::ASString _type; // [esp+50h] [ebp-1C0h] BYREF
  const Scaleform::GFx::AS3::Traits *t; // [esp+54h] [ebp-1BCh] BYREF
  Scaleform::GFx::ASString _access; // [esp+58h] [ebp-1B8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> factory; // [esp+5Ch] [ebp-1B4h] BYREF
  Scaleform::GFx::ASString _factory; // [esp+60h] [ebp-1B0h] BYREF
  int v263; // [esp+64h] [ebp-1ACh] BYREF
  Scaleform::GFx::ASString _method; // [esp+68h] [ebp-1A8h] BYREF
  Scaleform::GFx::ASString _accessor; // [esp+6Ch] [ebp-1A4h] BYREF
  Scaleform::GFx::AS3::MultinameHash<bool,2> handled; // [esp+70h] [ebp-1A0h] BYREF
  Scaleform::GFx::ASString _true; // [esp+78h] [ebp-198h] BYREF
  Scaleform::GFx::ASString _false; // [esp+7Ch] [ebp-194h] BYREF
  Scaleform::GFx::ASString _index; // [esp+80h] [ebp-190h] BYREF
  Scaleform::GFx::ASString _parameter; // [esp+84h] [ebp-18Ch] BYREF
  Scaleform::GFx::ASString _optional; // [esp+88h] [ebp-188h] BYREF
  Scaleform::GFx::ASString v272; // [esp+8Ch] [ebp-184h] BYREF
  unsigned int i; // [esp+90h] [ebp-180h]
  Scaleform::GFx::AS3::InstanceTraits::fl::XML *xml_itr; // [esp+94h] [ebp-17Ch]
  Scaleform::GFx::AS3::Value v275; // [esp+98h] [ebp-178h] BYREF
  Scaleform::GFx::AS3::CheckResult result[4]; // [esp+ACh] [ebp-164h] BYREF
  Scaleform::GFx::ASString _var; // [esp+B0h] [ebp-160h] BYREF
  Scaleform::GFx::ASString _const; // [esp+B4h] [ebp-15Ch] BYREF
  Scaleform::GFx::ASString _declaredBy; // [esp+B8h] [ebp-158h] BYREF
  const Scaleform::GFx::AS3::Abc::MethodInfo *mi; // [esp+BCh] [ebp-154h] BYREF
  Scaleform::GFx::AS3::StringManager *sm; // [esp+C0h] [ebp-150h]
  Scaleform::GFx::AS3::ClassTraits::Traits *val; // [esp+C4h] [ebp-14Ch] BYREF
  Scaleform::GFx::ASString _returnType; // [esp+C8h] [ebp-148h] BYREF
  Scaleform::GFx::ASString _name; // [esp+CCh] [ebp-144h] BYREF
  Scaleform::GFx::ASString type; // [esp+D0h] [ebp-140h] BYREF
  Scaleform::GFx::ASString _uri; // [esp+D4h] [ebp-13Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v287[4]; // [esp+D8h] [ebp-138h] BYREF
  Scaleform::GFx::ASString _access_name; // [esp+DCh] [ebp-134h] BYREF
  unsigned int first_opt_param_num; // [esp+E0h] [ebp-130h] BYREF
  Scaleform::GFx::ASString v290; // [esp+E4h] [ebp-12Ch] BYREF
  Scaleform::GFx::AS3::VMAbcFile *file; // [esp+E8h] [ebp-128h] BYREF
  Scaleform::GFx::AS3::Abc::MiInd method_ind; // [esp+ECh] [ebp-124h]
  Scaleform::GFx::AS3::Value func; // [esp+F0h] [ebp-120h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [esp+100h] [ebp-110h] BYREF
  Scaleform::GFx::AS3::XMLSupportImpl *v295; // [esp+11Ch] [ebp-F4h]
  Scaleform::GFx::ASStringNode *v296; // [esp+120h] [ebp-F0h] BYREF
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v297; // [esp+124h] [ebp-ECh]
  const Scaleform::GFx::AS3::Value *real_func; // [esp+128h] [ebp-E8h]
  unsigned int size; // [esp+12Ch] [ebp-E4h]
  Scaleform::GFx::AS3::Value v300; // [esp+130h] [ebp-E0h] BYREF
  Scaleform::GFx::ASStringNode *v301; // [esp+144h] [ebp-CCh] BYREF
  Scaleform::GFx::AS3::Slots::CIterator it; // [esp+148h] [ebp-C8h]
  Scaleform::GFx::AS3::Value v303; // [esp+150h] [ebp-C0h] BYREF
  Scaleform::GFx::ASString v304; // [esp+160h] [ebp-B0h] BYREF
  Scaleform::GFx::ASStringNode *v305; // [esp+164h] [ebp-ACh]
  Scaleform::GFx::ASStringNode *v306; // [esp+168h] [ebp-A8h] BYREF
  unsigned int v307; // [esp+16Ch] [ebp-A4h]
  Scaleform::GFx::ASStringNode *v308; // [esp+170h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::VMFile *v309; // [esp+174h] [ebp-9Ch]
  Scaleform::GFx::ASString v310; // [esp+178h] [ebp-98h] BYREF
  Scaleform::GFx::ASString v311; // [esp+17Ch] [ebp-94h] BYREF
  Scaleform::GFx::AS3::Multiname v312; // [esp+180h] [ebp-90h] BYREF
  Scaleform::GFx::AS3::Value v313; // [esp+198h] [ebp-78h] BYREF
  Scaleform::GFx::AS3::Value v314; // [esp+1A8h] [ebp-68h] BYREF
  Scaleform::LongFormatter f; // [esp+1B8h] [ebp-58h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v316; // [esp+208h] [ebp-8h] BYREF
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> v317; // [esp+20Ch] [ebp-4h] BYREF

  StringManagerRef = vm->StringManagerRef;
  pns = vm->PublicNamespace.pObject;
  _true.pNode = StringManagerRef->Builtins[4].pNode;
  ++_true.pNode->RefCount;
  _false.pNode = StringManagerRef->Builtins[5].pNode;
  ++_false.pNode->RefCount;
  pStringManager = StringManagerRef->pStringManager;
  v295 = this;
  v257 = 0;
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
                   (char *)&stru_962594.m_gs_ids,
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
      AppendChild = xml->AppendChild;
      *(_QWORD *)&v275.value.VNumber = (unsigned int)factory.pV;
      v275.Bonus.pWeakProxy = 0;
      v275.Flags = 12;
      HIBYTE(v253) = !AppendChild(xml, &result[3], &v275)->Result;
      if ( (v275.Flags & 0x1F) > 9 )
      {
        if ( (v275.Flags & 0x200) != 0 )
        {
          pWeakProxy = v275.Bonus.pWeakProxy;
          --v275.Bonus.pWeakProxy->RefCount;
          if ( !pWeakProxy->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
          memset(&v275.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v275);
        }
      }
      if ( HIBYTE(v253) )
      {
        pV = (Scaleform::GFx::ASStringNode *)param.pV;
        goto LABEL_36;
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
LABEL_109:
    Flags = tr->Flags;
    if ( (Flags & 0x10) == 0 )
      goto LABEL_163;
    if ( (Flags & 0x20) != 0 )
      goto LABEL_163;
    v70 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile(tr);
    method_info_ind = tr->class_info->inst_info.method_info_ind;
    v72 = v70->File.pObject;
    file = v70;
    v73 = v72->Methods.Info.Data.Data[method_info_ind];
    v74 = (Scaleform::GFx::ASStringNode *)v73->ParamTypes.Data.Size;
    mi = v73;
    _access_name.pNode = v74;
    if ( !v74 )
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
          v300.Flags = (unsigned int)v116;
          v300.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pManager;
          if ( pManager )
            pManager->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)(((int)&pManager->pFreeStringNodes->pData + 1)
                                                                        & 0x8FBFFFFF);
          if ( handled.Entries.mHash.pTable
            && (v120 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key>(
                         &handled.Entries.mHash,
                         (const Scaleform::GFx::AS3::MultinameHash<bool,2>::Key *)&v300,
                         handled.Entries.mHash.pTable->SizeMask
                       & ((unsigned int)&vostok::memory::s_CRT_arena[5574199]
                        & v116->RefCount
                        ^ (4
                         * ((unsigned int)&vostok::memory::s_CRT_arena[5574199]
                          & *(_DWORD *)&pManager->pTextBufferPages->Entries[1].Buff[4]))
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
              v300.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)((char *)&pManager[-1].FileName.HeapTypeBits + 3);
            }
            else
            {
              pFreeStringNodes = (unsigned int)pManager->pFreeStringNodes;
              if ( ((unsigned int)&byte_3FFFFF & pFreeStringNodes) != 0 )
              {
                pManager->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)(pFreeStringNodes - 1);
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pManager);
              }
            }
          }
          v39 = v118->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
          if ( v39 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v119);
          if ( !_factory.pNode )
          {
            v123 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)name.pNode->pManager;
            HIBYTE(v253) = 1;
            v296 = (Scaleform::GFx::ASStringNode *)t;
            ++t->pPrev;
            v297 = v123;
            if ( v123 )
            {
              v123->RefCount = (v123->RefCount + 1) & 0x8FBFFFFF;
              v123 = v297;
            }
            v275.Flags = (unsigned int)&v296;
            v124 = v123[1].__vftable;
            pNext = v123[1].pNext;
            v275.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)((char *)&v253 + 3);
            Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef>(
              &handled.Entries.mHash,
              handled.Entries.mHash.pHeap,
              (const Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeRef *)&v275,
              (unsigned int)&vostok::memory::s_CRT_arena[5574199]
            & v296->HashFlags
            ^ (4 * ((unsigned int)&vostok::memory::s_CRT_arena[5574199] & pNext->RefCount))
            ^ ((int)((_DWORD)v124 << 28) >> 28));
            if ( v297 )
            {
              if ( ((unsigned __int8)v297 & 1) != 0 )
              {
                v297 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v297 - 1);
              }
              else
              {
                RefCount = v297->RefCount;
                if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
                {
                  v127 = v297;
                  v297->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v127);
                }
              }
            }
            v128 = v296;
            --v296->RefCount;
            if ( !v128->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v128);
            v272.pNode = (Scaleform::GFx::ASStringNode *)((int)name.pNode->pData << 22 >> 27);
            v129 = v272.pNode;
            if ( (int)v272.pNode <= 10 )
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
              v205 = pns;
              v206 = Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                       xml_itr,
                       &v317,
                       xml_itr,
                       pns,
                       p_const,
                       0)->pV;
              v207 = xml->AppendChild;
              mn.Name.Bonus.pWeakProxy = v275.Bonus.pWeakProxy;
              mn.Obj.pObject = 0;
              mn.Kind = 12;
              mn.Name.Flags = (unsigned int)v206;
              HIBYTE(v253) = !v207(xml, &v287[3], (const Scaleform::GFx::AS3::Value *)&mn)->Result;
              Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&mn);
              if ( HIBYTE(v253) )
                goto LABEL_307;
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                v206,
                v205,
                &_name,
                (const Scaleform::GFx::ASString *)&t);
              v208 = name.pNode;
              DataType = Scaleform::GFx::AS3::SlotInfo::GetDataType((Scaleform::GFx::AS3::SlotInfo *)name.pNode, vm);
              if ( DataType )
              {
                v210 = DataType->GetQualifiedName(
                         &DataType->Scaleform::GFx::AS3::Traits,
                         (Scaleform::GFx::ASString *)&v301,
                         qnfWithColons);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v206, v205, &_type, v210);
                v211 = v301;
                --v301->RefCount;
                if ( !v211->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v211);
              }
              v212 = (const Scaleform::GFx::ASString *)v208->pManager;
              v213 = v212[7].pNode;
              v214 = v212 + 7;
              if ( v213->Size )
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v206, v205, &_uri, v214);
              if ( v208->HashFlags )
                Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(
                  v295,
                  vm,
                  v206,
                  (const Scaleform::GFx::AS3::VMAbcFile *)v208->RefCount,
                  (const Scaleform::GFx::AS3::Abc::TraitInfo *)v208->HashFlags);
            }
            else
            {
              p_method = &_method;
              if ( v272.pNode != (Scaleform::GFx::ASStringNode *)11 )
                p_method = &_accessor;
              v131 = pns;
              v132 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                                                       xml_itr,
                                                       &v316,
                                                       xml_itr,
                                                       pns,
                                                       p_method,
                                                       0)->pV;
              v133 = xml->AppendChild;
              _factory.pNode = v132;
              v303.Bonus.pWeakProxy = 0;
              v303.Flags = 12;
              *(_QWORD *)&v303.value.VNumber = __PAIR64__((unsigned int)v275.Bonus.pWeakProxy, (unsigned int)v132);
              HIBYTE(v253) = !v133(xml, (Scaleform::GFx::AS3::CheckResult *)&v263 + 3, &v303)->Result;
              if ( (v303.Flags & 0x1F) > 9 )
              {
                if ( (v303.Flags & 0x200) != 0 )
                {
                  v134 = v303.Bonus.pWeakProxy;
                  --v303.Bonus.pWeakProxy->RefCount;
                  if ( !v134->RefCount )
                    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v134);
                  memset(&v303.Bonus, 0, 12);
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v303);
                }
              }
              if ( HIBYTE(v253) )
                goto LABEL_307;
              Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                v131,
                &_name,
                (const Scaleform::GFx::ASString *)&t);
              if ( ((int)name.pNode->pData & 0x3E0) != 0x160 )
              {
                v135 = 0;
                if ( v129 == (Scaleform::GFx::ASStringNode *)12 )
                {
                  v135 = "readonly";
                }
                else if ( v129 == (Scaleform::GFx::ASStringNode *)13 )
                {
                  v135 = "writeonly";
                }
                else if ( v129 == (Scaleform::GFx::ASStringNode *)14 )
                {
                  v135 = "readwrite";
                }
                ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                    sm->pStringManager,
                                    v135,
                                    strlen(v135),
                                    0);
                v131 = pns;
                _access_name.pNode = ConstStringNode;
                ++ConstStringNode->RefCount;
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                  v131,
                  &_access,
                  &_access_name);
                v137 = _access_name.pNode;
                --_access_name.pNode->RefCount;
                if ( !v137->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v137);
                v129 = v272.pNode;
              }
              v138 = name.pNode->pManager;
              pTextBufferPages = v138->pTextBufferPages;
              p_pTextBufferPages = (const Scaleform::GFx::ASString *)&v138->pTextBufferPages;
              if ( *(_DWORD *)&pTextBufferPages->Entries[1].Buff[8] )
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                  v131,
                  &_uri,
                  p_pTextBufferPages);
              v252 = ((32 * (int)name.pNode->pData) >> 15) + (v129 == (Scaleform::GFx::ASStringNode *)13);
              VT = Scaleform::GFx::AS3::Traits::GetVT(tr);
              Scaleform::GFx::AS3::VTable::GetValue(VT, &func, (Scaleform::GFx::AS3::AbsoluteIndex)v252);
              v142 = (Scaleform::GFx::AS3::Traits_vtbl *)tr->__vftable;
              i = func.Flags & 0x1F;
              v143 = v142->GetAppDomain(tr);
              FunctReturnType = Scaleform::GFx::AS3::VM::GetFunctReturnType(vm, &func, v143);
              if ( Scaleform::GFx::AS3::InstanceTraits::Traits::IsParentTypeOf(
                     vm->TraitsClassClass.pObject->ITraits.pObject,
                     FunctReturnType) )
              {
                v145 = sm->pStringManager;
                v146 = v257 | 8;
                v257 |= 8u;
                v147 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v145, "*", 1u, 0);
                ++v147->RefCount;
                first_opt_param_num = (unsigned int)v147;
                p_first_opt_param_num = &first_opt_param_num;
              }
              else
              {
                GetQualifiedName = FunctReturnType->GetQualifiedName;
                v257 |= 0x10u;
                p_first_opt_param_num = (unsigned int *)GetQualifiedName(
                                                          (struct Scaleform::GFx::AS3::InstanceTraits::Traits *)FunctReturnType,
                                                          (Scaleform::GFx::ASString *)&v306,
                                                          qnfWithColons);
                v146 = v257;
                v147 = (Scaleform::GFx::ASStringNode *)first_opt_param_num;
              }
              type.pNode = (Scaleform::GFx::ASStringNode *)*p_first_opt_param_num;
              ++type.pNode->RefCount;
              if ( (v146 & 0x10) != 0 )
              {
                v150 = v306;
                --v306->RefCount;
                v146 &= ~0x10u;
                v39 = v150->RefCount == 0;
                v257 = v146;
                if ( v39 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v150);
              }
              if ( (v146 & 8) != 0 )
              {
                v146 &= ~8u;
                v39 = v147->RefCount-- == 1;
                v257 = v146;
                if ( v39 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v147);
              }
              if ( i == 7 )
              {
                v151 = Scaleform::GFx::AS3::Traits::GetVT((Scaleform::GFx::AS3::Traits *)func.value.VS._2.VObj);
                v152 = &v151->VTMethods.Data.Data[func.value.VS._1.VInt];
                VInt = v152->value.VS._1.VInt;
                v154.VObj = (Scaleform::GFx::AS3::Object *)v152->value.VS._2;
                v155 = v154.VObj->__vftable;
                real_func = v152;
                method_ind.Ind = VInt;
                v156 = ((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U))v155->Call)(v154);
                i = v156;
                if ( v272.pNode == (Scaleform::GFx::ASStringNode *)13 )
                {
                  Scaleform::GFx::AS3::Multiname::Multiname(
                    &v312,
                    (Scaleform::GFx::AS3::VMFile *)i,
                    (Scaleform::GFx::AS3::Abc::Multiname *)(*(_DWORD *)(*(_DWORD *)(v156 + 60) + 88)
                                                          + 16
                                                          * **(_DWORD **)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v156 + 60)
                                                                                                + 112)
                                                                                    + 4 * method_ind.Ind)
                                                                        + 12)));
                  if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v312) )
                  {
                    v157 = v146 | 0x20;
                    v257 = v157;
                    QualifiedName = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,62>::CreateConstString(
                                      sm,
                                      &v311,
                                      "*");
                  }
                  else
                  {
                    v290.pNode = v312.Name.value.VS._1.VStr;
                    ++*(_DWORD *)(v312.Name.value.VS._1.VInt + 12);
                    v157 = v146 | 0xC0;
                    v257 = v157;
                    QualifiedName = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(
                                      &v304,
                                      (Scaleform::GFx::ASStringNode *)v312.Obj.pObject,
                                      &v290,
                                      qnfWithColons);
                  }
                  Ind = QualifiedName->pNode;
                  ++Ind->RefCount;
                  v160 = type.pNode;
                  --type.pNode->RefCount;
                  v39 = v160->RefCount == 0;
                  method_ind.Ind = (int)Ind;
                  if ( v39 )
                  {
                    Scaleform::GFx::ASStringNode::ReleaseNode(v160);
                    Ind = (Scaleform::GFx::ASStringNode *)method_ind.Ind;
                  }
                  type.pNode = Ind;
                  if ( (v157 & 0x80u) != 0 )
                  {
                    v161 = v304.pNode;
                    --v304.pNode->RefCount;
                    v157 &= ~0x80u;
                    v39 = v161->RefCount == 0;
                    v257 = v157;
                    if ( v39 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v161);
                  }
                  if ( (v157 & 0x40) != 0 )
                  {
                    v162 = v290.pNode;
                    --v290.pNode->RefCount;
                    v157 &= ~0x40u;
                    v39 = v162->RefCount == 0;
                    v257 = v157;
                    if ( v39 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v162);
                  }
                  if ( (v157 & 0x20) != 0 )
                  {
                    v163 = v311.pNode;
                    --v311.pNode->RefCount;
                    v39 = v163->RefCount == 0;
                    v257 = v157 & 0xFFFFFFDF;
                    if ( v39 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v163);
                  }
                  Scaleform::GFx::AS3::Multiname::~Multiname(&v312);
                }
                p_returnType = &_returnType;
                if ( ((int)name.pNode->pData & 0x3E0) != 0x160 )
                  p_returnType = &_type;
                v165 = pns;
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                  pns,
                  p_returnType,
                  &type);
                v166 = (const Scaleform::GFx::ASString *)((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U, Scaleform::GFx::ASStringNode **, _DWORD))v154.VObj->GetDynamicProperty)(
                                                           v154,
                                                           &v308,
                                                           0);
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                  v165,
                  &_declaredBy,
                  v166);
                v167 = v308;
                --v308->RefCount;
                if ( !v167->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v167);
                if ( ((int)name.pNode->pData & 0x3E0) == 0x160 )
                {
                  v168 = real_func->value.VS._1;
                  v309 = (Scaleform::GFx::AS3::VMFile *)((int (__thiscall *)(Scaleform::GFx::AS3::Value::V2U))v154.VObj->Call)(v154);
                  v169 = v309[1].__vftable[3].~Scaleform::GFx::AS3::VMFile;
                  method_ind.Ind = (int)v309[1].__vftable;
                  v170 = (const Scaleform::GFx::AS3::Value *)*((_DWORD *)v169 + v168.VInt);
                  v171 = v170[1].Flags;
                  v172 = v171 - (unsigned int)v170[1].value.VS._2.VObj;
                  real_func = v170;
                  size = v171;
                  v307 = v172;
                  v272.pNode = 0;
                  if ( v171 )
                  {
                    while ( 1 )
                    {
                      v173 = xml_itr;
                      v305 = (Scaleform::GFx::ASStringNode *)((char *)&v272.pNode->pData + 1);
                      Scaleform::LongFormatter::LongFormatter(&f, (unsigned int)&v272.pNode->pData + 1);
                      Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                        v173,
                        &param,
                        v173,
                        pns,
                        &_parameter,
                        0);
                      *(_QWORD *)&v314.value.VNumber = __PAIR64__(
                                                         (unsigned int)v275.Bonus.pWeakProxy,
                                                         (unsigned int)param.pV);
                      v174 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *))*((_DWORD *)v132->pData + 19);
                      v314.Bonus.pWeakProxy = 0;
                      v314.Flags = 12;
                      v175 = *(_BYTE *)v174(v132, &v287[2], &v314) == 0;
                      Scaleform::GFx::AS3::Value::~Value(&v314);
                      if ( v175 )
                        break;
                      Scaleform::LongFormatter::Convert(&f);
                      v176 = vm->StringManagerRef;
                      ValueStr = f.ValueStr;
                      v178 = Scaleform::LongFormatter::GetSize(&f);
                      StringNode = (Scaleform::GFx::AS3::ClassTraits::Traits *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                                 v176->pStringManager,
                                                                                 ValueStr,
                                                                                 v178);
                      v180 = pns;
                      val = StringNode;
                      ++StringNode->pPrev;
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                        param.pV,
                        v180,
                        &_index,
                        (const Scaleform::GFx::ASString *)&val);
                      v181 = (Scaleform::GFx::ASStringNode *)val;
                      --val->pPrev;
                      if ( !v181->RefCount )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v181);
                      v182 = v272.pNode;
                      Scaleform::GFx::AS3::Multiname::Multiname(
                        &v312,
                        v309,
                        (Scaleform::GFx::AS3::Abc::Multiname *)(*(_DWORD *)(method_ind.Ind + 88)
                                                              + 16
                                                              * *((_DWORD *)&real_func->value.VS._2.VObj->__vftable
                                                                + (int)v272.pNode)));
                      if ( Scaleform::GFx::AS3::Multiname::IsAnyType(&v312) )
                      {
                        file = (Scaleform::GFx::AS3::VMAbcFile *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                                   sm->pStringManager,
                                                                   "*",
                                                                   1u,
                                                                   0);
                        ++file->pPrev;
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                          param.pV,
                          v180,
                          &_type,
                          (const Scaleform::GFx::ASString *)&file);
                        v183 = (Scaleform::GFx::ASStringNode *)file;
                      }
                      else
                      {
                        v184 = (Scaleform::GFx::ASStringNode *)v312.Obj.pObject;
                        v272.pNode = v312.Name.value.VS._1.VStr;
                        ++*(_DWORD *)(v312.Name.value.VS._1.VInt + 12);
                        v185 = param.pV;
                        v186 = Scaleform::GFx::AS3::XMLSupportImpl::GetQualifiedName(&v310, v184, &v272, qnfWithColons);
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v185, v180, &_type, v186);
                        v187 = v310.pNode;
                        --v310.pNode->RefCount;
                        if ( !v187->RefCount )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v187);
                        v183 = v272.pNode;
                      }
                      if ( !--v183->RefCount )
                        Scaleform::GFx::ASStringNode::ReleaseNode(v183);
                      p_true = &_true;
                      if ( (unsigned int)v182 < v307 )
                        p_true = &_false;
                      Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(param.pV, v180, &_optional, p_true);
                      Scaleform::GFx::AS3::Multiname::~Multiname(&v312);
                      f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
                      Scaleform::Formatter::~Formatter(&f);
                      v132 = _factory.pNode;
                      v272.pNode = v305;
                      if ( (unsigned int)v305 >= size )
                        goto LABEL_268;
                    }
LABEL_326:
                    f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
                    Scaleform::Formatter::~Formatter(&f);
                    v225 = type.pNode;
                    --type.pNode->RefCount;
                    if ( !v225->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v225);
                    Scaleform::GFx::AS3::Value::~Value(&func);
LABEL_307:
                    v216 = (Scaleform::GFx::ASStringNode *)t;
                    --t->pPrev;
                    if ( !v216->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v216);
                    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
                    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
                    v217 = _name.pNode;
                    --_name.pNode->RefCount;
                    if ( !v217->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v217);
                    v218 = _uri.pNode;
                    --_uri.pNode->RefCount;
                    if ( !v218->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v218);
                    v219 = _returnType.pNode;
                    --_returnType.pNode->RefCount;
                    if ( !v219->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v219);
                    v220 = _var.pNode;
                    --_var.pNode->RefCount;
                    if ( !v220->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v220);
                    v221 = _const.pNode;
                    --_const.pNode->RefCount;
                    if ( !v221->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v221);
                    v222 = _declaredBy.pNode;
                    --_declaredBy.pNode->RefCount;
                    if ( !v222->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v222);
                    v223 = _method.pNode;
                    --_method.pNode->RefCount;
                    if ( !v223->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v223);
                    v224 = _accessor.pNode;
                    --_accessor.pNode->RefCount;
                    if ( !v224->RefCount )
                      Scaleform::GFx::ASStringNode::ReleaseNode(v224);
                    v68 = _access.pNode;
                    goto LABEL_352;
                  }
                }
LABEL_268:
                if ( name.pNode->HashFlags )
                  Scaleform::GFx::AS3::XMLSupportImpl::DescribeMetaData(
                    v295,
                    vm,
                    (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                    (const Scaleform::GFx::AS3::VMAbcFile *)i,
                    (const Scaleform::GFx::AS3::Abc::TraitInfo *)name.pNode->HashFlags);
              }
              else
              {
                p_type = &_returnType;
                if ( ((int)name.pNode->pData & 0x3E0) != 0x160 )
                  p_type = &_type;
                Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                  (Scaleform::GFx::AS3::Instances::fl::XMLElement *)v132,
                  pns,
                  p_type,
                  &type);
                if ( ((int)name.pNode->pData & 0x3E0) == 0x160 )
                {
                  v190 = *(_DWORD *)(func.value.VS._1.VInt + 16);
                  if ( ((v190 >> 7) & 7) != 0 || (v190 & 0x3FFC00) != 0x3FFC00 )
                  {
                    v191 = (Scaleform::GFx::ASStringNode *)((v190 >> 10) & 0xFFF);
                    if ( v191 == (Scaleform::GFx::ASStringNode *)4095 )
                      v191 = (Scaleform::GFx::ASStringNode *)((*(_DWORD *)(func.value.VS._1.VInt + 16) >> 7) & 7);
                    v272.pNode = v191;
                    i = 0;
                    if ( v191 )
                    {
                      while ( 1 )
                      {
                        v192 = xml_itr;
                        size = i + 1;
                        Scaleform::LongFormatter::LongFormatter(&f, i + 1);
                        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                          v192,
                          &factory,
                          v192,
                          pns,
                          &_parameter,
                          0);
                        v193 = (int (__thiscall *)(Scaleform::GFx::ASStringNode *, Scaleform::GFx::AS3::CheckResult *, Scaleform::GFx::AS3::Value *))*((_DWORD *)v132->pData + 19);
                        *(_QWORD *)&v313.value.VNumber = __PAIR64__(
                                                           (unsigned int)v275.Bonus.pWeakProxy,
                                                           (unsigned int)factory.pV);
                        v313.Bonus.pWeakProxy = 0;
                        v313.Flags = 12;
                        v194 = *(_BYTE *)v193(v132, &result[3], &v313) == 0;
                        Scaleform::GFx::AS3::Value::~Value(&v313);
                        if ( v194 )
                          goto LABEL_326;
                        Scaleform::LongFormatter::Convert(&f);
                        v195 = f.ValueStr;
                        v196 = vm->StringManagerRef;
                        v197 = Scaleform::LongFormatter::GetSize(&f);
                        v198 = (const Scaleform::GFx::AS3::Abc::MethodInfo *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                                               v196->pStringManager,
                                                                               v195,
                                                                               v197);
                        v199 = pns;
                        mi = v198;
                        ++v198->ParamTypes.Data.Data;
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(
                          factory.pV,
                          v199,
                          &_index,
                          (const Scaleform::GFx::ASString *)&mi);
                        v200 = (Scaleform::GFx::ASStringNode *)mi;
                        --mi->ParamTypes.Data.Data;
                        if ( !v200->RefCount )
                          Scaleform::GFx::ASStringNode::ReleaseNode(v200);
                        p_false = &_true;
                        if ( i < ((*(_DWORD *)(func.value.VS._1.VInt + 16) >> 7) & 7u) )
                          p_false = &_false;
                        Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(factory.pV, v199, &_optional, p_false);
                        f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
                        Scaleform::Formatter::~Formatter(&f);
                        i = size;
                        if ( size >= (unsigned int)v272.pNode )
                          break;
                        v132 = _factory.pNode;
                      }
                    }
                  }
                }
              }
              v202 = type.pNode;
              --type.pNode->RefCount;
              if ( !v202->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v202);
              Scaleform::GFx::AS3::Value::~Value(&func);
            }
          }
          v215 = (Scaleform::GFx::ASStringNode *)t;
          --t->pPrev;
          if ( !v215->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v215);
        }
        if ( it.Ind.Index >= 0 )
          --it.Ind.Index;
      }
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF>>(&handled.Entries.mHash);
      v226 = _name.pNode;
      --_name.pNode->RefCount;
      if ( !v226->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v226);
      v227 = _uri.pNode;
      --_uri.pNode->RefCount;
      if ( !v227->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v227);
      v228 = _returnType.pNode;
      --_returnType.pNode->RefCount;
      if ( !v228->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v228);
      v229 = _var.pNode;
      --_var.pNode->RefCount;
      if ( !v229->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v229);
      v230 = _const.pNode;
      --_const.pNode->RefCount;
      if ( !v230->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v230);
      v231 = _declaredBy.pNode;
      --_declaredBy.pNode->RefCount;
      if ( !v231->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v231);
      v232 = _method.pNode;
      --_method.pNode->RefCount;
      if ( !v232->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v232);
      v233 = _accessor.pNode;
      --_accessor.pNode->RefCount;
      if ( !v233->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v233);
      v234 = _access.pNode;
      --_access.pNode->RefCount;
      if ( !v234->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v234);
      if ( (tr->Flags & 0x20) != 0 )
      {
        v235 = Scaleform::GFx::ASStringManager::CreateConstStringNode(sm->pStringManager, "factory", 7u, 0);
        v236 = pns;
        v237 = xml_itr;
        v250 = pns;
        v249 = xml_itr;
        _factory.pNode = v235;
        ++v235->RefCount;
        Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v237, &factory, v249, v250, &_factory, xml);
        v238 = xml->AppendChild;
        mn.Name.Flags = (unsigned int)factory.pV;
        mn.Name.Bonus.pWeakProxy = v275.Bonus.pWeakProxy;
        mn.Obj.pObject = 0;
        mn.Kind = 12;
        v239 = !v238(xml, &v287[3], (const Scaleform::GFx::AS3::Value *)&mn)->Result;
        Scaleform::GFx::AS3::Value::~Value((Scaleform::GFx::AS3::Value *)&mn);
        if ( !v239 )
        {
          v240 = factory.pV;
          v241 = tr->GetQualifiedName(tr, &v301, 0);
          Scaleform::GFx::AS3::Instances::fl::XMLElement::AddAttr(v240, v236, &_type, v241);
          v242 = v301;
          --v301->RefCount;
          if ( !v242->RefCount )
            Scaleform::GFx::ASStringNode::ReleaseNode(v242);
          Scaleform::GFx::AS3::XMLSupportImpl::DescribeTraits(
            v295,
            vm,
            factory.pV,
            (const Scaleform::GFx::AS3::Traits *)tr->Ns.pObject);
        }
        v68 = _factory.pNode;
        goto LABEL_352;
      }
      goto LABEL_354;
    }
    v75 = (unsigned int)v74 - v73->OptionalParams.Data.Size;
    v76 = StringManagerRef->pStringManager;
    first_opt_param_num = v75;
    v77 = Scaleform::GFx::ASStringManager::CreateConstStringNode(v76, "constructor", 0xBu, 0);
    v78 = pns;
    v79 = xml_itr;
    _method.pNode = v77;
    ++v77->RefCount;
    Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(v79, &factory, v79, v78, &_method, 0);
    *(_QWORD *)&func.value.VNumber = __PAIR64__((unsigned int)v275.Bonus.pWeakProxy, (unsigned int)factory.pV);
    v80 = xml->AppendChild;
    func.Bonus.pWeakProxy = 0;
    func.Flags = 12;
    HIBYTE(v253) = !v80(xml, (Scaleform::GFx::AS3::CheckResult *)&v263 + 3, &func)->Result;
    if ( (func.Flags & 0x1F) > 9 )
    {
      if ( (func.Flags & 0x200) != 0 )
      {
        v81 = func.Bonus.pWeakProxy;
        --func.Bonus.pWeakProxy->RefCount;
        if ( !v81->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v81);
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&func);
      }
    }
    if ( HIBYTE(v253) )
    {
      v68 = _method.pNode;
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
      v84 = v257;
      if ( v82 == 10 )
      {
        ++*(_DWORD *)(mn.Name.value.VS._1.VInt + 12);
        v84 |= 0x100u;
        v39 = CTr->FirstOwnSlotNum == 0;
        val = CTr;
        if ( v39 )
          goto LABEL_127;
      }
      HIBYTE(v253) = 0;
LABEL_128:
      if ( (v84 & 0x100) != 0 )
      {
        v85 = (Scaleform::GFx::ASStringNode *)val;
        v84 &= ~0x100u;
        v39 = val->pPrev-- == (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)1;
        if ( v39 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v85);
      }
      if ( HIBYTE(v253) )
      {
        v86 = sm->pStringManager;
        v87 = v84 | 1;
        v257 = v87;
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
        v39 = v91[1].__vftable == 0;
        v257 = v87;
        if ( v39 )
        {
          param.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)_const.pNode;
          ++_const.pNode->RefCount;
        }
        else
        {
          v93 = Scaleform::GFx::ASString::operator+(v92, &v290, "::");
          Scaleform::GFx::ASString::operator+(v93, (Scaleform::GFx::ASString *)&param, &_const);
          v94 = v290.pNode;
          --v290.pNode->RefCount;
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
        v39 = v95->RefCount == 0;
        v257 = v87;
        if ( v39 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v95);
      }
      if ( (v87 & 2) != 0 )
      {
        v96 = _const.pNode;
        --_const.pNode->RefCount;
        v87 &= ~2u;
        v39 = v96->RefCount == 0;
        v257 = v87;
        if ( v39 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v96);
      }
      if ( (v87 & 1) != 0 )
      {
        v39 = v88->RefCount-- == 1;
        v257 = v87 & 0xFFFFFFFE;
        if ( v39 )
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
      *(_QWORD *)&v275.value.VNumber = (unsigned int)_access.pNode;
      v275.Bonus.pWeakProxy = 0;
      v275.Flags = 12;
      HIBYTE(v253) = !factory.pV->AppendChild(factory.pV, (char *)&v263 + 3, &v275)->Result;
      if ( (v275.Flags & 0x1F) > 9 )
      {
        if ( (v275.Flags & 0x200) != 0 )
        {
          v98 = v275.Bonus.pWeakProxy;
          --v275.Bonus.pWeakProxy->RefCount;
          if ( !v98->RefCount )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v98);
          memset(&v275.Bonus, 0, 12);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v275);
        }
      }
      if ( HIBYTE(v253) )
      {
        f.Scaleform::String::InitStruct::__vftable = (Scaleform::String::InitStruct_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
        Scaleform::Formatter::~Formatter(&f);
        v111 = _var.pNode;
        --_var.pNode->RefCount;
        if ( !v111->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v111);
        Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
        pV = _method.pNode;
        goto LABEL_36;
      }
      Scaleform::LongFormatter::Convert(&f);
      v99 = vm->StringManagerRef;
      v100 = f.ValueStr;
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
    v84 = v257;
LABEL_127:
    HIBYTE(v253) = 1;
    goto LABEL_128;
  }
  _access.pNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                    StringManagerRef->pStringManager,
                    "implementsInterface",
                    0x13u,
                    0);
  ++_access.pNode->RefCount;
  MHeap = vm->MHeap;
  p_EmptyStringNode = &StringManagerRef->pStringManager->EmptyStringNode;
  handled.Entries.mHash.pTable = 0;
  handled.Entries.mHash.pHeap = MHeap;
  name.pNode = p_EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  t = tr;
  while ( 1 )
  {
    if ( (t->Flags & 0x10) == 0 )
    {
      mi = (const Scaleform::GFx::AS3::Abc::MethodInfo *)t[1].pPrev;
      i = 0;
      if ( mi )
      {
        param.pV = 0;
        while ( 1 )
        {
          if ( Scaleform::GFx::AS3::Value::Convert2String(
                 (Scaleform::GFx::AS3::Value *)((char *)&param.pV->8 + (unsigned int)t[1].pNext),
                 &v287[2],
                 &name)->Result )
          {
            pTable = handled.Entries.mHash.pTable;
            if ( !handled.Entries.mHash.pTable )
              goto LABEL_82;
            v50 = 4;
            v51 = 5381;
            do
            {
              --v50;
              v51 = *((unsigned __int8 *)&name.pNode + v50) + 65599 * v51;
            }
            while ( v50 );
            v52 = Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::findIndexCore<Scaleform::GFx::ASString>(
                    (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
                    &name,
                    v51 & handled.Entries.mHash.pTable->SizeMask);
            if ( v52 < 0
              || (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)pTable + 12 * v52) == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)-16 )
            {
LABEL_82:
              v53 = 4;
              v54 = 5381;
              do
              {
                --v53;
                v54 = *((unsigned __int8 *)&name.pNode + v53) + 65599 * v54;
              }
              while ( v53 );
              Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
                (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
                handled.Entries.mHash.pHeap,
                &name,
                v54);
              Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(
                xml_itr,
                (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::XMLElement> *)&_factory,
                xml_itr,
                pns,
                &_access,
                0);
              v55 = xml->AppendChild;
              *(_QWORD *)&v300.value.VNumber = __PAIR64__(
                                                 (unsigned int)v275.Bonus.pWeakProxy,
                                                 (unsigned int)_factory.pNode);
              v300.Bonus.pWeakProxy = 0;
              v300.Flags = 12;
              v56 = !v55(xml, (Scaleform::GFx::AS3::CheckResult *)&v263 + 3, &v300)->Result;
              if ( (v300.Flags & 0x1F) > 9 )
              {
                if ( (v300.Flags & 0x200) != 0 )
                {
                  v57 = v300.Bonus.pWeakProxy;
                  --v300.Bonus.pWeakProxy->RefCount;
                  if ( !v57->RefCount )
                    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v57);
                  memset(&v300.Bonus, 0, 12);
                }
                else
                {
                  Scaleform::GFx::AS3::Value::ReleaseInternal(&v300);
                }
              }
              if ( v56 )
              {
                v67 = name.pNode;
                --name.pNode->RefCount;
                if ( !v67->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v67);
                Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled);
                v68 = _access.pNode;
LABEL_352:
                if ( !--v68->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v68);
LABEL_354:
                v243 = _index.pNode;
                --_index.pNode->RefCount;
                if ( !v243->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v243);
                v244 = _parameter.pNode;
                --_parameter.pNode->RefCount;
                if ( !v244->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v244);
                v245 = _optional.pNode;
                --_optional.pNode->RefCount;
                if ( !v245->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v245);
                v246 = _type.pNode;
                --_type.pNode->RefCount;
                if ( !v246->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v246);
                v247 = _false.pNode;
                --_false.pNode->RefCount;
                if ( !v247->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v247);
                v248 = _true.pNode;
                --_true.pNode->RefCount;
                v38 = v248;
                v39 = v248->RefCount == 0;
                goto LABEL_365;
              }
              v58 = *(Scaleform::GFx::ASString **)((char *)&param.pV->_pRCC + (unsigned int)t[1].pNext);
              v59 = v58[7].pNode;
              v60 = v58 + 7;
              if ( v59->Size )
              {
                v61 = Scaleform::GFx::ASString::operator+(v60, &_access_name, "::");
                Scaleform::GFx::ASString::operator+(v61, &_method, &name);
                v62 = _access_name.pNode;
                --_access_name.pNode->RefCount;
                if ( !v62->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v62);
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
              v63 = _method.pNode;
              --_method.pNode->RefCount;
              if ( !v63->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v63);
            }
          }
          param.pV = (Scaleform::GFx::AS3::Instances::fl::XMLElement *)((char *)param.pV + 24);
          if ( ++i >= (unsigned int)mi )
            goto LABEL_98;
        }
      }
      goto LABEL_98;
    }
    mi = (const Scaleform::GFx::AS3::Abc::MethodInfo *)&t[1].pPrev[1].12;
    v16 = mi;
    v17 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t);
    RetTypeInd = v16->RetTypeInd;
    file = (Scaleform::GFx::AS3::VMAbcFile *)&v17->File.pObject->Const_Pool;
    first_opt_param_num = RetTypeInd;
    param.pV = 0;
    if ( RetTypeInd )
      break;
LABEL_98:
    t = t->pParent.pObject;
    if ( !t )
    {
      v64 = name.pNode;
      --name.pNode->RefCount;
      if ( !v64->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v64);
      Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled);
      v65 = _access.pNode;
      --_access.pNode->RefCount;
      if ( !v65->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v65);
      goto LABEL_109;
    }
  }
  while ( 1 )
  {
    v251 = (Scaleform::GFx::AS3::Abc::Multiname *)&file->GlobalObjects.pTable[2
                                                                            * *(_DWORD *)(*(_DWORD *)&mi->Flags
                                                                                        + 4 * (int)param.pV)];
    v19 = Scaleform::GFx::AS3::InstanceTraits::UserDefined::GetFile((Scaleform::GFx::AS3::InstanceTraits::UserDefined *)t);
    Scaleform::GFx::AS3::Multiname::Multiname(&mn, v19, v251);
    if ( Scaleform::GFx::AS3::Value::Convert2String(&mn.Name, &result[3], &name)->Result )
    {
      v20 = handled.Entries.mHash.pTable;
      if ( !handled.Entries.mHash.pTable )
        break;
      v21 = 4;
      v22 = 5381;
      do
      {
        v23 = *((unsigned __int8 *)&v253 + v21-- + 3);
        v22 = v23 + 65599 * v22;
      }
      while ( v21 );
      v24 = Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::findIndexCore<Scaleform::GFx::ASString>(
              (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
              &name,
              v22 & handled.Entries.mHash.pTable->SizeMask);
      if ( v24 < 0
        || (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)((char *)v20 + 12 * v24) == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::MultinameHash<bool,2>::Key,bool,Scaleform::GFx::AS3::MultinameHash<bool,2>::Key::HashFunctor>::NodeHashF> >::TableType *)-16 )
      {
        break;
      }
    }
LABEL_72:
    Scaleform::GFx::AS3::Multiname::~Multiname(&mn);
    if ( (unsigned int)++param.pV >= first_opt_param_num )
      goto LABEL_98;
  }
  v25 = 4;
  v26 = 5381;
  do
  {
    v27 = *((unsigned __int8 *)&v253 + v25-- + 3);
    v26 = v27 + 65599 * v26;
  }
  while ( v25 );
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::add<Scaleform::GFx::ASString>(
    (Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled,
    handled.Entries.mHash.pHeap,
    &name,
    v26);
  Scaleform::GFx::AS3::InstanceTraits::fl::XML::MakeInstanceElement(xml_itr, &factory, xml_itr, pns, &_access, 0);
  v28 = xml->AppendChild;
  *(_QWORD *)&v275.value.VNumber = (unsigned int)factory.pV;
  v275.Bonus.pWeakProxy = 0;
  v275.Flags = 12;
  v29 = !v28(xml, (Scaleform::GFx::AS3::CheckResult *)&v253 + 3, &v275)->Result;
  if ( (v275.Flags & 0x1F) > 9 )
  {
    if ( (v275.Flags & 0x200) != 0 )
    {
      v30 = v275.Bonus.pWeakProxy;
      --v275.Bonus.pWeakProxy->RefCount;
      if ( !v30->RefCount )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v30);
      memset(&v275.Bonus, 0, 12);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v275);
    }
  }
  if ( !v29 )
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
      v46 = Scaleform::GFx::ASString::operator+(&v40->Uri, &v290, "::");
      Scaleform::GFx::ASString::operator+(v46, &_accessor, &name);
      v47 = v290.pNode;
      --v290.pNode->RefCount;
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
  v66 = name.pNode;
  --name.pNode->RefCount;
  if ( !v66->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>::~HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>>>((Scaleform::HashSetBase<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::FixedSizeHash<Scaleform::GFx::ASString>,Scaleform::AllocatorDH<Scaleform::GFx::ASString,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::ASString,Scaleform::FixedSizeHash<Scaleform::GFx::ASString> > > *)&handled);
  pV = _access.pNode;
LABEL_36:
  if ( !--pV->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pV);
  v32 = _index.pNode;
  --_index.pNode->RefCount;
  if ( !v32->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  v33 = _parameter.pNode;
  --_parameter.pNode->RefCount;
  if ( !v33->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  v34 = _optional.pNode;
  --_optional.pNode->RefCount;
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  v35 = _type.pNode;
  --_type.pNode->RefCount;
  if ( !v35->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  v36 = _false.pNode;
  --_false.pNode->RefCount;
  if ( !v36->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v36);
  v37 = _true.pNode;
  --_true.pNode->RefCount;
  v38 = v37;
  v39 = v37->RefCount == 0;
LABEL_365:
  if ( v39 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v38);
}
