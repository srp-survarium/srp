unsigned int __thiscall Scaleform::GFx::AS3::VM::ExecuteCode(
        Scaleform::GFx::AS3::VM *this,
        unsigned int max_stack_depth)
{
  Scaleform::GFx::AS3::CallFrame **Pages; // edx
  Scaleform::GFx::AS3::CallFrame *v4; // ecx
  Scaleform::GFx::AS3::CallFrame *v5; // ebx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ecx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // esi
  Scaleform::GFx::AS3::Abc::File *pObject; // eax
  Scaleform::GFx::AS3::Value::V2U v9; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *v11; // eax
  unsigned int *CP; // esi
  int v13; // eax
  Scaleform::GFx::AS3::Boolean3 v14; // ecx
  unsigned int v15; // eax
  int v16; // esi
  Scaleform::GFx::AS3::Abc::Multiname *v17; // eax
  int v18; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  unsigned int v20; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v21; // ecx
  Scaleform::GFx::AS3::Boolean3 v22; // eax
  __int32 v23; // esi
  int v24; // eax
  Scaleform::GFx::AS3::Value *v25; // ecx
  Scaleform::GFx::AS3::Value *v26; // eax
  Scaleform::GFx::AS3::Value::V1U v27; // ecx
  unsigned int *v28; // esi
  Scaleform::GFx::AS3::Boolean3 v29; // edx
  Scaleform::GFx::AS3::Value *v30; // eax
  long double v31; // st7
  unsigned int v32; // edx
  long double v33; // st6
  unsigned int *v34; // esi
  unsigned int v35; // ecx
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  __int32 v37; // esi
  int v38; // eax
  Scaleform::GFx::AS3::Value *v39; // ecx
  Scaleform::GFx::AS3::Value *v40; // eax
  Scaleform::GFx::AS3::Value::V1U v41; // ecx
  Scaleform::GFx::AS3::Value *v42; // eax
  long double v43; // st7
  unsigned int v44; // edx
  long double v45; // st6
  Scaleform::GFx::AS3::Value *v46; // eax
  int v47; // eax
  Scaleform::GFx::AS3::Value *v48; // ecx
  Scaleform::GFx::AS3::Value *v49; // eax
  Scaleform::GFx::AS3::Value::V1U v50; // ecx
  Scaleform::GFx::AS3::Value *v51; // eax
  long double v52; // st7
  unsigned int v53; // edx
  long double v54; // st6
  int v55; // eax
  Scaleform::GFx::AS3::Value *v56; // ecx
  Scaleform::GFx::AS3::Value *v57; // eax
  Scaleform::GFx::AS3::Value::V1U v58; // ecx
  Scaleform::GFx::AS3::Value *v59; // eax
  long double v60; // st7
  unsigned int v61; // edx
  long double v62; // st6
  Scaleform::GFx::AS3::Value *v63; // ecx
  unsigned int *v64; // esi
  bool v65; // al
  char v66; // al
  Scaleform::GFx::AS3::Boolean3 v67; // ecx
  Scaleform::GFx::AS3::Value *v68; // eax
  bool VBool; // cl
  unsigned int v70; // edx
  unsigned int *v71; // esi
  unsigned int v72; // eax
  Scaleform::GFx::AS3::Value *v73; // ecx
  bool v74; // al
  char v75; // al
  Scaleform::GFx::AS3::Value *v76; // eax
  bool v77; // cl
  unsigned int v78; // edx
  int v79; // eax
  Scaleform::GFx::AS3::Value *v80; // ecx
  Scaleform::GFx::AS3::Value *v81; // eax
  Scaleform::GFx::AS3::Value::V1U v82; // ecx
  Scaleform::GFx::AS3::Value *v83; // eax
  long double v84; // st7
  unsigned int v85; // edx
  long double v86; // st6
  int v87; // eax
  Scaleform::GFx::AS3::Value *v88; // ecx
  Scaleform::GFx::AS3::Value *v89; // eax
  Scaleform::GFx::AS3::Value::V1U v90; // ecx
  Scaleform::GFx::AS3::Value *v91; // eax
  long double v92; // st7
  unsigned int v93; // edx
  long double v94; // st6
  unsigned int v95; // esi
  int v96; // eax
  Scaleform::GFx::AS3::Value *v97; // ecx
  Scaleform::GFx::AS3::Value *v98; // eax
  Scaleform::GFx::AS3::Value::V1U v99; // ecx
  unsigned int *v100; // esi
  unsigned int v101; // edx
  Scaleform::GFx::AS3::Value *v102; // eax
  unsigned int v103; // esi
  int v104; // eax
  Scaleform::GFx::AS3::Value *v105; // ecx
  Scaleform::GFx::AS3::Value *v106; // eax
  Scaleform::GFx::AS3::Value::V1U v107; // ecx
  Scaleform::GFx::AS3::Value *v108; // eax
  int v109; // eax
  Scaleform::GFx::AS3::Value *v110; // ecx
  Scaleform::GFx::AS3::Value *v111; // eax
  Scaleform::GFx::AS3::Value::V1U v112; // ecx
  int v113; // eax
  Scaleform::GFx::AS3::Value *v114; // ecx
  Scaleform::GFx::AS3::Value *v115; // eax
  Scaleform::GFx::AS3::Value::V1U v116; // ecx
  int v117; // eax
  bool v118; // zf
  Scaleform::GFx::AS3::Value *v119; // eax
  unsigned int *v120; // esi
  Scaleform::GFx::AS3::Value *v121; // eax
  unsigned int v122; // ecx
  int v123; // edx
  Scaleform::GFx::AS3::WeakProxy *v124; // edx
  Scaleform::GFx::AS3::Value *v125; // eax
  unsigned int v126; // ecx
  int v127; // edx
  Scaleform::GFx::AS3::WeakProxy *v128; // edx
  const unsigned int *v129; // eax
  const unsigned int *v130; // eax
  Scaleform::GFx::AS3::Value *v131; // eax
  Scaleform::GFx::AS3::Value *v132; // eax
  unsigned int v133; // ecx
  int v134; // edx
  Scaleform::GFx::AS3::WeakProxy *v135; // edx
  unsigned int v136; // ecx
  int v137; // edx
  Scaleform::GFx::AS3::Value *v138; // eax
  unsigned int v139; // edx
  unsigned int *v140; // esi
  int v141; // eax
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::GFx::AS3::Value *v143; // eax
  unsigned int v144; // ecx
  Scaleform::GFx::AS3::Value *v145; // eax
  unsigned int v146; // edx
  Scaleform::GFx::ASStringNode *v147; // ecx
  unsigned int v148; // ecx
  Scaleform::GFx::AS3::Value *v149; // eax
  unsigned int v150; // edx
  Scaleform::GFx::ASStringNode *v151; // ecx
  Scaleform::GFx::AS3::Value *v152; // eax
  Scaleform::GFx::AS3::Value::V2U v153; // edx
  Scaleform::GFx::AS3::Value *v154; // eax
  Scaleform::GFx::AS3::Value::V2U v155; // ecx
  int v156; // eax
  int v157; // edx
  int v158; // ecx
  Scaleform::GFx::AS3::Value *pRF; // ecx
  Scaleform::GFx::AS3::Value *v160; // eax
  Scaleform::StringDataPtr *String; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS3::Value *v163; // ecx
  Scaleform::GFx::ASStringNode *v164; // eax
  int v165; // ecx
  Scaleform::GFx::AS3::Value *v166; // eax
  unsigned int v167; // ecx
  Scaleform::GFx::AS3::Value *v168; // eax
  Scaleform::GFx::AS3::Value::V1U v169; // ecx
  Scaleform::GFx::AS3::Value *v170; // eax
  Scaleform::GFx::AS3::Value::V2U v171; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v172; // eax
  Scaleform::GFx::AS3::Value::V1U v173; // eax
  Scaleform::GFx::AS3::GlobalSlotIndex v174; // ecx
  Scaleform::GFx::AS3::Value::VU *v175; // eax
  Scaleform::GFx::AS3::Value::VU *v176; // eax
  int v177; // eax
  unsigned int v178; // eax
  unsigned int v179; // ecx
  unsigned int v180; // eax
  unsigned int v181; // ecx
  unsigned int v182; // eax
  unsigned int v183; // ecx
  unsigned int v184; // eax
  unsigned int v185; // ecx
  Scaleform::GFx::AS3::Abc::MiInd v186; // eax
  unsigned int v187; // ecx
  unsigned int v188; // eax
  unsigned int v189; // ecx
  unsigned int v190; // eax
  unsigned int v191; // ecx
  unsigned int v192; // eax
  unsigned int v193; // ecx
  unsigned int v194; // eax
  unsigned int v195; // ecx
  unsigned int v196; // eax
  unsigned int v197; // ecx
  unsigned int v198; // eax
  unsigned int v199; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // eax
  int v201; // edx
  Scaleform::GFx::AS3::Value *v202; // eax
  Scaleform::GFx::AS3::Value *v203; // ecx
  Scaleform::GFx::AS3::Value *v204; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v205; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v206; // ecx
  Scaleform::GFx::AS3::Value *v207; // eax
  Scaleform::GFx::AS3::Value *v208; // ecx
  Scaleform::GFx::AS3::Value *v209; // eax
  bool v210; // al
  Scaleform::GFx::AS3::Value *v211; // eax
  const Scaleform::GFx::AS3::VM::Error *v212; // eax
  Scaleform::GFx::ASStringNode *v213; // eax
  Scaleform::GFx::AS3::Value *v214; // ecx
  Scaleform::GFx::AS3::Value *v215; // ecx
  Scaleform::GFx::AS3::Value *v216; // ecx
  bool v217; // al
  Scaleform::GFx::AS3::Value *v218; // ecx
  bool v219; // cl
  double *v220; // eax
  double v221; // st7
  Scaleform::GFx::AS3::Value *v222; // eax
  Scaleform::GFx::AS3::Value *v223; // eax
  Scaleform::GFx::AS3::Value::V2U v224; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::AS3::Value *v226; // eax
  bool v227; // cl
  unsigned int v228; // eax
  long double v229; // st7
  Scaleform::GFx::AS3::Value *v230; // eax
  bool v231; // cl
  unsigned int v232; // eax
  Scaleform::GFx::AS3::Value *v233; // ecx
  bool v234; // cl
  double *v235; // eax
  double v236; // st7
  Scaleform::GFx::AS3::Value *v237; // eax
  Scaleform::GFx::AS3::Value *v238; // eax
  long double v239; // st7
  Scaleform::GFx::AS3::Value *v240; // ecx
  bool v241; // cl
  double *v242; // eax
  double v243; // st7
  Scaleform::GFx::AS3::Value *v244; // eax
  Scaleform::GFx::AS3::Value *v245; // ecx
  bool v246; // al
  int *v247; // ecx
  Scaleform::GFx::AS3::Value *v248; // ecx
  Scaleform::GFx::AS3::Value *v249; // ecx
  bool v250; // al
  int *v251; // ecx
  Scaleform::GFx::AS3::Value *v252; // ecx
  Scaleform::GFx::AS3::Value *v253; // ecx
  bool v254; // al
  int *v255; // ecx
  Scaleform::GFx::AS3::Value *v256; // ecx
  Scaleform::GFx::AS3::Value *v257; // ecx
  bool v258; // al
  int *v259; // ecx
  Scaleform::GFx::AS3::Value *v260; // ecx
  Scaleform::GFx::AS3::Value *v261; // ecx
  bool v262; // al
  int *v263; // ecx
  Scaleform::GFx::AS3::Value *v264; // ecx
  Scaleform::GFx::AS3::Value *v265; // ecx
  bool v266; // al
  int *v267; // ecx
  Scaleform::GFx::AS3::Value *v268; // ecx
  Scaleform::GFx::AS3::Value *v269; // eax
  Scaleform::GFx::AS3::Value *v270; // eax
  Scaleform::GFx::AS3::Value::Extra v271; // edx
  Scaleform::GFx::AS3::Value *v272; // eax
  Scaleform::GFx::AS3::Value *v273; // eax
  Scaleform::GFx::AS3::Value::V2U v274; // ecx
  Scaleform::GFx::AS3::Value *v275; // eax
  Scaleform::GFx::AS3::CheckResult *v276; // ecx
  Scaleform::GFx::AS3::Value *v277; // eax
  Scaleform::GFx::AS3::Value::V2U v278; // ecx
  Scaleform::GFx::AS3::Value *v279; // eax
  Scaleform::GFx::AS3::Value::V2U v280; // ecx
  Scaleform::GFx::AS3::Value *v281; // eax
  unsigned int v282; // ecx
  Scaleform::GFx::AS3::Value::V1U v283; // edx
  Scaleform::GFx::AS3::Value::V2U v284; // edx
  const Scaleform::GFx::AS3::VM::Error *v285; // eax
  Scaleform::GFx::ASStringNode *v286; // eax
  Scaleform::GFx::AS3::Value *AbsObject; // eax
  Scaleform::GFx::AS3::Value *v288; // ecx
  Scaleform::GFx::AS3::Value *v289; // ecx
  Scaleform::GFx::AS3::Value::VU *p_value; // eax
  Scaleform::GFx::AS3::Value *v291; // ecx
  Scaleform::GFx::AS3::Value::VU *v292; // eax
  Scaleform::GFx::AS3::Value *v293; // ecx
  bool v294; // al
  int *v295; // ecx
  Scaleform::GFx::AS3::Value *v296; // ecx
  Scaleform::GFx::AS3::Value *v297; // eax
  Scaleform::GFx::AS3::Value::V1U v298; // ecx
  Scaleform::GFx::AS3::Value *v299; // eax
  long double VNumber; // st7
  Scaleform::GFx::AS3::Value *v301; // ecx
  bool v302; // al
  int *v303; // ecx
  Scaleform::GFx::AS3::Value *v304; // ecx
  Scaleform::GFx::AS3::Value *v305; // eax
  Scaleform::GFx::AS3::Value::V1U v306; // ecx
  Scaleform::GFx::AS3::Value *v307; // eax
  long double v308; // st7
  Scaleform::GFx::AS3::Value *v309; // ecx
  bool v310; // al
  int *v311; // ecx
  Scaleform::GFx::AS3::Value *v312; // ecx
  Scaleform::GFx::AS3::Value *v313; // eax
  Scaleform::GFx::AS3::Value::V1U v314; // ecx
  Scaleform::GFx::AS3::Value *v315; // eax
  long double v316; // st7
  Scaleform::GFx::AS3::Value *v317; // eax
  Scaleform::GFx::AS3::Value *v318; // eax
  Scaleform::GFx::AS3::Value *v319; // eax
  Scaleform::GFx::AS3::Value *v320; // eax
  unsigned int v321; // edx
  Scaleform::GFx::AS3::CallFrame *v322; // ecx
  unsigned int Size; // eax
  const Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *OpCode; // eax
  Scaleform::GFx::AS3::Abc::Multiname *va; // [esp+0h] [ebp-248h]
  Scaleform::GFx::AS3::Abc::Multiname *vb; // [esp+0h] [ebp-248h]
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *v; // [esp+0h] [ebp-248h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4a; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v_4b; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4c; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4d; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4e; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4f; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4g; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4h; // [esp+4h] [ebp-244h]
  unsigned int v_4i; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::AbsoluteIndex v_4j; // [esp+4h] [ebp-244h]
  unsigned int v_4k; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v_4l; // [esp+4h] [ebp-244h]
  unsigned int v_4m; // [esp+4h] [ebp-244h]
  unsigned int v_4n; // [esp+4h] [ebp-244h]
  unsigned int v_4o; // [esp+4h] [ebp-244h]
  unsigned int v_4p; // [esp+4h] [ebp-244h]
  unsigned int v_4q; // [esp+4h] [ebp-244h]
  unsigned int v_4r; // [esp+4h] [ebp-244h]
  unsigned int v_4s; // [esp+4h] [ebp-244h]
  Scaleform::GFx::ASString v_4t; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4u; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v_4v; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4w; // [esp+4h] [ebp-244h]
  unsigned int v_4x; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4y; // [esp+4h] [ebp-244h]
  unsigned int v_4z; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4ba; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4bb; // [esp+4h] [ebp-244h]
  unsigned int v_4bc; // [esp+4h] [ebp-244h]
  unsigned int v_4bd; // [esp+4h] [ebp-244h]
  unsigned int v_4be; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::VM *v_4bf; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4bg; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4bh; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *v_4; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4bi; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v_4bj; // [esp+4h] [ebp-244h]
  unsigned int v_4bk; // [esp+4h] [ebp-244h]
  unsigned int v_4bl; // [esp+4h] [ebp-244h]
  unsigned int v_4bm; // [esp+4h] [ebp-244h]
  unsigned int v_4bn; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Boolean3 Data; // [esp+50h] [ebp-1F8h] BYREF
  unsigned int v371; // [esp+54h] [ebp-1F4h]
  double default_offset; // [esp+58h] [ebp-1F0h] BYREF
  const unsigned int *curr_cp; // [esp+64h] [ebp-1E4h] BYREF
  unsigned int case_count; // [esp+68h] [ebp-1E0h]
  const Scaleform::GFx::AS3::Abc::ConstPool *constp; // [esp+6Ch] [ebp-1DCh]
  Scaleform::GFx::AS3::VMAbcFile *file; // [esp+70h] [ebp-1D8h]
  unsigned int call_stack_size; // [esp+74h] [ebp-1D4h]
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> r; // [esp+78h] [ebp-1D0h] BYREF
  bool tmpHandleException; // [esp+91h] [ebp-1B7h]
  bool v380; // [esp+92h] [ebp-1B6h] BYREF
  bool v381; // [esp+93h] [ebp-1B5h] BYREF
  Scaleform::GFx::AS3::CheckResult v382; // [esp+94h] [ebp-1B4h] BYREF
  Scaleform::GFx::AS3::CheckResult v383; // [esp+95h] [ebp-1B3h] BYREF
  Scaleform::GFx::AS3::CheckResult v384; // [esp+96h] [ebp-1B2h] BYREF
  Scaleform::GFx::AS3::CheckResult v385; // [esp+97h] [ebp-1B1h] BYREF
  Scaleform::GFx::AS3::CheckResult v386; // [esp+98h] [ebp-1B0h] BYREF
  Scaleform::GFx::AS3::CheckResult v387; // [esp+99h] [ebp-1AFh] BYREF
  Scaleform::GFx::AS3::CheckResult v388; // [esp+9Ah] [ebp-1AEh] BYREF
  Scaleform::GFx::AS3::CheckResult v389; // [esp+9Bh] [ebp-1ADh] BYREF
  Scaleform::GFx::AS3::CheckResult v390; // [esp+9Ch] [ebp-1ACh] BYREF
  Scaleform::GFx::AS3::CheckResult v391; // [esp+9Dh] [ebp-1ABh] BYREF
  Scaleform::GFx::AS3::CheckResult v392; // [esp+9Eh] [ebp-1AAh] BYREF
  Scaleform::GFx::AS3::CheckResult v393; // [esp+9Fh] [ebp-1A9h] BYREF
  Scaleform::GFx::AS3::CheckResult v394; // [esp+A0h] [ebp-1A8h] BYREF
  Scaleform::GFx::AS3::CheckResult v395; // [esp+A1h] [ebp-1A7h] BYREF
  Scaleform::GFx::AS3::CheckResult v396; // [esp+A2h] [ebp-1A6h] BYREF
  Scaleform::GFx::AS3::CheckResult v397; // [esp+A3h] [ebp-1A5h] BYREF
  Scaleform::GFx::AS3::CheckResult v398; // [esp+A4h] [ebp-1A4h] BYREF
  Scaleform::GFx::AS3::CheckResult v399; // [esp+A5h] [ebp-1A3h] BYREF
  Scaleform::GFx::AS3::CheckResult v400; // [esp+A6h] [ebp-1A2h] BYREF
  Scaleform::GFx::AS3::CheckResult v401; // [esp+A7h] [ebp-1A1h] BYREF
  Scaleform::GFx::AS3::CheckResult v402; // [esp+A8h] [ebp-1A0h] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [esp+A9h] [ebp-19Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v404; // [esp+AAh] [ebp-19Eh] BYREF
  Scaleform::GFx::AS3::CheckResult v405; // [esp+ABh] [ebp-19Dh] BYREF
  Scaleform::GFx::AS3::CheckResult v406; // [esp+ACh] [ebp-19Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v407; // [esp+ADh] [ebp-19Bh] BYREF
  Scaleform::GFx::AS3::CheckResult v408; // [esp+AEh] [ebp-19Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v409; // [esp+AFh] [ebp-199h] BYREF
  Scaleform::GFx::AS3::CheckResult v410; // [esp+B0h] [ebp-198h] BYREF
  Scaleform::GFx::AS3::CheckResult v411; // [esp+B1h] [ebp-197h] BYREF
  Scaleform::GFx::AS3::CheckResult v412; // [esp+B2h] [ebp-196h] BYREF
  Scaleform::GFx::AS3::CheckResult v413; // [esp+B3h] [ebp-195h] BYREF
  Scaleform::GFx::AS3::CheckResult v414; // [esp+B4h] [ebp-194h] BYREF
  Scaleform::GFx::AS3::CheckResult v415; // [esp+B5h] [ebp-193h] BYREF
  Scaleform::GFx::AS3::CheckResult v416; // [esp+B6h] [ebp-192h] BYREF
  Scaleform::GFx::AS3::CheckResult v417; // [esp+B7h] [ebp-191h] BYREF
  Scaleform::GFx::AS3::CheckResult v418; // [esp+B8h] [ebp-190h] BYREF
  Scaleform::GFx::AS3::CheckResult v419; // [esp+B9h] [ebp-18Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v420; // [esp+BAh] [ebp-18Eh] BYREF
  Scaleform::GFx::AS3::CheckResult v421; // [esp+BBh] [ebp-18Dh] BYREF
  Scaleform::GFx::AS3::CheckResult v422; // [esp+BCh] [ebp-18Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v423; // [esp+BDh] [ebp-18Bh] BYREF
  Scaleform::GFx::AS3::CheckResult v424; // [esp+BEh] [ebp-18Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v425; // [esp+BFh] [ebp-189h] BYREF
  Scaleform::GFx::AS3::CheckResult v426; // [esp+C0h] [ebp-188h] BYREF
  Scaleform::GFx::AS3::CheckResult v427; // [esp+C1h] [ebp-187h] BYREF
  Scaleform::GFx::AS3::CheckResult v428; // [esp+C2h] [ebp-186h] BYREF
  Scaleform::GFx::AS3::CheckResult v429; // [esp+C3h] [ebp-185h] BYREF
  Scaleform::GFx::AS3::CheckResult v430; // [esp+C4h] [ebp-184h] BYREF
  Scaleform::GFx::AS3::CheckResult v431; // [esp+C5h] [ebp-183h] BYREF
  Scaleform::GFx::AS3::CheckResult v432; // [esp+C6h] [ebp-182h] BYREF
  Scaleform::GFx::AS3::CheckResult v433; // [esp+C7h] [ebp-181h] BYREF
  Scaleform::GFx::AS3::CheckResult v434; // [esp+C8h] [ebp-180h] BYREF
  Scaleform::GFx::AS3::CheckResult v435; // [esp+C9h] [ebp-17Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v436; // [esp+CAh] [ebp-17Eh] BYREF
  char v437; // [esp+CBh] [ebp-17Dh] BYREF
  Scaleform::GFx::AS3::CheckResult v438; // [esp+CCh] [ebp-17Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v439; // [esp+CDh] [ebp-17Bh] BYREF
  Scaleform::GFx::AS3::CheckResult v440; // [esp+CEh] [ebp-17Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v441; // [esp+CFh] [ebp-179h] BYREF
  Scaleform::GFx::AS3::VM::Error v442; // [esp+D0h] [ebp-178h] BYREF
  Scaleform::GFx::AS3::Boolean3 v443; // [esp+DCh] [ebp-16Ch] BYREF
  char v444; // [esp+E0h] [ebp-168h]
  int v445; // [esp+E4h] [ebp-164h]
  char v446; // [esp+ECh] [ebp-15Ch]
  int v447; // [esp+F0h] [ebp-158h]
  int v448; // [esp+F8h] [ebp-150h] BYREF
  char v449; // [esp+FCh] [ebp-14Ch]
  int v450; // [esp+100h] [ebp-148h]
  char v451; // [esp+108h] [ebp-140h]
  int v452; // [esp+10Ch] [ebp-13Ch]
  Scaleform::GFx::AS3::Boolean3 v453; // [esp+114h] [ebp-134h] BYREF
  char v454; // [esp+118h] [ebp-130h]
  int v455; // [esp+11Ch] [ebp-12Ch]
  char v456; // [esp+124h] [ebp-124h]
  int v457; // [esp+128h] [ebp-120h]
  char v458; // [esp+130h] [ebp-118h]
  int v459; // [esp+134h] [ebp-114h]
  bool v460[4]; // [esp+13Ch] [ebp-10Ch] BYREF
  char v461; // [esp+140h] [ebp-108h]
  int v462; // [esp+144h] [ebp-104h]
  Scaleform::GFx::AS3::Boolean3 v463; // [esp+14Ch] [ebp-FCh] BYREF
  char v464; // [esp+150h] [ebp-F8h]
  int v465; // [esp+154h] [ebp-F4h]
  Scaleform::GFx::AS3::Boolean3 v466; // [esp+15Ch] [ebp-ECh] BYREF
  Scaleform::GFx::AS3::Value tmpExceptionValue; // [esp+160h] [ebp-E8h] BYREF
  Scaleform::GFx::AS3::Value::V1U v468; // [esp+170h] [ebp-D8h]
  Scaleform::GFx::AS3::Value::V2U v469; // [esp+174h] [ebp-D4h]
  long double Double; // [esp+178h] [ebp-D0h]
  Scaleform::GFx::AS3::Value v471; // [esp+180h] [ebp-C8h] BYREF
  Scaleform::GFx::AS3::Value::V1U v472; // [esp+190h] [ebp-B8h]
  Scaleform::GFx::AS3::Value::V2U v473; // [esp+194h] [ebp-B4h]
  Scaleform::StringDataPtr v474; // [esp+198h] [ebp-B0h] BYREF
  double v475; // [esp+1A0h] [ebp-A8h]
  Scaleform::GFx::AS3::Value other; // [esp+1A8h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value v477; // [esp+1B8h] [ebp-90h] BYREF
  long double v478; // [esp+1C8h] [ebp-80h] BYREF
  long double v479; // [esp+1D0h] [ebp-78h] BYREF
  long double v480; // [esp+1D8h] [ebp-70h] BYREF
  Scaleform::GFx::AS3::VM::Error v481; // [esp+1E0h] [ebp-68h] BYREF
  char v482; // [esp+1E8h] [ebp-60h]
  long double v483; // [esp+1F0h] [ebp-58h]
  char v484; // [esp+200h] [ebp-48h]
  double v485; // [esp+208h] [ebp-40h]
  long double v486; // [esp+218h] [ebp-30h] BYREF
  char v487; // [esp+220h] [ebp-28h]
  double v488; // [esp+228h] [ebp-20h]
  Scaleform::GFx::AS3::Value v489; // [esp+238h] [ebp-10h] BYREF

  v118 = this->CallStack.Size == 0;
  v371 = 0;
  if ( v118 )
    return max_stack_depth;
  while ( 1 )
  {
    Pages = this->CallStack.Pages;
    call_stack_size = this->CallStack.Size;
    v4 = Pages[(call_stack_size - 1) >> 6];
    LOBYTE(Pages) = this->HandleException;
    v5 = &v4[(call_stack_size - 1) & 0x3F];
    pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
    p_ExceptionObj = &this->ExceptionObj;
    file = v5->pFile;
    pObject = file->File.pObject;
    tmpHandleException = (char)Pages;
    tmpExceptionValue.value.VS._1.VInt = this->ExceptionObj.value.VS._1.VInt;
    v9.VObj = (Scaleform::GFx::AS3::Object *)this->ExceptionObj.value.VS._2;
    constp = &pObject->Const_Pool;
    Flags = this->ExceptionObj.Flags;
    tmpExceptionValue.value.VS._2 = v9;
    tmpExceptionValue.Flags = Flags;
    tmpExceptionValue.Bonus.pWeakProxy = pWeakProxy;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        ++pWeakProxy->RefCount;
      else
        Scaleform::GFx::AS3::Value::AddRefInternal(&this->ExceptionObj);
    }
    this->HandleException = 0;
    if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
    {
      if ( (p_ExceptionObj->Flags & 0x200) != 0 )
      {
        v11 = this->ExceptionObj.Bonus.pWeakProxy;
        v118 = v11->RefCount-- == 1;
        if ( v118 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
        p_ExceptionObj->Flags &= 0xFFFFFDE0;
        this->ExceptionObj.Bonus.pWeakProxy = 0;
        this->ExceptionObj.value.VS._1.VInt = 0;
        this->ExceptionObj.value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&this->ExceptionObj);
      }
    }
    p_ExceptionObj->Flags = 0;
    if ( !v5->CP )
      v5->CP = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
    v118 = !this->HandleException;
    CP = (unsigned int *)v5->CP;
    _mm_prefetch((const char *)CP, 2);
    if ( !v118 )
      goto LABEL_588;
    if ( tmpHandleException )
    {
      this->HandleException = tmpHandleException;
      Scaleform::GFx::AS3::Value::Assign(&this->ExceptionObj, &tmpExceptionValue);
    }
LABEL_17:
    if ( !this->HandleException )
      goto $LN436;
    Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
    v13 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - Data) >> 2, (unsigned int)v5);
    if ( v13 >= 0 )
    {
      v14 = Data;
LABEL_20:
      CP = (unsigned int *)(v14 + 4 * v13);
$LN436:
      while ( 2 )
      {
        v15 = *CP;
        curr_cp = CP++;
        switch ( v15 )
        {
          case 3u:
            v16 = Scaleform::GFx::AS3::VM::exec_throw(this, CP, v5);
            if ( v16 < 0 )
              goto LABEL_587;
            CP = &Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data[v16];
            continue;
          case 4u:
            v_4a = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_getsuper(
              this,
              file,
              (Scaleform::GFx::AS3::Traits *)v5->OriginationTraits,
              v_4a);
            goto LABEL_17;
          case 5u:
            v17 = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_setsuper(
              this,
              file,
              (Scaleform::GFx::AS3::Traits *)v5->OriginationTraits,
              v17);
            goto LABEL_26;
          case 6u:
            v_4b = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*CP++;
            InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(v5->pFile, v_4b);
            curr_cp = (const unsigned int *)InternedNamespace;
            if ( InternedNamespace )
              InternedNamespace->RefCount = (InternedNamespace->RefCount + 1) & 0x8FBFFFFF;
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->DefXMLNamespace,
              (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&curr_cp);
            if ( curr_cp )
            {
              if ( ((unsigned __int8)curr_cp & 1) == 0 )
              {
                v20 = curr_cp[4];
                if ( ((unsigned int)&byte_3FFFFF & v20) != 0 )
                {
                  v21 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)curr_cp;
                  *((_DWORD *)curr_cp + 4) = v20 - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v21);
                }
              }
            }
            goto LABEL_17;
          case 7u:
            Scaleform::GFx::AS3::VM::exec_dxnslate(this);
LABEL_26:
            if ( !this->HandleException )
              continue;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v18 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - Data) >> 2, (unsigned int)v5);
            if ( v18 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(Data + 4 * v18);
            continue;
          case 8u:
            v22 = *CP++;
            Data = v22;
            if ( (_S10_0 & 1) == 0 )
            {
              _S10_0 |= 1u;
              ::v.Flags = 0;
              ::v.Bonus.pWeakProxy = 0;
              atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
            }
            Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[Data], &::v);
            continue;
          case 0xAu:
            p_value = &this->RegisterFile.pRF[*CP++].value;
            ++p_value->VS._1.VInt;
            continue;
          case 0xBu:
            v292 = &this->RegisterFile.pRF[*CP++].value;
            --v292->VS._1.VInt;
            continue;
          case 0xCu:
            v_4c = this->OpStack.pCurrent;
            Data = *CP;
            v23 = (__int32)(CP + 1);
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&result, &v443, v_4c - 1, v_4c)->Result && v443 != true3 )
              curr_cp = (const unsigned int *)Data;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_45;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v24 = Scaleform::GFx::AS3::VM::OnException(this, (v23 - Data) >> 2, (unsigned int)v5);
            if ( v24 < 0 )
              goto LABEL_587;
            v23 = Data + 4 * v24;
LABEL_45:
            CP = (unsigned int *)(v23 + 4 * (_DWORD)curr_cp);
            continue;
          case 0xDu:
            pCurrent = this->OpStack.pCurrent;
            Data = *CP;
            v37 = (__int32)(CP + 1);
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v391, &v453, pCurrent, pCurrent - 1)->Result && v453 != false3 )
              curr_cp = (const unsigned int *)Data;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_58;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v38 = Scaleform::GFx::AS3::VM::OnException(this, (v37 - Data) >> 2, (unsigned int)v5);
            if ( v38 < 0 )
              goto LABEL_587;
            v37 = Data + 4 * v38;
LABEL_58:
            CP = (unsigned int *)(v37 + 4 * (_DWORD)curr_cp);
            continue;
          case 0xEu:
            v46 = this->OpStack.pCurrent;
            Data = *CP;
            v37 = (__int32)(CP + 1);
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v393, &v463, v46, v46 - 1)->Result && v463 != true3 )
              curr_cp = (const unsigned int *)Data;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_58;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v47 = Scaleform::GFx::AS3::VM::OnException(this, (v37 - Data) >> 2, (unsigned int)v5);
            if ( v47 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(Data + 4 * v47 + 4 * (_DWORD)curr_cp);
            continue;
          case 0xFu:
            v_4d = this->OpStack.pCurrent;
            Data = *CP;
            v37 = (__int32)(CP + 1);
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v395, &v466, v_4d - 1, v_4d)->Result && v466 != false3 )
              curr_cp = (const unsigned int *)Data;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_58;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v55 = Scaleform::GFx::AS3::VM::OnException(this, (v37 - Data) >> 2, (unsigned int)v5);
            if ( v55 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(Data + 4 * v55 + 4 * (_DWORD)curr_cp);
            continue;
          case 0x10u:
            CP += *CP + 1;
            continue;
          case 0x11u:
            v63 = this->OpStack.pCurrent;
            Data = *CP;
            v64 = CP + 1;
            curr_cp = &v63->Flags;
            v65 = Scaleform::GFx::AS3::Value::Convert2Boolean(v63);
            Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)curr_cp, v65);
            v66 = *((_BYTE *)curr_cp + 8);
            --this->OpStack.pCurrent;
            v67 = undefined3;
            if ( v66 == 1 )
              v67 = Data;
            goto LABEL_86;
          case 0x12u:
            v73 = this->OpStack.pCurrent;
            Data = *CP;
            v64 = CP + 1;
            curr_cp = &v73->Flags;
            v74 = Scaleform::GFx::AS3::Value::Convert2Boolean(v73);
            Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)curr_cp, v74);
            v75 = *((_BYTE *)curr_cp + 8);
            --this->OpStack.pCurrent;
            v67 = undefined3;
            if ( v75 )
LABEL_86:
              CP = &v64[v67];
            else
              CP = &v64[Data];
            continue;
          case 0x13u:
            Data = *CP;
            v_4e = this->OpStack.pCurrent;
            v37 = (__int32)(CP + 1);
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractEqual(&v397, &v381, v_4e - 1, v_4e)->Result && v381 )
              curr_cp = (const unsigned int *)Data;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_58;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v79 = Scaleform::GFx::AS3::VM::OnException(this, (v37 - Data) >> 2, (unsigned int)v5);
            if ( v79 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(Data + 4 * v79 + 4 * (_DWORD)curr_cp);
            continue;
          case 0x14u:
            v_4f = this->OpStack.pCurrent;
            Data = *CP;
            v37 = (__int32)(CP + 1);
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractEqual(&v399, &v380, v_4f - 1, v_4f)->Result && !v380 )
              curr_cp = (const unsigned int *)Data;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_58;
            Data = (Scaleform::GFx::AS3::Boolean3)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v87 = Scaleform::GFx::AS3::VM::OnException(this, (v37 - Data) >> 2, (unsigned int)v5);
            if ( v87 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(Data + 4 * v87 + 4 * (_DWORD)curr_cp);
            continue;
          case 0x15u:
            v_4g = this->OpStack.pCurrent;
            case_count = *CP;
            v95 = (unsigned int)(CP + 1);
            Data = undefined3;
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v401, (Scaleform::GFx::AS3::Boolean3 *)&curr_cp, v_4g - 1, v_4g)->Result
              && curr_cp == (const unsigned int *)1 )
            {
              Data = case_count;
            }
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_120;
            case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v96 = Scaleform::GFx::AS3::VM::OnException(this, (int)(v95 - case_count) >> 2, (unsigned int)v5);
            if ( v96 < 0 )
              goto LABEL_587;
            v95 = case_count + 4 * v96;
LABEL_120:
            CP = (unsigned int *)(v95 + 4 * Data);
            continue;
          case 0x16u:
            v102 = this->OpStack.pCurrent;
            case_count = *CP;
            v103 = (unsigned int)(CP + 1);
            curr_cp = 0;
            Data = undefined3;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v438, &Data, v102, v102 - 1)->Result && Data == false3 )
              curr_cp = (const unsigned int *)case_count;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_130;
            case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v104 = Scaleform::GFx::AS3::VM::OnException(this, (int)(v103 - case_count) >> 2, (unsigned int)v5);
            if ( v104 < 0 )
              goto LABEL_587;
            v103 = case_count + 4 * v104;
LABEL_130:
            CP = (unsigned int *)(v103 + 4 * (_DWORD)curr_cp);
            continue;
          case 0x17u:
            v108 = this->OpStack.pCurrent;
            case_count = *CP;
            v103 = (unsigned int)(CP + 1);
            curr_cp = 0;
            Data = undefined3;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v440, &Data, v108, v108 - 1)->Result && Data == true3 )
              curr_cp = (const unsigned int *)case_count;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_130;
            case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v109 = Scaleform::GFx::AS3::VM::OnException(this, (int)(v103 - case_count) >> 2, (unsigned int)v5);
            if ( v109 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(case_count + 4 * v109 + 4 * (_DWORD)curr_cp);
            continue;
          case 0x18u:
            v_4h = this->OpStack.pCurrent;
            case_count = *CP;
            v103 = (unsigned int)(CP + 1);
            curr_cp = 0;
            Data = undefined3;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v423, &Data, v_4h - 1, v_4h)->Result && Data == false3 )
              curr_cp = (const unsigned int *)case_count;
            Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
            if ( !this->HandleException )
              goto LABEL_130;
            case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v113 = Scaleform::GFx::AS3::VM::OnException(this, (int)(v103 - case_count) >> 2, (unsigned int)v5);
            if ( v113 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(case_count + 4 * v113 + 4 * (_DWORD)curr_cp);
            continue;
          case 0x19u:
            v119 = this->OpStack.pCurrent;
            case_count = *CP;
            v120 = CP + 1;
            curr_cp = 0;
            if ( Scaleform::GFx::AS3::StrictEqual(v119, v119 - 1) )
              curr_cp = (const unsigned int *)case_count;
            v121 = this->OpStack.pCurrent;
            v122 = v121->Flags;
            v123 = v121->Flags & 0x1F;
            Data = (Scaleform::GFx::AS3::Boolean3)v121;
            if ( (char)v123 > 9 )
            {
              if ( (v122 & 0x200) != 0 )
              {
                v124 = v121->Bonus.pWeakProxy;
                v118 = v124->RefCount-- == 1;
                if ( v118 )
                {
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v124);
                  v121 = (Scaleform::GFx::AS3::Value *)Data;
                }
                v121->Flags &= 0xFFFFFDE0;
                v121->Bonus.pWeakProxy = 0;
                v121->value.VS._1.VInt = 0;
                v121->value.VS._2.VObj = 0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(v121);
              }
            }
            v125 = --this->OpStack.pCurrent;
            v126 = v125->Flags;
            v127 = v125->Flags & 0x1F;
            Data = (Scaleform::GFx::AS3::Boolean3)v125;
            if ( (char)v127 <= 9 )
              goto LABEL_169;
            if ( (v126 & 0x200) == 0 )
              goto LABEL_168;
            v128 = v125->Bonus.pWeakProxy;
            v118 = v128->RefCount-- == 1;
            if ( v118 )
              goto LABEL_166;
            goto LABEL_167;
          case 0x1Au:
            v131 = this->OpStack.pCurrent;
            case_count = *CP;
            v120 = CP + 1;
            curr_cp = 0;
            if ( !Scaleform::GFx::AS3::StrictEqual(v131, v131 - 1) )
              curr_cp = (const unsigned int *)case_count;
            v132 = this->OpStack.pCurrent;
            v133 = v132->Flags;
            v134 = v132->Flags & 0x1F;
            Data = (Scaleform::GFx::AS3::Boolean3)v132;
            if ( (char)v134 > 9 )
            {
              if ( (v133 & 0x200) != 0 )
              {
                v135 = v132->Bonus.pWeakProxy;
                v118 = v135->RefCount-- == 1;
                if ( v118 )
                {
                  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v135);
                  v132 = (Scaleform::GFx::AS3::Value *)Data;
                }
                v132->Flags &= 0xFFFFFDE0;
                v132->Bonus.pWeakProxy = 0;
                v132->value.VS._1.VInt = 0;
                v132->value.VS._2.VObj = 0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(v132);
              }
            }
            v125 = --this->OpStack.pCurrent;
            v136 = v125->Flags;
            v137 = v125->Flags & 0x1F;
            Data = (Scaleform::GFx::AS3::Boolean3)v125;
            if ( (char)v137 <= 9 )
              goto LABEL_169;
            if ( (v136 & 0x200) != 0 )
            {
              v128 = v125->Bonus.pWeakProxy;
              v118 = v128->RefCount-- == 1;
              if ( v118 )
              {
LABEL_166:
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v128);
                v125 = (Scaleform::GFx::AS3::Value *)Data;
              }
LABEL_167:
              v125->Bonus.pWeakProxy = 0;
              v125->value.VS._1.VInt = 0;
              v125->value.VS._2.VObj = 0;
              v125->Flags &= 0xFFFFFDE0;
              v129 = curr_cp;
              --this->OpStack.pCurrent;
              CP = &v120[(_DWORD)v129];
            }
            else
            {
LABEL_168:
              Scaleform::GFx::AS3::Value::ReleaseInternal(v125);
LABEL_169:
              v130 = curr_cp;
              --this->OpStack.pCurrent;
              CP = &v120[(_DWORD)v130];
            }
            continue;
          case 0x1Bu:
            v138 = this->OpStack.pCurrent;
            v139 = CP[1];
            LODWORD(default_offset) = *CP;
            v140 = CP + 1;
            Data = v138->value.VS._1.VInt;
            case_count = v139;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(v138, 0);
            --this->OpStack.pCurrent;
            if ( Data < undefined3 || Data > case_count )
              CP = (unsigned int *)&curr_cp[LODWORD(default_offset)];
            else
              CP = (unsigned int *)&curr_cp[v140[Data + 1]];
            continue;
          case 0x1Cu:
            Scaleform::GFx::AS3::VM::exec_pushwith(this);
            goto LABEL_187;
          case 0x1Du:
            Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
              &this->ScopeStack.Data,
              this->ScopeStack.Data.Size - 1);
            continue;
          case 0x1Eu:
            Scaleform::GFx::AS3::VM::exec_nextname(this);
            goto LABEL_187;
          case 0x1Fu:
            Scaleform::GFx::AS3::VM::exec_hasnext(this);
            goto LABEL_193;
          case 0x20u:
            ++this->OpStack.pCurrent;
            pNode = v442.Message.pNode;
            this->OpStack.pCurrent->Flags = 0;
            v143 = this->OpStack.pCurrent;
            v143->Flags = v143->Flags & 0xFFFFFFE0 | 0xC;
            v143->value.VS._1.VInt = 0;
            v143->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
            continue;
          case 0x21u:
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            this->OpStack.pCurrent->Flags &= 0xFFFFFFE0;
            continue;
          case 0x22u:
            this->OpStack.pCurrent->value.VS._1.VBool = !this->OpStack.pCurrent->value.VS._1.VBool;
            continue;
          case 0x23u:
            Scaleform::GFx::AS3::VM::exec_nextvalue(this);
            goto LABEL_193;
          case 0x24u:
            v144 = *CP;
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            v145 = this->OpStack.pCurrent;
            v146 = v145->Flags & 0xFFFFFFE2;
            ++CP;
            v145->value.VS._1.VInt = (char)v144;
            v147 = v442.Message.pNode;
            v145->Flags = v146 | 2;
            v145->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v147;
            continue;
          case 0x25u:
            v148 = *CP;
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            v149 = this->OpStack.pCurrent;
            v150 = v149->Flags & 0xFFFFFFE2;
            ++CP;
            v149->value.VS._1.VInt = v148;
            v151 = v442.Message.pNode;
            v149->Flags = v150 | 2;
            v149->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v151;
            continue;
          case 0x26u:
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            v152 = this->OpStack.pCurrent;
            v152->Flags = v152->Flags & 0xFFFFFFE0 | 1;
            v153.VObj = v469.VObj;
            v468.VBool = 1;
            v152->value.VS._1 = v468;
            v152->value.VS._2 = v153;
            continue;
          case 0x27u:
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            v154 = this->OpStack.pCurrent;
            v154->Flags = v154->Flags & 0xFFFFFFE0 | 1;
            v155.VObj = v473.VObj;
            v472.VBool = 0;
            v154->value.VS._1 = v472;
            v154->value.VS._2 = v155;
            continue;
          case 0x28u:
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            LODWORD(default_offset) = this->OpStack.pCurrent;
            v475 = Scaleform::GFx::NumberUtil::NaN();
            v156 = LODWORD(default_offset);
            v157 = LODWORD(v475);
            *(_DWORD *)LODWORD(default_offset) = *(_DWORD *)LODWORD(default_offset) & 0xFFFFFFE0 | 4;
            v158 = HIDWORD(v475);
            *(_DWORD *)(v156 + 8) = v157;
            *(_DWORD *)(v156 + 12) = v158;
            continue;
          case 0x29u:
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            goto $LN199_0;
          case 0x2Au:
            pRF = this->OpStack.pCurrent;
            this->OpStack.pCurrent = pRF + 1;
            v160 = this->OpStack.pCurrent;
            if ( pRF == (Scaleform::GFx::AS3::Value *)-16 )
              continue;
            v160->Flags = pRF->Flags;
            v160->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
            v160->value.VS._1.VInt = pRF->value.VS._1.VInt;
            v160->value.VS._2.VObj = pRF->value.VS._2.VObj;
            if ( (pRF->Flags & 0x1F) <= 9 )
              continue;
            if ( (pRF->Flags & 0x200) == 0 )
              goto LABEL_259;
            ++pRF->Bonus.pWeakProxy->RefCount;
            continue;
          case 0x2Bu:
            Scaleform::GFx::AS3::VSBase::SwapTop(&this->OpStack);
            continue;
          case 0x2Cu:
            v_4j.Index = *CP++;
            String = Scaleform::GFx::AS3::Abc::ConstPool::GetString(
                       (Scaleform::GFx::AS3::Abc::ConstPool *)constp,
                       &v474,
                       v_4j);
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                           this->StringManagerRef->pStringManager,
                           (char *)String->pStr,
                           String->Size);
            ++StringNode->RefCount;
            v163 = this->OpStack.pCurrent;
            curr_cp = (const unsigned int *)StringNode;
            Scaleform::GFx::AS3::Value::AssignUnsafe(v163, (const Scaleform::GFx::ASString *)&curr_cp);
            v164 = (Scaleform::GFx::ASStringNode *)curr_cp;
            v118 = curr_cp[3]-- == 1;
            if ( v118 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v164);
            continue;
          case 0x2Du:
            v165 = constp->ConstInt.Data.Data[*CP];
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            v166 = this->OpStack.pCurrent;
            ++CP;
            v166->Flags = v166->Flags & 0xFFFFFFE0 | 2;
            v166->value.VS._1.VInt = v165;
            v166->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v474.Size;
            continue;
          case 0x2Eu:
            v167 = constp->ConstUInt.Data.Data[*CP];
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            v168 = this->OpStack.pCurrent;
            ++CP;
            v168->Flags = v168->Flags & 0xFFFFFFE0 | 3;
            v168->value.VS._1.VInt = v167;
            v168->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v474.Size;
            continue;
          case 0x2Fu:
            v_4k = *CP++;
            Double = Scaleform::GFx::AS3::Abc::ConstPool::GetDouble((Scaleform::GFx::AS3::Abc::ConstPool *)constp, v_4k);
            ++this->OpStack.pCurrent;
            v169 = LODWORD(Double);
            this->OpStack.pCurrent->Flags = 0;
            v170 = this->OpStack.pCurrent;
            v170->Flags = v170->Flags & 0xFFFFFFE0 | 4;
            v171.VObj = *(Scaleform::GFx::AS3::Object **)((char *)&Double + 4);
            v170->value.VS._1 = v169;
            v170->value.VS._2 = v171;
            continue;
          case 0x30u:
            Scaleform::GFx::AS3::VM::exec_pushscope(this);
            goto LABEL_187;
          case 0x31u:
            v_4l = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*CP++;
            v172 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v_4l);
            ++this->OpStack.pCurrent;
            this->OpStack.pCurrent->Flags = 0;
            Scaleform::GFx::AS3::Value::AssignUnsafe(this->OpStack.pCurrent, v172);
            continue;
          case 0x32u:
            v173.VInt = *CP;
            v174.Index = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_hasnext2(this, v173, v174);
            goto LABEL_193;
          case 0x33u:
            v68 = this->OpStack.pCurrent;
            VBool = v68->value.VS._1.VBool;
            v70 = *CP;
            this->OpStack.pCurrent = v68 - 1;
            v71 = CP + 1;
            v72 = 0;
            if ( VBool )
              v72 = v70;
            goto LABEL_89;
          case 0x34u:
            v76 = this->OpStack.pCurrent;
            v77 = v76->value.VS._1.VBool;
            v78 = *CP;
            this->OpStack.pCurrent = v76 - 1;
            v71 = CP + 1;
            v72 = 0;
            if ( v77 )
LABEL_89:
              CP = &v71[v72];
            else
              CP = &v71[v78];
            continue;
          case 0x35u:
          case 0x98u:
            ++this->OpStack.pCurrent->value.VS._1.VInt;
            continue;
          case 0x36u:
          case 0x99u:
            --this->OpStack.pCurrent->value.VS._1.VInt;
            continue;
          case 0x37u:
            v175 = &this->RegisterFile.pRF[*CP++].value;
            ++v175->VS._1.VInt;
            continue;
          case 0x38u:
            v176 = &this->RegisterFile.pRF[*CP++].value;
            --v176->VS._1.VInt;
            continue;
          case 0x3Fu:
            this->OpStack.pCurrent->value.VS._1.VInt = -this->OpStack.pCurrent->value.VS._1.VInt;
            continue;
          case 0x40u:
            v_4m = *CP++;
            Scaleform::GFx::AS3::VM::exec_newfunction(this, (Scaleform::GFx::AS3::Instances::FunctionBase *)v5, v_4m);
            continue;
          case 0x41u:
            v_4n = *CP++;
            Scaleform::GFx::AS3::VM::exec_call(this, v_4n);
            goto LABEL_226;
          case 0x42u:
            v_4o = *CP++;
            Scaleform::GFx::AS3::VM::exec_construct(this, v_4o);
            goto LABEL_226;
          case 0x43u:
            v178 = *CP;
            v179 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callmethod(this, v178, v179);
            goto LABEL_226;
          case 0x44u:
            v186.Ind = *CP;
            v187 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callstatic(this, file, v186, v187);
            goto LABEL_226;
          case 0x45u:
            v188 = *CP;
            v189 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callsuper(
              this,
              file,
              (Scaleform::GFx::AS3::Traits *)v5->OriginationTraits,
              &constp->const_multiname.Data.Data[v188],
              v189);
            goto LABEL_226;
          case 0x46u:
            v190 = *CP;
            v191 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callproperty(this, file, &constp->const_multiname.Data.Data[v190], v191);
            goto LABEL_226;
          case 0x47u:
            Scaleform::GFx::AS3::VM::exec_returnvoid(this);
            goto LABEL_587;
          case 0x48u:
            Scaleform::GFx::AS3::VM::exec_returnvalue(this);
            if ( !this->HandleException )
              goto LABEL_589;
            OpCode = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5);
            Scaleform::GFx::AS3::VM::OnException(this, CP - OpCode->Data.Data, (unsigned int)v5);
            goto LABEL_587;
          case 0x49u:
            v_4p = *CP++;
            Scaleform::GFx::AS3::VM::exec_constructsuper(this, v5->OriginationTraits, v_4p);
            goto LABEL_226;
          case 0x4Au:
            v192 = *CP;
            v193 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_constructprop(this, file, &constp->const_multiname.Data.Data[v192], v193);
            goto LABEL_226;
          case 0x4Cu:
            v194 = *CP;
            v195 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callproplex(this, file, &constp->const_multiname.Data.Data[v194], v195);
            goto LABEL_226;
          case 0x4Eu:
            v196 = *CP;
            v197 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callsupervoid(
              this,
              file,
              (Scaleform::GFx::AS3::Traits *)v5->OriginationTraits,
              &constp->const_multiname.Data.Data[v196],
              v197);
            goto LABEL_226;
          case 0x4Fu:
            v198 = *CP;
            v199 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callpropvoid(this, file, &constp->const_multiname.Data.Data[v198], v199);
            goto LABEL_226;
          case 0x53u:
            v_4q = *CP++;
            Scaleform::GFx::AS3::VM::exec_applytype(this, v_4q);
            goto LABEL_187;
          case 0x54u:
            this->OpStack.pCurrent->value.VNumber = -this->OpStack.pCurrent->value.VNumber;
            continue;
          case 0x55u:
            v_4r = *CP++;
            Scaleform::GFx::AS3::VM::exec_newobject(this, v_4r);
            continue;
          case 0x56u:
            v_4s = *CP++;
            Scaleform::GFx::AS3::VM::exec_newarray(this, v_4s);
            continue;
          case 0x57u:
            Scaleform::GFx::AS3::VM::exec_newactivation(this, (int)v5);
            continue;
          case 0x58u:
            v_4t.pNode = (Scaleform::GFx::ASStringNode *)*CP++;
            Scaleform::GFx::AS3::VM::exec_newclass(this, (Scaleform::GFx::ASStringNode *)file, v_4t);
            goto LABEL_226;
          case 0x59u:
            v_4u = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_getdescendants(this, file, v_4u);
            goto LABEL_187;
          case 0x5Au:
            v_4v = &v5->pFile->Exceptions.Data.Data[v5->MBIIndex.Ind].info.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_newcatch(this, file, v_4v);
            continue;
          case 0x5Du:
            va = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_findpropstrict(this, file, va, v5->pSavedScope);
            goto LABEL_187;
          case 0x5Eu:
            ++CP;
            GlobalObject = Scaleform::GFx::AS3::CallFrame::GetGlobalObject(v5);
            Scaleform::GFx::AS3::VM::exec_findproperty(
              this,
              file,
              &constp->const_multiname.Data.Data[v201],
              v5->pSavedScope,
              GlobalObject);
            goto LABEL_187;
          case 0x60u:
            vb = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_getlex(this, file, vb, v5->pSavedScope);
            goto LABEL_187;
          case 0x61u:
            v_4w = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_setproperty(this, file, v_4w);
            goto LABEL_187;
          case 0x62u:
            v202 = &this->RegisterFile.pRF[*CP++];
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v203 = this->OpStack.pCurrent;
            if ( v118 )
              continue;
            v203->Flags = v202->Flags;
            v203->Bonus.pWeakProxy = v202->Bonus.pWeakProxy;
            v203->value.VS._1.VInt = v202->value.VS._1.VInt;
            v203->value.VS._2.VObj = v202->value.VS._2.VObj;
            if ( (v202->Flags & 0x1F) <= 9 )
              continue;
            if ( (v202->Flags & 0x200) != 0 )
            {
              ++v202->Bonus.pWeakProxy->RefCount;
            }
            else
            {
              pRF = v202;
LABEL_259:
              Scaleform::GFx::AS3::Value::AddRefInternal(pRF);
            }
            continue;
          case 0x63u:
            v204 = &this->RegisterFile.pRF[*CP++];
            Scaleform::GFx::AS3::Value::Pick(v204, this->OpStack.pCurrent);
            --this->OpStack.pCurrent;
            continue;
          case 0x64u:
            v205 = Scaleform::GFx::AS3::VM::GetGlobalObject(this);
            v206 = v205;
            v471.Flags = 12;
            v471.Bonus.pWeakProxy = 0;
            v471.value.VS._1.VInt = (int)v205;
            if ( v205 )
              v205->RefCount = (v205->RefCount + 1) & 0x8FBFFFFF;
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v207 = this->OpStack.pCurrent;
            if ( !v118 )
            {
              v207->value.VS._1.VInt = (int)v206;
              v207->value.VS._2.VObj = v471.value.VS._2.VObj;
              v207->Flags = 12;
              v207->Bonus.pWeakProxy = 0;
              Scaleform::GFx::AS3::Value::AddRefInternal(&v471);
            }
            Scaleform::GFx::AS3::Value::~Value(&v471);
            continue;
          case 0x65u:
            v_4x = *CP++ + v5->ScopeStackBaseInd;
            Scaleform::GFx::AS3::VM::exec_getscopeobject(this, v_4x);
            continue;
          case 0x66u:
            v_4y = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_getproperty(this, file, v_4y);
            goto LABEL_187;
          case 0x67u:
            v_4z = *CP++;
            Scaleform::GFx::AS3::VM::exec_getouterscope(this, v5, v_4z);
            continue;
          case 0x68u:
            v_4ba = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_initproperty(this, file, v_4ba);
            goto LABEL_187;
          case 0x69u:
            v208 = this->OpStack.pCurrent;
            this->OpStack.pCurrent = v208 + 1;
            v209 = this->OpStack.pCurrent;
            if ( v208 != (Scaleform::GFx::AS3::Value *)-16 )
            {
              v209->Flags = v208->Flags;
              v209->Bonus.pWeakProxy = v208->Bonus.pWeakProxy;
              v209->value.VS._1.VInt = v208->value.VS._1.VInt;
              v209->value.VS._2.VObj = v208->value.VS._2.VObj;
            }
            continue;
          case 0x6Au:
            v_4bb = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_deleteproperty(this, file, v_4bb);
            goto LABEL_187;
          case 0x6Bu:
$LN199_0:
            --this->OpStack.pCurrent;
            continue;
          case 0x6Cu:
            v_4bc = *CP++;
            Scaleform::GFx::AS3::VM::exec_getslot(this, v_4bc);
            goto LABEL_193;
          case 0x6Du:
            v_4bd = *CP++;
            Scaleform::GFx::AS3::VM::exec_setslot(this, v_4bd);
            goto LABEL_187;
          case 0x6Eu:
            v_4be = *CP++;
            Scaleform::GFx::AS3::VM::exec_getglobalslot(this, v_4be);
            goto LABEL_193;
          case 0x6Fu:
            v_4bf = (Scaleform::GFx::AS3::VM *)*CP++;
            Scaleform::GFx::AS3::VM::exec_setglobalslot(this, v_4bf);
            goto LABEL_187;
          case 0x70u:
            Scaleform::GFx::AS3::Value::ToStringValue(
              this->OpStack.pCurrent,
              &v384,
              (Scaleform::GFx::ASStringNode *)this->StringManagerRef);
            goto LABEL_187;
          case 0x71u:
            Scaleform::GFx::AS3::VM::exec_esc_xelem(this);
            goto LABEL_193;
          case 0x72u:
            Scaleform::GFx::AS3::VM::exec_esc_xattr(this);
            goto LABEL_187;
          case 0x73u:
            Scaleform::GFx::AS3::Value::ToInt32Value(this->OpStack.pCurrent, &v416);
            goto LABEL_187;
          case 0x74u:
            Scaleform::GFx::AS3::Value::ToUInt32Value(this->OpStack.pCurrent, &v386);
            goto LABEL_187;
          case 0x75u:
            Scaleform::GFx::AS3::Value::ToNumberValue(this->OpStack.pCurrent, &v418);
            goto LABEL_187;
          case 0x76u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            v210 = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)LODWORD(default_offset));
            Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), v210);
            continue;
          case 0x77u:
            v211 = this->OpStack.pCurrent;
            if ( (v211->Flags & 0x1F) == 0 || (v211->Flags & 0x1F) - 12 <= 3 && !v211->value.VS._1.VInt )
            {
              Scaleform::GFx::AS3::VM::Error::Error(&v481, eConvertNullToObjectError, this);
              Scaleform::GFx::AS3::VM::ThrowErrorInternal(
                this,
                v212,
                (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
              v213 = v481.Message.pNode;
              --v481.Message.pNode->RefCount;
              if ( !v213->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v213);
            }
            goto LABEL_187;
          case 0x78u:
            Scaleform::GFx::AS3::VM::exec_checkfilter(this);
            continue;
          case 0x79u:
            v297 = this->OpStack.pCurrent;
            v298 = v297->value.VS._1;
            this->OpStack.pCurrent = v297 - 1;
            v297[-1].value.VS._1.VInt += v298.VInt;
            continue;
          case 0x7Au:
            v305 = this->OpStack.pCurrent;
            v306 = v305->value.VS._1;
            this->OpStack.pCurrent = v305 - 1;
            v305[-1].value.VS._1.VInt -= v306.VInt;
            continue;
          case 0x7Bu:
            v313 = this->OpStack.pCurrent;
            v314 = v313->value.VS._1;
            this->OpStack.pCurrent = v313 - 1;
            v313[-1].value.VS._1.VInt *= v314.VInt;
            continue;
          case 0x7Cu:
            v299 = this->OpStack.pCurrent;
            VNumber = v299->value.VNumber;
            this->OpStack.pCurrent = v299 - 1;
            v299[-1].value.VNumber = VNumber + v299[-1].value.VNumber;
            continue;
          case 0x7Du:
            v307 = this->OpStack.pCurrent;
            v308 = v307->value.VNumber;
            this->OpStack.pCurrent = v307 - 1;
            v307[-1].value.VNumber = v307[-1].value.VNumber - v308;
            continue;
          case 0x7Eu:
            v315 = this->OpStack.pCurrent;
            v316 = v315->value.VNumber;
            this->OpStack.pCurrent = v315 - 1;
            v315[-1].value.VNumber = v316 * v315[-1].value.VNumber;
            continue;
          case 0x7Fu:
            v238 = this->OpStack.pCurrent;
            v239 = v238->value.VNumber;
            this->OpStack.pCurrent = v238 - 1;
            v238[-1].value.VNumber = v238[-1].value.VNumber / v239;
            continue;
          case 0x80u:
            v_4bg = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_coerce(this, file, v_4bg);
            goto LABEL_187;
          case 0x85u:
            v214 = this->OpStack.pCurrent;
            if ( (v214->Flags & 0x1F) != 0 && ((v214->Flags & 0x1F) - 12 > 3 || v214->value.VS._1.VInt) )
              Scaleform::GFx::AS3::Value::ToStringValue(
                v214,
                &v388,
                (Scaleform::GFx::ASStringNode *)this->StringManagerRef);
            else
              Scaleform::GFx::AS3::Value::SetNull(v214);
            goto LABEL_187;
          case 0x86u:
            v_4bh = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_astype(this, file, v_4bh);
            goto LABEL_187;
          case 0x87u:
            Scaleform::GFx::AS3::VM::exec_astypelate(this);
            goto LABEL_193;
          case 0x8Au:
            Data = *CP;
            v25 = this->OpStack.pCurrent;
            v26 = v25 - 1;
            this->OpStack.pCurrent = v25 - 1;
            v27 = v25->value.VS._1;
            this->OpStack.pCurrent = v26 - 1;
            v28 = CP + 1;
            v29 = undefined3;
            if ( v26->value.VS._1.VInt >= v27.VInt )
              v29 = Data;
            goto LABEL_48;
          case 0x8Bu:
            v39 = this->OpStack.pCurrent;
            Data = *CP;
            v40 = v39 - 1;
            this->OpStack.pCurrent = v39 - 1;
            v41 = v39->value.VS._1;
            this->OpStack.pCurrent = v40 - 1;
            v28 = CP + 1;
            v29 = undefined3;
            if ( v40->value.VS._1.VInt <= v41.VInt )
              goto LABEL_48;
            CP = &v28[Data];
            continue;
          case 0x8Cu:
            v48 = this->OpStack.pCurrent;
            Data = *CP;
            v49 = v48 - 1;
            this->OpStack.pCurrent = v48 - 1;
            v50 = v48->value.VS._1;
            this->OpStack.pCurrent = v49 - 1;
            v28 = CP + 1;
            v29 = undefined3;
            if ( v49->value.VS._1.VInt > v50.VInt )
              goto LABEL_48;
            CP = &v28[Data];
            continue;
          case 0x8Du:
            v56 = this->OpStack.pCurrent;
            Data = *CP;
            v57 = v56 - 1;
            this->OpStack.pCurrent = v56 - 1;
            v58 = v56->value.VS._1;
            this->OpStack.pCurrent = v57 - 1;
            v28 = CP + 1;
            v29 = undefined3;
            if ( v57->value.VS._1.VInt >= v58.VInt )
              goto LABEL_48;
            CP = &v28[Data];
            continue;
          case 0x8Eu:
            v80 = this->OpStack.pCurrent;
            Data = *CP;
            v81 = v80 - 1;
            this->OpStack.pCurrent = v80 - 1;
            v82 = v80->value.VS._1;
            this->OpStack.pCurrent = v81 - 1;
            v28 = CP + 1;
            v29 = undefined3;
            if ( v81->value.VS._1.VInt != v82.VInt )
              goto LABEL_48;
            CP = &v28[Data];
            continue;
          case 0x8Fu:
            v114 = this->OpStack.pCurrent;
            case_count = *CP;
            v115 = v114 - 1;
            this->OpStack.pCurrent = v114 - 1;
            v116 = v114->value.VS._1;
            this->OpStack.pCurrent = v115 - 1;
            v100 = CP + 1;
            v101 = 0;
            if ( v115->value.VS._1.VInt < v116.VInt )
              goto LABEL_123;
            CP = &v100[case_count];
            continue;
          case 0x90u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v420)->Result )
              *(double *)(LODWORD(default_offset) + 8) = -*(double *)(LODWORD(default_offset) + 8);
            goto LABEL_187;
          case 0x91u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v390)->Result )
              *(double *)(LODWORD(default_offset) + 8) = *(double *)(LODWORD(default_offset) + 8) + 1.0;
            goto LABEL_187;
          case 0x92u:
            v215 = &this->RegisterFile.pRF[*CP++];
            LODWORD(default_offset) = v215;
            if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v215, &v422, &v479)->Result )
              Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), v479 + 1.0);
            goto LABEL_193;
          case 0x93u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v392)->Result )
              *(double *)(LODWORD(default_offset) + 8) = *(double *)(LODWORD(default_offset) + 8) - 1.0;
            goto LABEL_187;
          case 0x94u:
            v216 = &this->RegisterFile.pRF[*CP++];
            LODWORD(default_offset) = v216;
            if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v216, &v424, &v480)->Result )
              Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), v480 - 1.0);
            goto LABEL_193;
          case 0x95u:
            Scaleform::GFx::AS3::VM::exec_typeof(this);
            continue;
          case 0x96u:
            Data = (Scaleform::GFx::AS3::Boolean3)this->OpStack.pCurrent;
            v217 = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)Data);
            Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)Data, v217);
            *(_BYTE *)(Data + 8) = *(_BYTE *)(Data + 8) == 0;
            continue;
          case 0x97u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::Convert2Int32(
                   (Scaleform::GFx::AS3::Value *)LODWORD(default_offset),
                   &v394,
                   (Scaleform::GFx::AS3::Value::V1U *)&v448)->Result )
              Scaleform::GFx::AS3::Value::SetSInt32((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), ~v448);
            goto LABEL_193;
          case 0x9Bu:
            v218 = this->OpStack.pCurrent;
            v371 |= 1u;
            LODWORD(default_offset) = v218;
            v219 = Scaleform::GFx::AS3::Value::ToNumberValue(v218, &v426)->Result;
            if ( (v371 & 1) != 0 )
              v371 &= ~1u;
            if ( v219 )
              v220 = (double *)(LODWORD(default_offset) + 8);
            else
              v220 = (double *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
            v221 = *v220;
            v222 = this->OpStack.pCurrent - 1;
            v485 = v221;
            Data = (Scaleform::GFx::AS3::Boolean3)v222;
            if ( !v219
              || (v371 |= 2u, v118 = !Scaleform::GFx::AS3::Value::ToNumberValue(v222, &v396)->Result, v484 = 1, v118) )
            {
              v484 = 0;
            }
            if ( (v371 & 2) != 0 )
              v371 &= ~2u;
            if ( v484 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v484 )
              *(double *)Data = v485 + *(double *)Data;
            goto LABEL_187;
          case 0x9Cu:
            v110 = this->OpStack.pCurrent;
            case_count = *CP;
            v111 = v110 - 1;
            this->OpStack.pCurrent = v110 - 1;
            v112 = v110->value.VS._1;
            this->OpStack.pCurrent = v111 - 1;
            v100 = CP + 1;
            v101 = 0;
            if ( v111->value.VS._1.VInt <= v112.VInt )
              goto LABEL_123;
            CP = &v100[case_count];
            continue;
          case 0x9Du:
            v105 = this->OpStack.pCurrent;
            case_count = *CP;
            v106 = v105 - 1;
            this->OpStack.pCurrent = v105 - 1;
            v107 = v105->value.VS._1;
            this->OpStack.pCurrent = v106 - 1;
            v100 = CP + 1;
            v101 = 0;
            if ( v106->value.VS._1.VInt > v107.VInt )
              goto LABEL_123;
            CP = &v100[case_count];
            continue;
          case 0x9Eu:
            v97 = this->OpStack.pCurrent;
            case_count = *CP;
            v98 = v97 - 1;
            this->OpStack.pCurrent = v97 - 1;
            v99 = v97->value.VS._1;
            this->OpStack.pCurrent = v98 - 1;
            v100 = CP + 1;
            v101 = 0;
            if ( v98->value.VS._1.VInt < v99.VInt )
              v101 = case_count;
LABEL_123:
            CP = &v100[v101];
            continue;
          case 0x9Fu:
            v88 = this->OpStack.pCurrent;
            Data = *CP;
            v89 = v88 - 1;
            this->OpStack.pCurrent = v88 - 1;
            v90 = v88->value.VS._1;
            this->OpStack.pCurrent = v89 - 1;
            v28 = CP + 1;
            v29 = undefined3;
            if ( v89->value.VS._1.VInt == v90.VInt )
LABEL_48:
              CP = &v28[v29];
            else
              CP = &v28[Data];
            continue;
          case 0xA0u:
            v223 = this->OpStack.pCurrent;
            r._2.Flags = v223->Flags;
            r._2.Bonus.pWeakProxy = v223->Bonus.pWeakProxy;
            r._2.value.VS._1.VInt = v223->value.VS._1.VInt;
            v224.VObj = (Scaleform::GFx::AS3::Object *)v223->value.VS._2;
            this->OpStack.pCurrent = v223 - 1;
            r._1 = v223 - 1;
            StringManagerRef = this->StringManagerRef;
            r._2.value.VS._2 = v224;
            Scaleform::GFx::AS3::Add(&v428, StringManagerRef, r._1, r._1, &r._2);
            Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            goto LABEL_193;
          case 0xA1u:
            v226 = this->OpStack.pCurrent;
            v371 |= 4u;
            default_offset = 0.0;
            r._2.Flags = v226->Flags;
            r._2.Bonus.pWeakProxy = v226->Bonus.pWeakProxy;
            r._2.value.VNumber = v226->value.VNumber;
            this->OpStack.pCurrent = v226 - 1;
            r._1 = v226 - 1;
            v227 = 0;
            if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v226 - 1, &v398, &v486)->Result )
            {
              v371 |= 8u;
              if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(&r._2, &v430, &default_offset)->Result )
                v227 = 1;
            }
            v228 = v371;
            if ( (v371 & 8) != 0 )
            {
              v228 = v371 & 0xFFFFFFF7;
              v371 &= ~8u;
            }
            if ( (v228 & 4) != 0 )
              v371 = v228 & 0xFFFFFFFB;
            if ( !v227 )
              goto LABEL_339;
            v229 = v486 - default_offset;
            goto LABEL_338;
          case 0xA2u:
            v230 = this->OpStack.pCurrent;
            v371 |= 0x10u;
            default_offset = 0.0;
            r._2.Flags = v230->Flags;
            r._2.Bonus.pWeakProxy = v230->Bonus.pWeakProxy;
            r._2.value.VNumber = v230->value.VNumber;
            this->OpStack.pCurrent = v230 - 1;
            r._1 = v230 - 1;
            v231 = 0;
            if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v230 - 1, &v400, &v478)->Result )
            {
              v371 |= 0x20u;
              if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(&r._2, &v432, &default_offset)->Result )
                v231 = 1;
            }
            v232 = v371;
            if ( (v371 & 0x20) != 0 )
            {
              v232 = v371 & 0xFFFFFFDF;
              v371 &= ~0x20u;
            }
            if ( (v232 & 0x10) != 0 )
              v371 = v232 & 0xFFFFFFEF;
            if ( !v231 )
              goto LABEL_339;
            v229 = v478 * default_offset;
LABEL_338:
            Scaleform::GFx::AS3::Value::SetNumber(r._1, v229);
LABEL_339:
            Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            goto LABEL_193;
          case 0xA3u:
            v233 = this->OpStack.pCurrent;
            v371 |= 0x40u;
            LODWORD(default_offset) = v233;
            v234 = Scaleform::GFx::AS3::Value::ToNumberValue(v233, &v402)->Result;
            if ( (v371 & 0x40) != 0 )
              v371 &= ~0x40u;
            if ( v234 )
              v235 = (double *)(LODWORD(default_offset) + 8);
            else
              v235 = (double *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
            v236 = *v235;
            v237 = this->OpStack.pCurrent - 1;
            v488 = v236;
            Data = (Scaleform::GFx::AS3::Boolean3)v237;
            if ( !v234
              || (v371 |= 0x80u, v118 = !Scaleform::GFx::AS3::Value::ToNumberValue(v237, &v434)->Result, v487 = 1, v118) )
            {
              v487 = 0;
            }
            if ( (v371 & 0x80u) != 0 )
              v371 &= ~0x80u;
            if ( v487 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v487 )
              *(double *)Data = *(double *)Data / v488;
            goto LABEL_187;
          case 0xA4u:
            v240 = this->OpStack.pCurrent;
            v371 |= 0x100u;
            LODWORD(default_offset) = v240;
            v241 = Scaleform::GFx::AS3::Value::ToNumberValue(v240, &v436)->Result;
            if ( (v371 & 0x100) != 0 )
              v371 &= ~0x100u;
            if ( v241 )
              v242 = (double *)(LODWORD(default_offset) + 8);
            else
              v242 = (double *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
            v243 = *v242;
            v244 = this->OpStack.pCurrent - 1;
            v483 = v243;
            Data = (Scaleform::GFx::AS3::Boolean3)v244;
            if ( !v241
              || (v371 |= 0x200u, v118 = !Scaleform::GFx::AS3::Value::ToNumberValue(v244, &v405)->Result, v482 = 1, v118) )
            {
              v482 = 0;
            }
            if ( (v371 & 0x200) != 0 )
              v371 &= ~0x200u;
            if ( v482 )
              curr_cp = (const unsigned int *)(Data + 8);
            else
              curr_cp = (const unsigned int *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v482 )
              *(long double *)curr_cp = fmod(*(double *)curr_cp, v483);
            goto LABEL_193;
          case 0xA5u:
            v245 = this->OpStack.pCurrent;
            v371 |= 0x400u;
            LODWORD(default_offset) = v245;
            v246 = Scaleform::GFx::AS3::Value::ToUInt32Value(v245, &v433)->Result;
            if ( (v371 & 0x400) != 0 )
              v371 &= ~0x400u;
            if ( v246 )
              v247 = (int *)(LODWORD(default_offset) + 8);
            else
              v247 = (int *)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
            v457 = *v247;
            v248 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v248;
            if ( !v246
              || (v371 |= 0x800u, v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v248, &v407)->Result, v456 = 1, v118) )
            {
              v456 = 0;
            }
            if ( (v371 & 0x800) != 0 )
              v371 &= ~0x800u;
            if ( v456 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v456 )
              *(_DWORD *)Data <<= v457 & 0x1F;
            goto LABEL_187;
          case 0xA6u:
            v249 = this->OpStack.pCurrent;
            v371 |= 0x1000u;
            LODWORD(default_offset) = v249;
            v250 = Scaleform::GFx::AS3::Value::ToUInt32Value(v249, &v425)->Result;
            if ( (v371 & 0x1000) != 0 )
              v371 &= ~0x1000u;
            if ( v250 )
              v251 = (int *)(LODWORD(default_offset) + 8);
            else
              v251 = (int *)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
            v445 = *v251;
            v252 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v252;
            if ( !v250
              || (v371 |= 0x2000u, v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v252, &v409)->Result, v444 = 1, v118) )
            {
              v444 = 0;
            }
            if ( (v371 & 0x2000) != 0 )
              v371 &= ~0x2000u;
            if ( v444 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v444 )
              *(int *)Data >>= v445 & 0x1F;
            goto LABEL_187;
          case 0xA7u:
            v253 = this->OpStack.pCurrent;
            v371 |= 0x4000u;
            LODWORD(default_offset) = v253;
            v254 = Scaleform::GFx::AS3::Value::ToUInt32Value(v253, &v441)->Result;
            if ( (v371 & 0x4000) != 0 )
              v371 &= ~0x4000u;
            if ( v254 )
              v255 = (int *)(LODWORD(default_offset) + 8);
            else
              v255 = (int *)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
            v447 = *v255;
            v256 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v256;
            if ( !v254
              || (v371 |= 0x8000u, v118 = !Scaleform::GFx::AS3::Value::ToUInt32Value(v256, &v411)->Result,
                                   v446 = 1,
                                   v118) )
            {
              v446 = 0;
            }
            if ( (v371 & 0x8000) != 0 )
              v371 &= ~0x8000u;
            if ( v446 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v446 )
              *(_DWORD *)Data >>= v447 & 0x1F;
            goto LABEL_187;
          case 0xA8u:
            v257 = this->OpStack.pCurrent;
            v371 |= (unsigned int)&_sbh_sizeHeaderList;
            LODWORD(default_offset) = v257;
            v258 = Scaleform::GFx::AS3::Value::ToInt32Value(v257, &v427)->Result;
            if ( ((unsigned int)&_sbh_sizeHeaderList & v371) != 0 )
              v371 &= ~0x10000u;
            if ( v258 )
              v259 = (int *)(LODWORD(default_offset) + 8);
            else
              v259 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            v450 = *v259;
            v260 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v260;
            if ( !v258
              || (v371 |= (unsigned int)&loc_20000,
                  v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v260, &v413)->Result,
                  v449 = 1,
                  v118) )
            {
              v449 = 0;
            }
            if ( ((unsigned int)&loc_20000 & v371) != 0 )
              v371 &= ~0x20000u;
            if ( v449 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v449 )
              *(_DWORD *)Data &= v450;
            goto LABEL_193;
          case 0xA9u:
            v261 = this->OpStack.pCurrent;
            v371 |= 0x40000u;
            LODWORD(default_offset) = v261;
            v262 = Scaleform::GFx::AS3::Value::ToInt32Value(v261, &v435)->Result;
            if ( (v371 & 0x40000) != 0 )
              v371 &= ~0x40000u;
            if ( v262 )
              v263 = (int *)(LODWORD(default_offset) + 8);
            else
              v263 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            v452 = *v263;
            v264 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v264;
            if ( !v262
              || (v371 |= 0x80000u, v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v264, &v415)->Result,
                                    v451 = 1,
                                    v118) )
            {
              v451 = 0;
            }
            if ( (v371 & 0x80000) != 0 )
              v371 &= ~0x80000u;
            if ( v451 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v451 )
              *(_DWORD *)Data |= v452;
            goto LABEL_193;
          case 0xAAu:
            v265 = this->OpStack.pCurrent;
            v371 |= 0x100000u;
            LODWORD(default_offset) = v265;
            v266 = Scaleform::GFx::AS3::Value::ToInt32Value(v265, &v429)->Result;
            if ( (v371 & 0x100000) != 0 )
              v371 &= ~0x100000u;
            if ( v266 )
              v267 = (int *)(LODWORD(default_offset) + 8);
            else
              v267 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            v455 = *v267;
            v268 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v268;
            if ( !v266
              || (v371 |= 0x200000u,
                  v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v268, &v417)->Result,
                  v454 = 1,
                  v118) )
            {
              v454 = 0;
            }
            if ( (v371 & 0x200000) != 0 )
              v371 &= ~0x200000u;
            if ( v454 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v454 )
              *(_DWORD *)Data ^= v455;
            goto LABEL_193;
          case 0xABu:
            v269 = this->OpStack.pCurrent;
            r._2.Flags = v269->Flags;
            r._2.Bonus.pWeakProxy = v269->Bonus.pWeakProxy;
            r._2.value.VNumber = v269->value.VNumber;
            this->OpStack.pCurrent = v269 - 1;
            r._1 = v269 - 1;
            if ( !Scaleform::GFx::AS3::AbstractEqual(&v439, v460, v269 - 1, &r._2)->Result )
              goto LABEL_339;
            Scaleform::GFx::AS3::Value::SetBool(r._1, v460[0]);
            Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            goto LABEL_193;
          case 0xACu:
            v270 = this->OpStack.pCurrent;
            v271.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v270->Bonus;
            r._2.Flags = v270->Flags;
            r._2.value.VS._1.VInt = v270->value.VS._1.VInt;
            r._2.Bonus = v271;
            r._2.value.VS._2.VObj = v270->value.VS._2.VObj;
            this->OpStack.pCurrent = v270 - 1;
            r._1 = v270 - 1;
            other.Flags = 1;
            other.Bonus.pWeakProxy = 0;
            other.value.VS._1.VBool = Scaleform::GFx::AS3::StrictEqual(v270 - 1, &r._2);
            Scaleform::GFx::AS3::Value::Assign(r._1, &other);
            Scaleform::GFx::AS3::Value::~Value(&other);
            Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            continue;
          case 0xADu:
            v272 = this->OpStack.pCurrent;
            r._2.Flags = v272->Flags;
            r._2.Bonus.pWeakProxy = v272->Bonus.pWeakProxy;
            r._2.value.VNumber = v272->value.VNumber;
            this->OpStack.pCurrent = v272 - 1;
            r._1 = v272 - 1;
            Data = undefined3;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v419, &Data, v272 - 1, &r._2)->Result )
              goto LABEL_475;
            goto LABEL_476;
          case 0xAEu:
            v273 = this->OpStack.pCurrent;
            r._2.Flags = v273->Flags;
            r._2.Bonus.pWeakProxy = v273->Bonus.pWeakProxy;
            r._2.value.VS._1.VInt = v273->value.VS._1.VInt;
            v274.VObj = (Scaleform::GFx::AS3::Object *)v273->value.VS._2;
            v275 = v273 - 1;
            v_4 = (Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *)v275;
            r._2.value.VS._2 = v274;
            v = &r;
            v276 = &v431;
            goto LABEL_478;
          case 0xAFu:
            v277 = this->OpStack.pCurrent;
            r._2.Flags = v277->Flags;
            r._2.Bonus.pWeakProxy = v277->Bonus.pWeakProxy;
            r._2.value.VS._1.VInt = v277->value.VS._1.VInt;
            v278.VObj = (Scaleform::GFx::AS3::Object *)v277->value.VS._2;
            this->OpStack.pCurrent = v277 - 1;
            r._1 = v277 - 1;
            r._2.value.VS._2 = v278;
            Data = undefined3;
            if ( Scaleform::GFx::AS3::AbstractLessThan(&v421, &Data, &r._2, v277 - 1)->Result )
LABEL_475:
              Scaleform::GFx::AS3::Value::SetBool(r._1, Data == true3);
            goto LABEL_476;
          case 0xB0u:
            v279 = this->OpStack.pCurrent;
            r._2.Flags = v279->Flags;
            r._2.Bonus.pWeakProxy = v279->Bonus.pWeakProxy;
            r._2.value.VS._1.VInt = v279->value.VS._1.VInt;
            v280.VObj = (Scaleform::GFx::AS3::Object *)v279->value.VS._2;
            v275 = v279 - 1;
            v_4 = &r;
            r._2.value.VS._2 = v280;
            v = (Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> *)v275;
            v276 = (Scaleform::GFx::AS3::CheckResult *)&v437;
LABEL_478:
            this->OpStack.pCurrent = v275;
            r._1 = v275;
            Data = undefined3;
            if ( Scaleform::GFx::AS3::AbstractLessThan(v276, &Data, &v->_2, &v_4->_2)->Result )
              Scaleform::GFx::AS3::Value::SetBool(r._1, Data == false3);
            goto LABEL_476;
          case 0xB1u:
            Scaleform::GFx::AS3::VM::exec_instanceof(this);
            goto LABEL_193;
          case 0xB2u:
            v_4bi = &constp->const_multiname.Data.Data[*CP++];
            Scaleform::GFx::AS3::VM::exec_istype(this, file, v_4bi);
            goto LABEL_187;
          case 0xB3u:
            v281 = this->OpStack.pCurrent;
            v282 = v281->Flags;
            r._2.Bonus.pWeakProxy = v281->Bonus.pWeakProxy;
            v283 = v281->value.VS._1;
            r._2.Flags = v282;
            r._2.value.VS._1 = v283;
            v284.VObj = (Scaleform::GFx::AS3::Object *)v281->value.VS._2;
            --v281;
            r._2.value.VS._2 = v284;
            this->OpStack.pCurrent = v281;
            r._1 = v281;
            if ( (v282 & 0x1F) == 0xD )
            {
              v_4bj = *(Scaleform::GFx::AS3::ClassTraits::fl::Object **)(r._2.value.VS._1.VInt + 20);
              v477.Flags = 1;
              v477.Bonus.pWeakProxy = 0;
              v477.value.VS._1.VBool = Scaleform::GFx::AS3::VM::IsOfType(this, r._1, v_4bj);
              Scaleform::GFx::AS3::Value::Assign(r._1, &v477);
              Scaleform::GFx::AS3::Value::~Value(&v477);
              Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            }
            else
            {
              Scaleform::GFx::AS3::VM::Error::Error(&v442, eIsTypeMustBeClassError, this);
              Scaleform::GFx::AS3::VM::ThrowErrorInternal(
                this,
                v285,
                (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
              v286 = v442.Message.pNode;
              --v442.Message.pNode->RefCount;
              if ( v286->RefCount )
              {
LABEL_476:
                Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
              }
              else
              {
                Scaleform::GFx::ASStringNode::ReleaseNode(v286);
                Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
              }
            }
            goto LABEL_187;
          case 0xB4u:
            Scaleform::GFx::AS3::VM::exec_in(this);
            goto LABEL_193;
          case 0xB5u:
            v_4bk = *CP++;
            AbsObject = Scaleform::GFx::AS3::GetAbsObject(&v489, v_4bk);
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v288 = this->OpStack.pCurrent;
            if ( v118 )
              goto LABEL_495;
            v288->Flags = AbsObject->Flags;
            v288->Bonus.pWeakProxy = AbsObject->Bonus.pWeakProxy;
            v288->value.VS._1.VInt = AbsObject->value.VS._1.VInt;
            v288->value.VS._2.VObj = AbsObject->value.VS._2.VObj;
            if ( (AbsObject->Flags & 0x1F) <= 9 )
              goto LABEL_495;
            if ( (AbsObject->Flags & 0x200) != 0 )
            {
              ++AbsObject->Bonus.pWeakProxy->RefCount;
              Scaleform::GFx::AS3::Value::~Value(&v489);
            }
            else
            {
              Scaleform::GFx::AS3::Value::AddRefInternal(AbsObject);
LABEL_495:
              Scaleform::GFx::AS3::Value::~Value(&v489);
            }
            continue;
          case 0xB6u:
            v_4bl = *CP++;
            Scaleform::GFx::AS3::VM::exec_getabsslot(this, v_4bl);
            goto LABEL_187;
          case 0xB7u:
            v_4bm = *CP++;
            Scaleform::GFx::AS3::VM::exec_setabsslot(this, v_4bm);
            goto LABEL_193;
          case 0xB8u:
            v_4bn = *CP++;
            Scaleform::GFx::AS3::VM::exec_initabsslot(this, v_4bn);
            goto LABEL_187;
          case 0xB9u:
            v180 = *CP;
            v181 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callsupermethod(this, v5->OriginationTraits, v180, v181);
            goto LABEL_226;
          case 0xBAu:
            v182 = *CP;
            v183 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callgetter(this, v182, v183);
            goto LABEL_226;
          case 0xBBu:
            v184 = *CP;
            v185 = CP[1];
            CP += 2;
            Scaleform::GFx::AS3::VM::exec_callsupergetter(this, v5->OriginationTraits, v184, v185);
LABEL_226:
            if ( !this->HandleException )
              goto LABEL_229;
            LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v177 = Scaleform::GFx::AS3::VM::OnException(
                     this,
                     ((int)CP - LODWORD(default_offset)) >> 2,
                     (unsigned int)v5);
            if ( v177 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(LODWORD(default_offset) + 4 * v177);
LABEL_229:
            v118 = call_stack_size == this->CallStack.Size;
            goto LABEL_153;
          case 0xBCu:
          case 0xC9u:
            v42 = this->OpStack.pCurrent;
            v43 = v42->value.VNumber;
            v44 = *CP;
            v45 = v42[-1].value.VNumber;
            this->OpStack.pCurrent = v42 - 2;
            v34 = CP + 1;
            v35 = 0;
            if ( v45 <= v43 )
              goto LABEL_51;
            CP = &v34[v44];
            continue;
          case 0xBDu:
          case 0xCAu:
            v51 = this->OpStack.pCurrent;
            v52 = v51->value.VNumber;
            v53 = *CP;
            v54 = v51[-1].value.VNumber;
            this->OpStack.pCurrent = v51 - 2;
            v34 = CP + 1;
            v35 = 0;
            if ( v54 > v52 )
              goto LABEL_51;
            CP = &v34[v53];
            continue;
          case 0xBEu:
          case 0xCBu:
            v59 = this->OpStack.pCurrent;
            v60 = v59->value.VNumber;
            v61 = *CP;
            v62 = v59[-1].value.VNumber;
            this->OpStack.pCurrent = v59 - 2;
            v34 = CP + 1;
            v35 = 0;
            if ( v62 >= v60 )
              goto LABEL_51;
            CP = &v34[v61];
            continue;
          case 0xBFu:
            v91 = this->OpStack.pCurrent;
            v92 = v91->value.VNumber;
            v93 = *CP;
            v94 = v91[-1].value.VNumber;
            this->OpStack.pCurrent = v91 - 2;
            v34 = CP + 1;
            v35 = 0;
            if ( v94 == v92 )
              goto LABEL_51;
            CP = &v34[v93];
            continue;
          case 0xC0u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::ToInt32Value((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v382)->Result )
              ++*(_DWORD *)(LODWORD(default_offset) + 8);
            goto LABEL_187;
          case 0xC1u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::ToInt32Value((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v404)->Result )
              --*(_DWORD *)(LODWORD(default_offset) + 8);
            goto LABEL_187;
          case 0xC2u:
            v289 = &this->RegisterFile.pRF[*CP++];
            LODWORD(default_offset) = v289;
            if ( Scaleform::GFx::AS3::Value::ToInt32Value(v289, &v406)->Result )
              ++*(_DWORD *)(LODWORD(default_offset) + 8);
LABEL_187:
            if ( !this->HandleException )
              continue;
            LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v13 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - LODWORD(default_offset)) >> 2, (unsigned int)v5);
            if ( v13 < 0 )
              goto LABEL_587;
            v14 = LODWORD(default_offset);
            goto LABEL_20;
          case 0xC3u:
            v291 = &this->RegisterFile.pRF[*CP++];
            LODWORD(default_offset) = v291;
            if ( Scaleform::GFx::AS3::Value::ToInt32Value(v291, &v408)->Result )
              --*(_DWORD *)(LODWORD(default_offset) + 8);
            goto LABEL_193;
          case 0xC4u:
            LODWORD(default_offset) = this->OpStack.pCurrent;
            if ( Scaleform::GFx::AS3::Value::ToInt32Value((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v410)->Result )
              *(_DWORD *)(LODWORD(default_offset) + 8) = -*(_DWORD *)(LODWORD(default_offset) + 8);
            goto LABEL_193;
          case 0xC5u:
            v293 = this->OpStack.pCurrent;
            v371 |= (unsigned int)Scaleform::GFx::AS2::CreateShadow;
            LODWORD(default_offset) = v293;
            v294 = Scaleform::GFx::AS3::Value::ToInt32Value(v293, &v412)->Result;
            if ( ((unsigned int)Scaleform::GFx::AS2::CreateShadow & v371) != 0 )
              v371 &= ~0x400000u;
            if ( v294 )
              v295 = (int *)(LODWORD(default_offset) + 8);
            else
              v295 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            v459 = *v295;
            v296 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v296;
            if ( !v294
              || (v371 |= (unsigned int)&unk_800000,
                  v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v296, &v414)->Result,
                  v458 = 1,
                  v118) )
            {
              v458 = 0;
            }
            if ( ((unsigned int)&unk_800000 & v371) != 0 )
              v371 &= ~0x800000u;
            if ( v458 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v458 )
              *(_DWORD *)Data += v459;
            goto LABEL_193;
          case 0xC6u:
            v301 = this->OpStack.pCurrent;
            v371 |= (unsigned int)&vostok::memory::s_CRT_arena[5574200];
            LODWORD(default_offset) = v301;
            v302 = Scaleform::GFx::AS3::Value::ToInt32Value(v301, &v383)->Result;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[5574200] & v371) != 0 )
              v371 &= ~0x1000000u;
            if ( v302 )
              v303 = (int *)(LODWORD(default_offset) + 8);
            else
              v303 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            v462 = *v303;
            v304 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v304;
            if ( !v302
              || (v371 |= (unsigned int)&vostok::memory::s_CRT_arena[22351416],
                  v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v304, &v385)->Result,
                  v461 = 1,
                  v118) )
            {
              v461 = 0;
            }
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & v371) != 0 )
              v371 &= ~0x2000000u;
            if ( v461 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v461 )
              *(_DWORD *)Data -= v462;
            goto LABEL_193;
          case 0xC7u:
            v309 = this->OpStack.pCurrent;
            v371 |= (unsigned int)&vostok::memory::s_CRT_arena[55905848];
            LODWORD(default_offset) = v309;
            v310 = Scaleform::GFx::AS3::Value::ToInt32Value(v309, &v387)->Result;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & v371) != 0 )
              v371 &= ~0x4000000u;
            if ( v310 )
              v311 = (int *)(LODWORD(default_offset) + 8);
            else
              v311 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            v465 = *v311;
            v312 = this->OpStack.pCurrent - 1;
            Data = (Scaleform::GFx::AS3::Boolean3)v312;
            if ( !v310
              || (v371 |= 0x8000000u,
                  v118 = !Scaleform::GFx::AS3::Value::ToInt32Value(v312, &v389)->Result,
                  v464 = 1,
                  v118) )
            {
              v464 = 0;
            }
            if ( (v371 & 0x8000000) != 0 )
              v371 &= ~0x8000000u;
            if ( v464 )
              Data += 8;
            else
              Data = (Scaleform::GFx::AS3::Boolean3)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
            Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
            --this->OpStack.pCurrent;
            if ( v464 )
              *(_DWORD *)Data *= v465;
LABEL_193:
            if ( !this->HandleException )
              continue;
            LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v141 = Scaleform::GFx::AS3::VM::OnException(
                     this,
                     ((int)CP - LODWORD(default_offset)) >> 2,
                     (unsigned int)v5);
            if ( v141 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(LODWORD(default_offset) + 4 * v141);
            continue;
          case 0xC8u:
          case 0xCDu:
            v30 = this->OpStack.pCurrent;
            v31 = v30->value.VNumber;
            v32 = *CP;
            v33 = v30[-1].value.VNumber;
            this->OpStack.pCurrent = v30 - 2;
            v34 = CP + 1;
            v35 = 0;
            if ( v33 >= v31 )
              v35 = v32;
            goto LABEL_51;
          case 0xCCu:
            v83 = this->OpStack.pCurrent;
            v84 = v83->value.VNumber;
            v85 = *CP;
            v86 = v83[-1].value.VNumber;
            this->OpStack.pCurrent = v83 - 2;
            v34 = CP + 1;
            v35 = 0;
            if ( v86 == v84 )
              CP = &v34[v85];
            else
LABEL_51:
              CP = &v34[v35];
            continue;
          case 0xCEu:
            v_4i = *CP++;
            Scaleform::GFx::AS3::VM::exec_callobject(this, v_4i);
            if ( !this->HandleException )
              goto LABEL_152;
            case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v5->pFile, v5->MBIIndex, v5)->Data.Data;
            v117 = Scaleform::GFx::AS3::VM::OnException(this, (int)((int)CP - case_count) >> 2, (unsigned int)v5);
            if ( v117 < 0 )
              goto LABEL_587;
            CP = (unsigned int *)(case_count + 4 * v117);
LABEL_152:
            v118 = call_stack_size == this->CallStack.Size;
LABEL_153:
            if ( v118 )
              continue;
            ++max_stack_depth;
            this->CallStack.Pages[(call_stack_size - 1) >> 6][(call_stack_size - 1) & 0x3F].CP = CP;
            break;
          case 0xD0u:
            pRF = this->RegisterFile.pRF;
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v317 = this->OpStack.pCurrent;
            if ( v118 )
              continue;
            v317->Flags = pRF->Flags;
            v317->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
            v317->value.VS._1.VInt = pRF->value.VS._1.VInt;
            v317->value.VS._2.VObj = pRF->value.VS._2.VObj;
            if ( (pRF->Flags & 0x1F) <= 9 )
              continue;
            if ( (pRF->Flags & 0x200) == 0 )
              goto LABEL_259;
            ++pRF->Bonus.pWeakProxy->RefCount;
            continue;
          case 0xD1u:
            pRF = this->RegisterFile.pRF + 1;
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v318 = this->OpStack.pCurrent;
            if ( v118 )
              continue;
            v318->Flags = pRF->Flags;
            v318->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
            v318->value.VS._1.VInt = pRF->value.VS._1.VInt;
            v318->value.VS._2.VObj = pRF->value.VS._2.VObj;
            if ( (pRF->Flags & 0x1F) <= 9 )
              continue;
            if ( (pRF->Flags & 0x200) == 0 )
              goto LABEL_259;
            ++pRF->Bonus.pWeakProxy->RefCount;
            continue;
          case 0xD2u:
            pRF = this->RegisterFile.pRF + 2;
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v319 = this->OpStack.pCurrent;
            if ( v118 )
              continue;
            v319->Flags = pRF->Flags;
            v319->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
            v319->value.VS._1.VInt = pRF->value.VS._1.VInt;
            v319->value.VS._2.VObj = pRF->value.VS._2.VObj;
            if ( (pRF->Flags & 0x1F) <= 9 )
              continue;
            if ( (pRF->Flags & 0x200) == 0 )
              goto LABEL_259;
            ++pRF->Bonus.pWeakProxy->RefCount;
            continue;
          case 0xD3u:
            pRF = this->RegisterFile.pRF + 3;
            v118 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
            v320 = this->OpStack.pCurrent;
            if ( v118 )
              continue;
            v320->Flags = pRF->Flags;
            v320->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
            v320->value.VS._1.VInt = pRF->value.VS._1.VInt;
            v320->value.VS._2.VObj = pRF->value.VS._2.VObj;
            if ( (pRF->Flags & 0x1F) <= 9 )
              continue;
            if ( (pRF->Flags & 0x200) == 0 )
              goto LABEL_259;
            ++pRF->Bonus.pWeakProxy->RefCount;
            continue;
          case 0xD4u:
            Scaleform::GFx::AS3::Value::Pick(this->RegisterFile.pRF, this->OpStack.pCurrent);
            --this->OpStack.pCurrent;
            continue;
          case 0xD5u:
            Scaleform::GFx::AS3::Value::Pick(this->RegisterFile.pRF + 1, this->OpStack.pCurrent);
            --this->OpStack.pCurrent;
            continue;
          case 0xD6u:
            Scaleform::GFx::AS3::Value::Pick(this->RegisterFile.pRF + 2, this->OpStack.pCurrent);
            --this->OpStack.pCurrent;
            continue;
          case 0xD7u:
            Scaleform::GFx::AS3::Value::Pick(this->RegisterFile.pRF + 3, this->OpStack.pCurrent);
            --this->OpStack.pCurrent;
            continue;
          case 0xEFu:
            CP += 4;
            continue;
          case 0xF0u:
          case 0xF1u:
          case 0xF2u:
            ++CP;
            continue;
          default:
            continue;
        }
        goto LABEL_592;
      }
    }
LABEL_587:
    if ( this->HandleException )
    {
LABEL_588:
      v321 = this->CallStack.Size - 1;
      v322 = this->CallStack.Pages[v321 >> 6];
      Scaleform::GFx::AS3::ValueStack::PopReserved(
        &v322[v321 & 0x3F].pFile->VMRef->OpStack,
        v322[v321 & 0x3F].PrevInitialStackPos);
    }
LABEL_589:
    Size = this->CallStack.Size;
    if ( Size )
    {
      Scaleform::GFx::AS3::CallFrame::~CallFrame(&this->CallStack.Pages[(Size - 1) >> 6][(Size - 1) & 0x3F]);
      --this->CallStack.Size;
    }
    if ( !--max_stack_depth )
      break;
LABEL_592:
    Scaleform::GFx::AS3::Value::~Value(&tmpExceptionValue);
    if ( !this->CallStack.Size )
      return max_stack_depth;
  }
  Scaleform::GFx::AS3::Value::~Value(&tmpExceptionValue);
  return max_stack_depth;
}
