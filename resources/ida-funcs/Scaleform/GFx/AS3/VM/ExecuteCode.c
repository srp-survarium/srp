unsigned int __thiscall Scaleform::GFx::AS3::VM::ExecuteCode(
        Scaleform::GFx::AS3::VM *this,
        unsigned int max_stack_depth)
{
  Scaleform::GFx::AS3::CallFrame **Pages; // edx
  Scaleform::GFx::AS3::CallFrame *v4; // edi
  Scaleform::GFx::AS3::Value::V1U v5; // edx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // ecx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // ebx
  bool HandleException; // al
  Scaleform::GFx::AS3::Value::V2U v9; // edx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::WeakProxy *v11; // eax
  const unsigned int *CP; // ebx
  int v13; // eax
  int v14; // edx
  unsigned int v15; // eax
  const Scaleform::ArrayLH_POD<unsigned int,338,Scaleform::ArrayDefaultPolicy> *OpCode; // eax
  Scaleform::GFx::AS3::Abc::Multiname *v17; // eax
  int v18; // eax
  Scaleform::GFx::AS3::Abc::Multiname *v19; // eax
  Scaleform::GFx::AS3::Instances::fl::Namespace *InternedNamespace; // eax
  unsigned int v21; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v22; // ecx
  int v23; // eax
  int v24; // eax
  Scaleform::GFx::AS3::Value *v25; // ecx
  Scaleform::GFx::AS3::Value *v26; // eax
  Scaleform::GFx::AS3::Value::V1U v27; // ecx
  const unsigned int *v28; // ebx
  int v29; // edx
  Scaleform::GFx::AS3::Value *v30; // eax
  long double v31; // st7
  unsigned int v32; // edx
  long double v33; // st6
  const unsigned int *v34; // ebx
  unsigned int v35; // ecx
  Scaleform::GFx::AS3::Value *pCurrent; // eax
  int v37; // eax
  Scaleform::GFx::AS3::Value *v38; // ecx
  Scaleform::GFx::AS3::Value *v39; // eax
  Scaleform::GFx::AS3::Value::V1U v40; // ecx
  Scaleform::GFx::AS3::Value *v41; // eax
  long double v42; // st7
  unsigned int v43; // edx
  long double v44; // st6
  Scaleform::GFx::AS3::Value *v45; // eax
  int v46; // eax
  Scaleform::GFx::AS3::Value *v47; // ecx
  Scaleform::GFx::AS3::Value *v48; // eax
  Scaleform::GFx::AS3::Value::V1U v49; // ecx
  Scaleform::GFx::AS3::Value *v50; // eax
  long double v51; // st7
  unsigned int v52; // edx
  long double v53; // st6
  int v54; // eax
  Scaleform::GFx::AS3::Value *v55; // ecx
  Scaleform::GFx::AS3::Value *v56; // eax
  Scaleform::GFx::AS3::Value::V1U v57; // ecx
  Scaleform::GFx::AS3::Value *v58; // eax
  long double v59; // st7
  unsigned int v60; // edx
  long double v61; // st6
  Scaleform::GFx::AS3::Value *v62; // ecx
  const unsigned int *v63; // ebx
  bool v64; // al
  char v65; // al
  int v66; // ecx
  Scaleform::GFx::AS3::Value *v67; // eax
  bool VBool; // cl
  unsigned int v69; // edx
  const unsigned int *v70; // ebx
  unsigned int v71; // eax
  Scaleform::GFx::AS3::Value *v72; // ecx
  bool v73; // al
  char v74; // al
  Scaleform::GFx::AS3::Value *v75; // eax
  bool v76; // cl
  unsigned int v77; // edx
  int v78; // eax
  Scaleform::GFx::AS3::Value *v79; // ecx
  Scaleform::GFx::AS3::Value *v80; // eax
  Scaleform::GFx::AS3::Value::V1U v81; // ecx
  Scaleform::GFx::AS3::Value *v82; // eax
  long double v83; // st7
  unsigned int v84; // edx
  long double v85; // st6
  int v86; // eax
  Scaleform::GFx::AS3::Value *v87; // ecx
  Scaleform::GFx::AS3::Value *v88; // eax
  Scaleform::GFx::AS3::Value::V1U v89; // ecx
  Scaleform::GFx::AS3::Value *v90; // eax
  long double v91; // st7
  unsigned int v92; // edx
  long double v93; // st6
  int v94; // eax
  Scaleform::GFx::AS3::Value *v95; // ecx
  Scaleform::GFx::AS3::Value *v96; // eax
  Scaleform::GFx::AS3::Value::V1U v97; // ecx
  const unsigned int *v98; // ebx
  unsigned int v99; // edx
  Scaleform::GFx::AS3::Value *v100; // eax
  int v101; // eax
  Scaleform::GFx::AS3::Value *v102; // ecx
  Scaleform::GFx::AS3::Value *v103; // eax
  Scaleform::GFx::AS3::Value::V1U v104; // ecx
  Scaleform::GFx::AS3::Value *v105; // eax
  int v106; // eax
  Scaleform::GFx::AS3::Value *v107; // ecx
  Scaleform::GFx::AS3::Value *v108; // eax
  Scaleform::GFx::AS3::Value::V1U v109; // ecx
  int v110; // eax
  Scaleform::GFx::AS3::Value *v111; // ecx
  Scaleform::GFx::AS3::Value *v112; // eax
  Scaleform::GFx::AS3::Value::V1U v113; // ecx
  int v114; // eax
  unsigned int v115; // ecx
  Scaleform::GFx::AS3::Value *v116; // eax
  const unsigned int *v117; // ebx
  Scaleform::GFx::AS3::Value *v118; // eax
  unsigned int v119; // ecx
  int v120; // edx
  Scaleform::GFx::AS3::WeakProxy *v121; // edx
  Scaleform::GFx::AS3::Value *v122; // eax
  unsigned int v123; // ecx
  int v124; // edx
  Scaleform::GFx::AS3::WeakProxy *v125; // edx
  const unsigned int *v126; // eax
  const unsigned int *v127; // eax
  Scaleform::GFx::AS3::Value *v128; // eax
  Scaleform::GFx::AS3::Value *v129; // eax
  unsigned int v130; // ecx
  int v131; // edx
  Scaleform::GFx::AS3::WeakProxy *v132; // edx
  unsigned int v133; // ecx
  int v134; // edx
  Scaleform::GFx::AS3::Value *v135; // eax
  unsigned int v136; // edx
  const unsigned int *v137; // ebx
  Scaleform::GFx::ASStringNode *pNode; // edx
  Scaleform::GFx::AS3::Value *v139; // eax
  int v140; // eax
  unsigned int v141; // ecx
  Scaleform::GFx::AS3::Value *v142; // eax
  unsigned int v143; // edx
  Scaleform::GFx::ASStringNode *v144; // ecx
  Scaleform::GFx::AS3::Value::V1U v145; // ecx
  Scaleform::GFx::AS3::Value *v146; // eax
  unsigned int v147; // edx
  Scaleform::GFx::ASStringNode *v148; // ecx
  Scaleform::GFx::AS3::Value *v149; // eax
  Scaleform::GFx::AS3::Value::V2U v150; // edx
  Scaleform::GFx::AS3::Value *v151; // eax
  Scaleform::GFx::AS3::Value::V2U v152; // ecx
  int v153; // eax
  int v154; // edx
  int v155; // ecx
  Scaleform::GFx::AS3::Value *pRF; // ecx
  Scaleform::GFx::AS3::Value *v157; // eax
  Scaleform::StringDataPtr *String; // eax
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS3::Value *v160; // ecx
  Scaleform::GFx::ASStringNode *v161; // eax
  int v162; // ecx
  Scaleform::GFx::AS3::Value *v163; // eax
  unsigned int v164; // ecx
  Scaleform::GFx::AS3::Value *v165; // eax
  Scaleform::GFx::AS3::Value::V1U v166; // ecx
  Scaleform::GFx::AS3::Value *v167; // eax
  Scaleform::GFx::AS3::Value::V2U v168; // edx
  Scaleform::GFx::AS3::Instances::fl::Namespace *v169; // eax
  Scaleform::GFx::AS3::Value::V1U v170; // eax
  Scaleform::GFx::AS3::GlobalSlotIndex v171; // ecx
  Scaleform::GFx::AS3::Value::VU *v172; // eax
  Scaleform::GFx::AS3::Value::VU *v173; // eax
  unsigned int v174; // eax
  unsigned int v175; // ecx
  unsigned int v176; // eax
  unsigned int v177; // ecx
  unsigned int v178; // eax
  unsigned int v179; // ecx
  unsigned int v180; // eax
  unsigned int v181; // ecx
  Scaleform::GFx::AS3::Abc::MiInd v182; // eax
  unsigned int v183; // ecx
  unsigned int v184; // eax
  unsigned int v185; // ecx
  unsigned int v186; // eax
  unsigned int v187; // ecx
  bool v188; // zf
  int v189; // edi
  unsigned int v190; // eax
  unsigned int v191; // ecx
  int v192; // eax
  unsigned int v193; // eax
  unsigned int v194; // ecx
  unsigned int v195; // eax
  unsigned int v196; // ecx
  unsigned int v197; // eax
  unsigned int v198; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *GlobalObject; // eax
  int v200; // edx
  Scaleform::GFx::AS3::Value *v201; // eax
  Scaleform::GFx::AS3::Value *v202; // ecx
  Scaleform::GFx::AS3::Value *v203; // ecx
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v204; // eax
  Scaleform::GFx::AS3::Instances::fl::GlobalObjectScript *v205; // ecx
  Scaleform::GFx::AS3::Value *v206; // eax
  Scaleform::GFx::AS3::Value *v207; // ecx
  Scaleform::GFx::AS3::Value *v208; // eax
  bool v209; // al
  Scaleform::GFx::AS3::Value *v210; // eax
  const Scaleform::GFx::AS3::VM::Error *v211; // eax
  Scaleform::GFx::ASStringNode *v212; // eax
  Scaleform::GFx::AS3::Value *v213; // ecx
  Scaleform::GFx::AS3::Value *v214; // ecx
  Scaleform::GFx::AS3::Value *v215; // ecx
  bool v216; // al
  Scaleform::GFx::AS3::Value *v217; // ecx
  bool v218; // cl
  double *v219; // eax
  double v220; // st7
  Scaleform::GFx::AS3::Value *v221; // eax
  Scaleform::GFx::AS3::Value *v222; // eax
  Scaleform::GFx::AS3::Value::V2U v223; // ecx
  Scaleform::GFx::AS3::StringManager *StringManagerRef; // eax
  Scaleform::GFx::AS3::Value *v225; // eax
  bool v226; // cl
  unsigned int v227; // eax
  Scaleform::GFx::AS3::Value *v228; // eax
  bool v229; // cl
  unsigned int v230; // eax
  Scaleform::GFx::AS3::Value *v231; // ecx
  bool v232; // cl
  double *v233; // eax
  double v234; // st7
  Scaleform::GFx::AS3::Value *v235; // eax
  Scaleform::GFx::AS3::Value *v236; // eax
  long double v237; // st7
  Scaleform::GFx::AS3::Value *v238; // ecx
  bool v239; // cl
  double *v240; // eax
  double v241; // st7
  Scaleform::GFx::AS3::Value *v242; // eax
  Scaleform::GFx::AS3::Value *v243; // ecx
  bool v244; // al
  int *v245; // ecx
  Scaleform::GFx::AS3::Value *v246; // ecx
  Scaleform::GFx::AS3::Value *v247; // ecx
  bool v248; // al
  int *v249; // ecx
  Scaleform::GFx::AS3::Value *v250; // ecx
  Scaleform::GFx::AS3::Value *v251; // ecx
  bool v252; // al
  int *v253; // ecx
  Scaleform::GFx::AS3::Value *v254; // ecx
  Scaleform::GFx::AS3::Value *v255; // ecx
  bool v256; // al
  int *v257; // ecx
  Scaleform::GFx::AS3::Value *v258; // ecx
  Scaleform::GFx::AS3::Value *v259; // ecx
  bool v260; // al
  int *v261; // ecx
  Scaleform::GFx::AS3::Value *v262; // ecx
  Scaleform::GFx::AS3::Value *v263; // ecx
  bool v264; // al
  int *v265; // ecx
  Scaleform::GFx::AS3::Value *v266; // ecx
  Scaleform::GFx::AS3::Value *v267; // eax
  Scaleform::GFx::AS3::Value::V2U v268; // ecx
  bool v269; // dl
  Scaleform::GFx::AS3::Value *v270; // eax
  Scaleform::GFx::AS3::Value::Extra v271; // edx
  Scaleform::GFx::AS3::Value *v272; // eax
  Scaleform::GFx::AS3::Value *v273; // eax
  Scaleform::GFx::AS3::Value::V2U v274; // edx
  Scaleform::GFx::AS3::Value *v275; // eax
  Scaleform::GFx::AS3::Value::V2U v276; // ecx
  Scaleform::GFx::AS3::Value *v277; // eax
  Scaleform::GFx::AS3::Value *v278; // eax
  unsigned int v279; // ecx
  Scaleform::GFx::AS3::Value::V1U v280; // edx
  Scaleform::GFx::AS3::Value::V2U v281; // edx
  const Scaleform::GFx::AS3::VM::Error *v282; // eax
  Scaleform::GFx::ASStringNode *v283; // eax
  Scaleform::GFx::AS3::Value *AbsObject; // eax
  Scaleform::GFx::AS3::Value *v285; // ecx
  Scaleform::GFx::AS3::Value *v286; // ecx
  Scaleform::GFx::AS3::Value::VU *p_value; // eax
  Scaleform::GFx::AS3::Value *v288; // ecx
  Scaleform::GFx::AS3::Value *v289; // ecx
  bool v290; // al
  int *v291; // ecx
  Scaleform::GFx::AS3::Value *v292; // ecx
  Scaleform::GFx::AS3::Value *v293; // eax
  Scaleform::GFx::AS3::Value::V1U v294; // ecx
  Scaleform::GFx::AS3::Value *v295; // eax
  long double VNumber; // st7
  Scaleform::GFx::AS3::Value *v297; // ecx
  bool v298; // al
  int *v299; // ecx
  Scaleform::GFx::AS3::Value *v300; // ecx
  Scaleform::GFx::AS3::Value *v301; // eax
  Scaleform::GFx::AS3::Value::V1U v302; // ecx
  Scaleform::GFx::AS3::Value *v303; // eax
  long double v304; // st7
  Scaleform::GFx::AS3::Value *v305; // ecx
  bool v306; // al
  int *v307; // ecx
  Scaleform::GFx::AS3::Value *v308; // ecx
  Scaleform::GFx::AS3::Value *v309; // eax
  Scaleform::GFx::AS3::Value::V1U v310; // ecx
  Scaleform::GFx::AS3::Value *v311; // eax
  long double v312; // st7
  Scaleform::GFx::AS3::Value *v313; // eax
  Scaleform::GFx::AS3::Value *v314; // eax
  Scaleform::GFx::AS3::Value *v315; // eax
  Scaleform::GFx::AS3::Value *v316; // eax
  int v317; // eax
  Scaleform::GFx::AS3::CallFrame *v318; // edi
  unsigned int v319; // ebx
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpServer *v321; // eax
  int StartTicks_high; // edx
  __int64 v323; // kr08_8
  _DWORD *v324; // ecx
  Scaleform::GFx::AMP::ViewStats *v325; // eax
  Scaleform::GFx::AS3::CallFrame *v326; // eax
  unsigned int Size; // eax
  int v329; // [esp-8h] [ebp-250h]
  unsigned int v330; // [esp-4h] [ebp-24Ch]
  Scaleform::GFx::AS3::Abc::Multiname *v; // [esp+0h] [ebp-248h]
  Scaleform::GFx::AS3::Abc::Multiname *va; // [esp+0h] [ebp-248h]
  unsigned __int64 vb; // [esp+0h] [ebp-248h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v_4; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4a; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4b; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4c; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4d; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4e; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Value *v_4f; // [esp+4h] [ebp-244h]
  unsigned int v_4g; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::AbsoluteIndex v_4h; // [esp+4h] [ebp-244h]
  unsigned int v_4i; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Instances::fl::Namespace *v_4j; // [esp+4h] [ebp-244h]
  unsigned int v_4k; // [esp+4h] [ebp-244h]
  unsigned int v_4l; // [esp+4h] [ebp-244h]
  unsigned int v_4m; // [esp+4h] [ebp-244h]
  unsigned int v_4n; // [esp+4h] [ebp-244h]
  unsigned int v_4o; // [esp+4h] [ebp-244h]
  unsigned int v_4p; // [esp+4h] [ebp-244h]
  unsigned int v_4q; // [esp+4h] [ebp-244h]
  Scaleform::GFx::ASString v_4r; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4s; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v_4t; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4u; // [esp+4h] [ebp-244h]
  unsigned int v_4v; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4w; // [esp+4h] [ebp-244h]
  unsigned int v_4x; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4y; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4z; // [esp+4h] [ebp-244h]
  unsigned int v_4ba; // [esp+4h] [ebp-244h]
  unsigned int v_4bb; // [esp+4h] [ebp-244h]
  unsigned int v_4bc; // [esp+4h] [ebp-244h]
  unsigned int v_4bd; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4be; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4bf; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::Abc::Multiname *v_4bg; // [esp+4h] [ebp-244h]
  Scaleform::GFx::AS3::ClassTraits::fl::Object *v_4bh; // [esp+4h] [ebp-244h]
  unsigned int v_4bi; // [esp+4h] [ebp-244h]
  unsigned int v_4bj; // [esp+4h] [ebp-244h]
  unsigned int v_4bk; // [esp+4h] [ebp-244h]
  unsigned int v_4bl; // [esp+4h] [ebp-244h]
  unsigned int v_4bm; // [esp+4h] [ebp-244h]
  Scaleform::GFx::ASStringNode *v_4bn; // [esp+4h] [ebp-244h]
  int position; // [esp+40h] [ebp-208h] BYREF
  unsigned int v376; // [esp+44h] [ebp-204h]
  double default_offset; // [esp+48h] [ebp-200h] BYREF
  const unsigned int *curr_cp; // [esp+54h] [ebp-1F4h] BYREF
  unsigned int case_count; // [esp+58h] [ebp-1F0h]
  const Scaleform::GFx::AS3::Abc::ConstPool *constp; // [esp+5Ch] [ebp-1ECh]
  Scaleform::GFx::AS3::VMAbcFile *file; // [esp+60h] [ebp-1E8h]
  unsigned int call_stack_size; // [esp+64h] [ebp-1E4h]
  Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value> r; // [esp+68h] [ebp-1E0h] BYREF
  bool tmpHandleException; // [esp+81h] [ebp-1C7h]
  bool v385; // [esp+82h] [ebp-1C6h] BYREF
  bool v386; // [esp+83h] [ebp-1C5h] BYREF
  Scaleform::GFx::AS3::CheckResult v387; // [esp+84h] [ebp-1C4h] BYREF
  Scaleform::GFx::AS3::CheckResult v388; // [esp+85h] [ebp-1C3h] BYREF
  Scaleform::GFx::AS3::CheckResult v389; // [esp+86h] [ebp-1C2h] BYREF
  Scaleform::GFx::AS3::CheckResult v390; // [esp+87h] [ebp-1C1h] BYREF
  Scaleform::GFx::AS3::CheckResult v391; // [esp+88h] [ebp-1C0h] BYREF
  Scaleform::GFx::AS3::CheckResult v392; // [esp+89h] [ebp-1BFh] BYREF
  Scaleform::GFx::AS3::CheckResult v393; // [esp+8Ah] [ebp-1BEh] BYREF
  Scaleform::GFx::AS3::CheckResult v394; // [esp+8Bh] [ebp-1BDh] BYREF
  Scaleform::GFx::AS3::CheckResult v395; // [esp+8Ch] [ebp-1BCh] BYREF
  Scaleform::GFx::AS3::CheckResult v396; // [esp+8Dh] [ebp-1BBh] BYREF
  Scaleform::GFx::AS3::CheckResult v397; // [esp+8Eh] [ebp-1BAh] BYREF
  Scaleform::GFx::AS3::CheckResult v398; // [esp+8Fh] [ebp-1B9h] BYREF
  Scaleform::GFx::AS3::CheckResult v399; // [esp+90h] [ebp-1B8h] BYREF
  Scaleform::GFx::AS3::CheckResult v400; // [esp+91h] [ebp-1B7h] BYREF
  Scaleform::GFx::AS3::CheckResult v401; // [esp+92h] [ebp-1B6h] BYREF
  Scaleform::GFx::AS3::CheckResult v402; // [esp+93h] [ebp-1B5h] BYREF
  Scaleform::GFx::AS3::CheckResult v403; // [esp+94h] [ebp-1B4h] BYREF
  Scaleform::GFx::AS3::CheckResult v404; // [esp+95h] [ebp-1B3h] BYREF
  Scaleform::GFx::AS3::CheckResult v405; // [esp+96h] [ebp-1B2h] BYREF
  Scaleform::GFx::AS3::CheckResult v406; // [esp+97h] [ebp-1B1h] BYREF
  Scaleform::GFx::AS3::CheckResult v407; // [esp+98h] [ebp-1B0h] BYREF
  Scaleform::GFx::AS3::CheckResult v408; // [esp+99h] [ebp-1AFh] BYREF
  Scaleform::GFx::AS3::CheckResult result; // [esp+9Ah] [ebp-1AEh] BYREF
  Scaleform::GFx::AS3::CheckResult v410; // [esp+9Bh] [ebp-1ADh] BYREF
  Scaleform::GFx::AS3::CheckResult v411; // [esp+9Ch] [ebp-1ACh] BYREF
  Scaleform::GFx::AS3::CheckResult v412; // [esp+9Dh] [ebp-1ABh] BYREF
  Scaleform::GFx::AS3::CheckResult v413; // [esp+9Eh] [ebp-1AAh] BYREF
  Scaleform::GFx::AS3::CheckResult v414; // [esp+9Fh] [ebp-1A9h] BYREF
  Scaleform::GFx::AS3::CheckResult v415; // [esp+A0h] [ebp-1A8h] BYREF
  Scaleform::GFx::AS3::CheckResult v416; // [esp+A1h] [ebp-1A7h] BYREF
  Scaleform::GFx::AS3::CheckResult v417; // [esp+A2h] [ebp-1A6h] BYREF
  Scaleform::GFx::AS3::CheckResult v418; // [esp+A3h] [ebp-1A5h] BYREF
  Scaleform::GFx::AS3::CheckResult v419; // [esp+A4h] [ebp-1A4h] BYREF
  Scaleform::GFx::AS3::CheckResult v420; // [esp+A5h] [ebp-1A3h] BYREF
  Scaleform::GFx::AS3::CheckResult v421; // [esp+A6h] [ebp-1A2h] BYREF
  Scaleform::GFx::AS3::CheckResult v422; // [esp+A7h] [ebp-1A1h] BYREF
  Scaleform::GFx::AS3::CheckResult v423; // [esp+A8h] [ebp-1A0h] BYREF
  Scaleform::GFx::AS3::CheckResult v424; // [esp+A9h] [ebp-19Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v425; // [esp+AAh] [ebp-19Eh] BYREF
  Scaleform::GFx::AS3::CheckResult v426; // [esp+ABh] [ebp-19Dh] BYREF
  Scaleform::GFx::AS3::CheckResult v427; // [esp+ACh] [ebp-19Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v428; // [esp+ADh] [ebp-19Bh] BYREF
  Scaleform::GFx::AS3::CheckResult v429; // [esp+AEh] [ebp-19Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v430; // [esp+AFh] [ebp-199h] BYREF
  Scaleform::GFx::AS3::CheckResult v431; // [esp+B0h] [ebp-198h] BYREF
  Scaleform::GFx::AS3::CheckResult v432; // [esp+B1h] [ebp-197h] BYREF
  Scaleform::GFx::AS3::CheckResult v433; // [esp+B2h] [ebp-196h] BYREF
  Scaleform::GFx::AS3::CheckResult v434; // [esp+B3h] [ebp-195h] BYREF
  Scaleform::GFx::AS3::CheckResult v435; // [esp+B4h] [ebp-194h] BYREF
  Scaleform::GFx::AS3::CheckResult v436; // [esp+B5h] [ebp-193h] BYREF
  Scaleform::GFx::AS3::CheckResult v437; // [esp+B6h] [ebp-192h] BYREF
  Scaleform::GFx::AS3::CheckResult v438; // [esp+B7h] [ebp-191h] BYREF
  Scaleform::GFx::AS3::CheckResult v439; // [esp+B8h] [ebp-190h] BYREF
  Scaleform::GFx::AS3::CheckResult v440; // [esp+B9h] [ebp-18Fh] BYREF
  Scaleform::GFx::AS3::CheckResult v441; // [esp+BAh] [ebp-18Eh] BYREF
  Scaleform::GFx::AS3::CheckResult v442; // [esp+BBh] [ebp-18Dh] BYREF
  Scaleform::GFx::AS3::CheckResult v443; // [esp+BCh] [ebp-18Ch] BYREF
  Scaleform::GFx::AS3::CheckResult v444; // [esp+BDh] [ebp-18Bh] BYREF
  Scaleform::GFx::AS3::CheckResult v445; // [esp+BEh] [ebp-18Ah] BYREF
  Scaleform::GFx::AS3::CheckResult v446; // [esp+BFh] [ebp-189h] BYREF
  Scaleform::GFx::AS3::VM::Error v447; // [esp+C0h] [ebp-188h] BYREF
  Scaleform::GFx::AS3::Boolean3 v448; // [esp+CCh] [ebp-17Ch] BYREF
  char v449; // [esp+D0h] [ebp-178h]
  int v450; // [esp+D4h] [ebp-174h]
  char v451; // [esp+DCh] [ebp-16Ch]
  int v452; // [esp+E0h] [ebp-168h]
  int v453; // [esp+E8h] [ebp-160h] BYREF
  char v454; // [esp+ECh] [ebp-15Ch]
  int v455; // [esp+F0h] [ebp-158h]
  __int64 v456; // [esp+F8h] [ebp-150h]
  char v457; // [esp+100h] [ebp-148h]
  int v458; // [esp+104h] [ebp-144h]
  char v459; // [esp+10Ch] [ebp-13Ch]
  int v460; // [esp+110h] [ebp-138h]
  char v461; // [esp+118h] [ebp-130h]
  int v462; // [esp+11Ch] [ebp-12Ch]
  Scaleform::GFx::AS3::Boolean3 v463; // [esp+124h] [ebp-124h] BYREF
  char v464; // [esp+128h] [ebp-120h]
  int v465; // [esp+12Ch] [ebp-11Ch]
  bool v466[4]; // [esp+134h] [ebp-114h] BYREF
  char v467; // [esp+138h] [ebp-110h]
  int v468; // [esp+13Ch] [ebp-10Ch]
  Scaleform::GFx::AS3::Boolean3 v469; // [esp+144h] [ebp-104h] BYREF
  char v470; // [esp+148h] [ebp-100h]
  int v471; // [esp+14Ch] [ebp-FCh]
  Scaleform::GFx::AS3::Boolean3 v472; // [esp+154h] [ebp-F4h] BYREF
  Scaleform::GFx::AS3::Value tmpExceptionValue; // [esp+158h] [ebp-F0h] BYREF
  Scaleform::GFx::AS3::Value::V1U v474; // [esp+168h] [ebp-E0h]
  Scaleform::GFx::AS3::Value::V2U v475; // [esp+16Ch] [ebp-DCh]
  Scaleform::StringDataPtr v476; // [esp+170h] [ebp-D8h] BYREF
  Scaleform::GFx::AS3::Value::V1U v477; // [esp+178h] [ebp-D0h]
  Scaleform::GFx::AS3::Value::V2U v478; // [esp+17Ch] [ebp-CCh]
  unsigned int v479; // [esp+184h] [ebp-C4h]
  Scaleform::GFx::AS3::Value v480; // [esp+188h] [ebp-C0h] BYREF
  long double Double; // [esp+198h] [ebp-B0h]
  double v482; // [esp+1A0h] [ebp-A8h]
  Scaleform::GFx::AS3::Value other; // [esp+1A8h] [ebp-A0h] BYREF
  Scaleform::GFx::AS3::Value v484; // [esp+1B8h] [ebp-90h] BYREF
  Scaleform::GFx::AS3::VM::Error v485; // [esp+1C8h] [ebp-80h] BYREF
  long double v486; // [esp+1D0h] [ebp-78h] BYREF
  char v487; // [esp+1D8h] [ebp-70h]
  long double v488; // [esp+1E0h] [ebp-68h]
  long double v489; // [esp+1F0h] [ebp-58h] BYREF
  long double v490; // [esp+1F8h] [ebp-50h] BYREF
  char v491; // [esp+200h] [ebp-48h]
  double v492; // [esp+208h] [ebp-40h]
  long double v493; // [esp+218h] [ebp-30h] BYREF
  char v494; // [esp+220h] [ebp-28h]
  double v495; // [esp+228h] [ebp-20h]
  Scaleform::GFx::AS3::Value v496; // [esp+238h] [ebp-10h] BYREF

  v188 = this->CallStack.Size == 0;
  v376 = 0;
  if ( v188 )
    return max_stack_depth;
  while ( 1 )
  {
    Pages = this->CallStack.Pages;
    call_stack_size = this->CallStack.Size;
    v4 = &Pages[(call_stack_size - 1) >> 6][(call_stack_size - 1) & 0x3F];
    v5 = this->ExceptionObj.value.VS._1;
    pWeakProxy = this->ExceptionObj.Bonus.pWeakProxy;
    file = v4->pFile;
    p_ExceptionObj = &this->ExceptionObj;
    constp = &file->File.pObject->Const_Pool;
    HandleException = this->HandleException;
    tmpExceptionValue.value.VS._1 = v5;
    v9.VObj = (Scaleform::GFx::AS3::Object *)this->ExceptionObj.value.VS._2;
    tmpHandleException = HandleException;
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
        v188 = v11->RefCount-- == 1;
        if ( v188 )
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
    if ( !v4->CP )
      v4->CP = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
    v188 = !this->HandleException;
    CP = v4->CP;
    _mm_prefetch((const char *)CP, 2);
    if ( !v188 )
    {
LABEL_597:
      v189 = 2;
      goto call_stack_label;
    }
    if ( tmpHandleException )
    {
      this->HandleException = tmpHandleException;
      Scaleform::GFx::AS3::Value::Assign(&this->ExceptionObj, &tmpExceptionValue);
    }
LABEL_17:
    if ( this->HandleException )
    {
      position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
      v13 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
      if ( v13 < 0 )
        goto LABEL_597;
      v14 = position;
LABEL_20:
      CP = (const unsigned int *)(v14 + 4 * v13);
    }
    while ( 2 )
    {
      v15 = *CP;
      curr_cp = CP++;
      switch ( v15 )
      {
        case 3u:
          position = Scaleform::GFx::AS3::VM::exec_throw(this, CP, v4);
          if ( position < 0 )
            goto LABEL_597;
          OpCode = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4);
          CP = &OpCode->Data.Data[position];
          continue;
        case 4u:
          v17 = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_getsuper(this, file, v4->OriginationTraits, v17);
          goto LABEL_25;
        case 5u:
          v19 = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_setsuper(this, file, v4->OriginationTraits, v19);
LABEL_25:
          if ( !this->HandleException )
            continue;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v18 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v18 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v18);
          continue;
        case 6u:
          v_4 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*CP++;
          InternedNamespace = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(v4->pFile, v_4);
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
              v21 = curr_cp[4];
              if ( (v21 & 0x3FFFFF) != 0 )
              {
                v22 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)curr_cp;
                *((_DWORD *)curr_cp + 4) = v21 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v22);
              }
            }
          }
          goto LABEL_17;
        case 7u:
          Scaleform::GFx::AS3::VM::exec_dxnslate(this);
          goto LABEL_17;
        case 8u:
          v23 = *CP++;
          position = v23;
          if ( (_S15 & 1) == 0 )
          {
            _S15 |= 1u;
            ::v.Flags = 0;
            ::v.Bonus.pWeakProxy = 0;
            atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
          }
          Scaleform::GFx::AS3::Value::Assign(&this->RegisterFile.pRF[position], &::v);
          continue;
        case 0xAu:
          p_value = &this->RegisterFile.pRF[*CP++].value;
          ++p_value->VS._1.VInt;
          continue;
        case 0xBu:
        case 0x38u:
          v173 = &this->RegisterFile.pRF[*CP++].value;
          --v173->VS._1.VInt;
          continue;
        case 0xCu:
          v_4a = this->OpStack.pCurrent;
          position = *CP++;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&result, &v448, v_4a - 1, v_4a)->Result && v448 != true3 )
            curr_cp = (const unsigned int *)position;
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_45;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v24 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v24 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v24);
LABEL_45:
          CP += (int)curr_cp;
          continue;
        case 0xDu:
          pCurrent = this->OpStack.pCurrent;
          position = *CP++;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v394, &v472, pCurrent, pCurrent - 1)->Result && v472 != false3 )
            curr_cp = (const unsigned int *)position;
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_58;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v37 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v37 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v37);
LABEL_58:
          CP += (int)curr_cp;
          continue;
        case 0xEu:
          v45 = this->OpStack.pCurrent;
          position = *CP++;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v396, &v469, v45, v45 - 1)->Result && v469 != true3 )
            curr_cp = (const unsigned int *)position;
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_58;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v46 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v46 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v46 + 4 * (_DWORD)curr_cp);
          continue;
        case 0xFu:
          v_4b = this->OpStack.pCurrent;
          position = *CP++;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v398, &v463, v_4b - 1, v_4b)->Result && v463 != false3 )
            curr_cp = (const unsigned int *)position;
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_58;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v54 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v54 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v54 + 4 * (_DWORD)curr_cp);
          continue;
        case 0x10u:
          CP += *CP + 1;
          continue;
        case 0x11u:
          v62 = this->OpStack.pCurrent;
          position = *CP;
          v63 = CP + 1;
          curr_cp = &v62->Flags;
          v64 = Scaleform::GFx::AS3::Value::Convert2Boolean(v62);
          Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)curr_cp, v64);
          v65 = *((_BYTE *)curr_cp + 8);
          --this->OpStack.pCurrent;
          v66 = 0;
          if ( v65 == 1 )
            v66 = position;
          goto LABEL_86;
        case 0x12u:
          v72 = this->OpStack.pCurrent;
          position = *CP;
          v63 = CP + 1;
          curr_cp = &v72->Flags;
          v73 = Scaleform::GFx::AS3::Value::Convert2Boolean(v72);
          Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)curr_cp, v73);
          v74 = *((_BYTE *)curr_cp + 8);
          --this->OpStack.pCurrent;
          v66 = 0;
          if ( v74 )
LABEL_86:
            CP = &v63[v66];
          else
            CP = &v63[position];
          continue;
        case 0x13u:
          position = *CP;
          v_4c = this->OpStack.pCurrent;
          ++CP;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractEqual(&v400, &v386, v_4c - 1, v_4c)->Result && v386 )
            curr_cp = (const unsigned int *)position;
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_58;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v78 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v78 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v78 + 4 * (_DWORD)curr_cp);
          continue;
        case 0x14u:
          v_4d = this->OpStack.pCurrent;
          position = *CP++;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractEqual(&v402, &v385, v_4d - 1, v_4d)->Result && !v385 )
            curr_cp = (const unsigned int *)position;
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_58;
          position = (int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v86 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - position) >> 2, (unsigned int)v4);
          if ( v86 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(position + 4 * v86 + 4 * (_DWORD)curr_cp);
          continue;
        case 0x15u:
          v_4e = this->OpStack.pCurrent;
          case_count = *CP++;
          position = 0;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v404, (Scaleform::GFx::AS3::Boolean3 *)&curr_cp, v_4e - 1, v_4e)->Result
            && curr_cp == (const unsigned int *)1 )
          {
            position = case_count;
          }
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_120;
          case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v94 = Scaleform::GFx::AS3::VM::OnException(this, (int)((int)CP - case_count) >> 2, (unsigned int)v4);
          if ( v94 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(case_count + 4 * v94);
LABEL_120:
          CP += position;
          continue;
        case 0x16u:
          v100 = this->OpStack.pCurrent;
          case_count = *CP++;
          curr_cp = 0;
          position = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v443, (Scaleform::GFx::AS3::Boolean3 *)&position, v100, v100 - 1)->Result
            && position == 2 )
          {
            curr_cp = (const unsigned int *)case_count;
          }
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_130;
          case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v101 = Scaleform::GFx::AS3::VM::OnException(this, (int)((int)CP - case_count) >> 2, (unsigned int)v4);
          if ( v101 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(case_count + 4 * v101);
LABEL_130:
          CP += (int)curr_cp;
          continue;
        case 0x17u:
          v105 = this->OpStack.pCurrent;
          case_count = *CP++;
          curr_cp = 0;
          position = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v445, (Scaleform::GFx::AS3::Boolean3 *)&position, v105, v105 - 1)->Result
            && position == 1 )
          {
            curr_cp = (const unsigned int *)case_count;
          }
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_130;
          case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v106 = Scaleform::GFx::AS3::VM::OnException(this, (int)((int)CP - case_count) >> 2, (unsigned int)v4);
          if ( v106 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(case_count + 4 * v106 + 4 * (_DWORD)curr_cp);
          continue;
        case 0x18u:
          v_4f = this->OpStack.pCurrent;
          case_count = *CP++;
          curr_cp = 0;
          position = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v442, (Scaleform::GFx::AS3::Boolean3 *)&position, v_4f - 1, v_4f)->Result
            && position == 2 )
          {
            curr_cp = (const unsigned int *)case_count;
          }
          Scaleform::GFx::AS3::VSBase::PopBack(&this->OpStack, 2u);
          if ( !this->HandleException )
            goto LABEL_130;
          case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v110 = Scaleform::GFx::AS3::VM::OnException(this, (int)((int)CP - case_count) >> 2, (unsigned int)v4);
          if ( v110 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(case_count + 4 * v110 + 4 * (_DWORD)curr_cp);
          continue;
        case 0x19u:
          case_count = *CP;
          v116 = this->OpStack.pCurrent;
          v117 = CP + 1;
          curr_cp = 0;
          if ( Scaleform::GFx::AS3::StrictEqual(v116, v116 - 1) )
            curr_cp = (const unsigned int *)case_count;
          v118 = this->OpStack.pCurrent;
          v119 = v118->Flags;
          v120 = v118->Flags & 0x1F;
          position = (int)v118;
          if ( (char)v120 > 9 )
          {
            if ( (v119 & 0x200) != 0 )
            {
              v121 = v118->Bonus.pWeakProxy;
              v188 = v121->RefCount-- == 1;
              if ( v188 )
              {
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v121);
                v118 = (Scaleform::GFx::AS3::Value *)position;
              }
              v118->Flags &= 0xFFFFFDE0;
              v118->Bonus.pWeakProxy = 0;
              v118->value.VS._1.VInt = 0;
              v118->value.VS._2.VObj = 0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(v118);
            }
          }
          v122 = --this->OpStack.pCurrent;
          v123 = v122->Flags;
          v124 = v122->Flags & 0x1F;
          position = (int)v122;
          if ( (char)v124 <= 9 )
            goto LABEL_166;
          if ( (v123 & 0x200) == 0 )
            goto LABEL_165;
          v125 = v122->Bonus.pWeakProxy;
          v188 = v125->RefCount-- == 1;
          if ( v188 )
            goto LABEL_163;
          goto LABEL_164;
        case 0x1Au:
          v128 = this->OpStack.pCurrent;
          case_count = *CP;
          v117 = CP + 1;
          curr_cp = 0;
          if ( !Scaleform::GFx::AS3::StrictEqual(v128, v128 - 1) )
            curr_cp = (const unsigned int *)case_count;
          v129 = this->OpStack.pCurrent;
          v130 = v129->Flags;
          v131 = v129->Flags & 0x1F;
          position = (int)v129;
          if ( (char)v131 > 9 )
          {
            if ( (v130 & 0x200) != 0 )
            {
              v132 = v129->Bonus.pWeakProxy;
              v188 = v132->RefCount-- == 1;
              if ( v188 )
              {
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v132);
                v129 = (Scaleform::GFx::AS3::Value *)position;
              }
              v129->Flags &= 0xFFFFFDE0;
              v129->Bonus.pWeakProxy = 0;
              v129->value.VS._1.VInt = 0;
              v129->value.VS._2.VObj = 0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(v129);
            }
          }
          v122 = --this->OpStack.pCurrent;
          v133 = v122->Flags;
          v134 = v122->Flags & 0x1F;
          position = (int)v122;
          if ( (char)v134 <= 9 )
            goto LABEL_166;
          if ( (v133 & 0x200) != 0 )
          {
            v125 = v122->Bonus.pWeakProxy;
            v188 = v125->RefCount-- == 1;
            if ( v188 )
            {
LABEL_163:
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v125);
              v122 = (Scaleform::GFx::AS3::Value *)position;
            }
LABEL_164:
            v122->Bonus.pWeakProxy = 0;
            v122->value.VS._1.VInt = 0;
            v122->value.VS._2.VObj = 0;
            v122->Flags &= 0xFFFFFDE0;
            v126 = curr_cp;
            --this->OpStack.pCurrent;
            CP = &v117[(_DWORD)v126];
          }
          else
          {
LABEL_165:
            Scaleform::GFx::AS3::Value::ReleaseInternal(v122);
LABEL_166:
            v127 = curr_cp;
            --this->OpStack.pCurrent;
            CP = &v117[(_DWORD)v127];
          }
          continue;
        case 0x1Bu:
          v135 = this->OpStack.pCurrent;
          v136 = CP[1];
          LODWORD(default_offset) = *CP;
          v137 = CP + 1;
          position = v135->value.VS._1.VInt;
          case_count = v136;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(v135, 0);
          --this->OpStack.pCurrent;
          if ( position < 0 || position > case_count )
            CP = &curr_cp[LODWORD(default_offset)];
          else
            CP = &curr_cp[v137[position + 1]];
          continue;
        case 0x1Cu:
          Scaleform::GFx::AS3::VM::exec_pushwith(this);
          goto LABEL_184;
        case 0x1Du:
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            &this->ScopeStack.Data,
            this->ScopeStack.Data.Size - 1);
          continue;
        case 0x1Eu:
          Scaleform::GFx::AS3::VM::exec_nextname(this);
          goto LABEL_184;
        case 0x1Fu:
          Scaleform::GFx::AS3::VM::exec_hasnext(this);
          goto LABEL_184;
        case 0x20u:
          ++this->OpStack.pCurrent;
          pNode = v447.Message.pNode;
          this->OpStack.pCurrent->Flags = 0;
          v139 = this->OpStack.pCurrent;
          v139->Flags = v139->Flags & 0xFFFFFFE0 | 0xC;
          v139->value.VS._1.VInt = 0;
          v139->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)pNode;
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
          goto LABEL_194;
        case 0x24u:
          v141 = *CP;
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          v142 = this->OpStack.pCurrent;
          v143 = v142->Flags & 0xFFFFFFE2;
          ++CP;
          v142->value.VS._1.VInt = (char)v141;
          v144 = v447.Message.pNode;
          v142->Flags = v143 | 2;
          v142->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v144;
          continue;
        case 0x25u:
          v145 = *(Scaleform::GFx::AS3::Value::V1U *)CP;
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          v146 = this->OpStack.pCurrent;
          v147 = v146->Flags & 0xFFFFFFE2;
          ++CP;
          v146->value.VS._1 = v145;
          v148 = v447.Message.pNode;
          v146->Flags = v147 | 2;
          v146->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v148;
          continue;
        case 0x26u:
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          v149 = this->OpStack.pCurrent;
          v149->Flags = v149->Flags & 0xFFFFFFE0 | 1;
          v150.VObj = v478.VObj;
          v477.VBool = 1;
          v149->value.VS._1 = v477;
          v149->value.VS._2 = v150;
          continue;
        case 0x27u:
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          v151 = this->OpStack.pCurrent;
          v151->Flags = v151->Flags & 0xFFFFFFE0 | 1;
          v152.VObj = v475.VObj;
          v474.VBool = 0;
          v151->value.VS._1 = v474;
          v151->value.VS._2 = v152;
          continue;
        case 0x28u:
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          LODWORD(default_offset) = this->OpStack.pCurrent;
          v482 = Scaleform::GFx::NumberUtil::NaN();
          v153 = LODWORD(default_offset);
          v154 = LODWORD(v482);
          *(_DWORD *)LODWORD(default_offset) = *(_DWORD *)LODWORD(default_offset) & 0xFFFFFFE0 | 4;
          v155 = HIDWORD(v482);
          *(_DWORD *)(v153 + 8) = v154;
          *(_DWORD *)(v153 + 12) = v155;
          continue;
        case 0x29u:
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          goto $LN199_0;
        case 0x2Au:
          pRF = this->OpStack.pCurrent;
          this->OpStack.pCurrent = pRF + 1;
          v157 = this->OpStack.pCurrent;
          if ( pRF == (Scaleform::GFx::AS3::Value *)-16 )
            continue;
          v157->Flags = pRF->Flags;
          v157->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
          v157->value.VS._1.VInt = pRF->value.VS._1.VInt;
          v157->value.VS._2.VObj = pRF->value.VS._2.VObj;
          if ( (pRF->Flags & 0x1F) <= 9 )
            continue;
          if ( (pRF->Flags & 0x200) == 0 )
            goto LABEL_263;
          ++pRF->Bonus.pWeakProxy->RefCount;
          continue;
        case 0x2Bu:
          Scaleform::GFx::AS3::VSBase::SwapTop(&this->OpStack);
          continue;
        case 0x2Cu:
          v_4h.Index = *CP++;
          String = Scaleform::GFx::AS3::Abc::ConstPool::GetString(
                     (Scaleform::GFx::AS3::Abc::ConstPool *)constp,
                     &v476,
                     v_4h);
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         this->StringManagerRef->pStringManager,
                         (__m128i *)String->pStr,
                         String->Size);
          ++StringNode->RefCount;
          v160 = this->OpStack.pCurrent;
          curr_cp = (const unsigned int *)StringNode;
          Scaleform::GFx::AS3::Value::AssignUnsafe(v160, (const Scaleform::GFx::ASString *)&curr_cp);
          v161 = (Scaleform::GFx::ASStringNode *)curr_cp;
          v188 = curr_cp[3]-- == 1;
          if ( v188 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v161);
          continue;
        case 0x2Du:
          v162 = constp->ConstInt.Data.Data[*CP];
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          v163 = this->OpStack.pCurrent;
          ++CP;
          v163->Flags = v163->Flags & 0xFFFFFFE0 | 2;
          v163->value.VS._1.VInt = v162;
          v163->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v476.Size;
          continue;
        case 0x2Eu:
          v164 = constp->ConstUInt.Data.Data[*CP];
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          v165 = this->OpStack.pCurrent;
          ++CP;
          v165->Flags = v165->Flags & 0xFFFFFFE0 | 3;
          v165->value.VS._1.VInt = v164;
          v165->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v476.Size;
          continue;
        case 0x2Fu:
          v_4i = *CP++;
          Double = Scaleform::GFx::AS3::Abc::ConstPool::GetDouble((Scaleform::GFx::AS3::Abc::ConstPool *)constp, v_4i);
          ++this->OpStack.pCurrent;
          v166 = LODWORD(Double);
          this->OpStack.pCurrent->Flags = 0;
          v167 = this->OpStack.pCurrent;
          v167->Flags = v167->Flags & 0xFFFFFFE0 | 4;
          v168.VObj = *(Scaleform::GFx::AS3::Object **)((char *)&Double + 4);
          v167->value.VS._1 = v166;
          v167->value.VS._2 = v168;
          continue;
        case 0x30u:
          Scaleform::GFx::AS3::VM::exec_pushscope(this);
          goto LABEL_184;
        case 0x31u:
          v_4j = (Scaleform::GFx::AS3::Instances::fl::Namespace *)*CP++;
          v169 = Scaleform::GFx::AS3::VMFile::GetInternedNamespace(file, v_4j);
          ++this->OpStack.pCurrent;
          this->OpStack.pCurrent->Flags = 0;
          Scaleform::GFx::AS3::Value::AssignUnsafe(this->OpStack.pCurrent, v169);
          continue;
        case 0x32u:
          v170 = *(Scaleform::GFx::AS3::Value::V1U *)CP;
          v171.Index = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_hasnext2(this, v170, v171);
          goto LABEL_184;
        case 0x33u:
          v67 = this->OpStack.pCurrent;
          VBool = v67->value.VS._1.VBool;
          v69 = *CP;
          this->OpStack.pCurrent = v67 - 1;
          v70 = CP + 1;
          v71 = 0;
          if ( VBool )
            v71 = v69;
          goto LABEL_89;
        case 0x34u:
          v75 = this->OpStack.pCurrent;
          v76 = v75->value.VS._1.VBool;
          v77 = *CP;
          this->OpStack.pCurrent = v75 - 1;
          v70 = CP + 1;
          v71 = 0;
          if ( v76 )
LABEL_89:
            CP = &v70[v71];
          else
            CP = &v70[v77];
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
          v172 = &this->RegisterFile.pRF[*CP++].value;
          ++v172->VS._1.VInt;
          continue;
        case 0x3Fu:
          this->OpStack.pCurrent->value.VS._1.VInt = -this->OpStack.pCurrent->value.VS._1.VInt;
          continue;
        case 0x40u:
          v_4k = *CP++;
          Scaleform::GFx::AS3::VM::exec_newfunction(this, (Scaleform::GFx::AS3::Instances::FunctionBase *)v4, v_4k);
          continue;
        case 0x41u:
          v_4l = *CP++;
          Scaleform::GFx::AS3::VM::exec_call(this, v_4l);
          goto LABEL_240;
        case 0x42u:
          v_4m = *CP++;
          Scaleform::GFx::AS3::VM::exec_construct(this, v_4m);
          goto LABEL_240;
        case 0x43u:
          v174 = *CP;
          v175 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callmethod(this, v174, v175);
          goto LABEL_240;
        case 0x44u:
          v182.Ind = *CP;
          v183 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callstatic(this, file, v182, v183);
          goto LABEL_240;
        case 0x45u:
          v184 = *CP;
          v185 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callsuper(
            this,
            file,
            v4->OriginationTraits,
            &constp->const_multiname.Data.Data[v184],
            v185);
          goto LABEL_240;
        case 0x46u:
          v186 = *CP;
          v187 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callproperty(this, file, &constp->const_multiname.Data.Data[v186], v187);
          goto LABEL_240;
        case 0x47u:
          Scaleform::GFx::AS3::VM::exec_returnvoid(this);
          goto LABEL_597;
        case 0x48u:
          Scaleform::GFx::AS3::VM::exec_returnvalue(this);
          if ( this->HandleException )
          {
            LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
            v317 = Scaleform::GFx::AS3::VM::OnException(
                     this,
                     ((int)CP - LODWORD(default_offset)) >> 2,
                     (unsigned int)v4);
            if ( v317 >= 0 )
              CP = (const unsigned int *)(LODWORD(default_offset) + 4 * v317);
          }
          goto LABEL_597;
        case 0x49u:
          v_4n = *CP++;
          Scaleform::GFx::AS3::VM::exec_constructsuper(this, v4->OriginationTraits, v_4n);
          goto LABEL_232;
        case 0x4Au:
          v190 = *CP;
          v191 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_constructprop(this, file, &constp->const_multiname.Data.Data[v190], v191);
          goto LABEL_240;
        case 0x4Cu:
          v193 = *CP;
          v194 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callproplex(this, file, &constp->const_multiname.Data.Data[v193], v194);
          goto LABEL_240;
        case 0x4Eu:
          v195 = *CP;
          v196 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callsupervoid(
            this,
            file,
            v4->OriginationTraits,
            &constp->const_multiname.Data.Data[v195],
            v196);
          goto LABEL_240;
        case 0x4Fu:
          v197 = *CP;
          v198 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callpropvoid(this, file, &constp->const_multiname.Data.Data[v197], v198);
          goto LABEL_240;
        case 0x53u:
          v_4o = *CP++;
          Scaleform::GFx::AS3::VM::exec_applytype(this, v_4o);
          goto LABEL_184;
        case 0x54u:
          this->OpStack.pCurrent->value.VNumber = -this->OpStack.pCurrent->value.VNumber;
          continue;
        case 0x55u:
          v_4p = *CP++;
          Scaleform::GFx::AS3::VM::exec_newobject(this, v_4p);
          continue;
        case 0x56u:
          v_4q = *CP++;
          Scaleform::GFx::AS3::VM::exec_newarray(this, v_4q);
          continue;
        case 0x57u:
          Scaleform::GFx::AS3::VM::exec_newactivation(this, (Scaleform::GFx::ASStringNode *)v4);
          continue;
        case 0x58u:
          v_4r.pNode = (Scaleform::GFx::ASStringNode *)*CP++;
          Scaleform::GFx::AS3::VM::exec_newclass(this, (Scaleform::GFx::ASStringNode *)file, v_4r);
          goto LABEL_240;
        case 0x59u:
          v_4s = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_getdescendants(this, file, v_4s);
          goto LABEL_184;
        case 0x5Au:
          v_4t = &v4->pFile->Exceptions.Data.Data[v4->MBIIndex.Ind].info.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_newcatch(this, file, v_4t);
          continue;
        case 0x5Du:
          v = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_findpropstrict(this, file, v, v4->pSavedScope);
          goto LABEL_184;
        case 0x5Eu:
          ++CP;
          GlobalObject = Scaleform::GFx::AS3::CallFrame::GetGlobalObject(v4);
          Scaleform::GFx::AS3::VM::exec_findproperty(
            this,
            file,
            &constp->const_multiname.Data.Data[v200],
            v4->pSavedScope,
            GlobalObject);
          goto LABEL_184;
        case 0x60u:
          va = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_getlex(this, file, va, v4->pSavedScope);
          goto LABEL_184;
        case 0x61u:
          v_4u = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_setproperty(this, file, v_4u);
          goto LABEL_184;
        case 0x62u:
          v201 = &this->RegisterFile.pRF[*CP++];
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v202 = this->OpStack.pCurrent;
          if ( v188 )
            continue;
          v202->Flags = v201->Flags;
          v202->Bonus.pWeakProxy = v201->Bonus.pWeakProxy;
          v202->value.VS._1.VInt = v201->value.VS._1.VInt;
          v202->value.VS._2.VObj = v201->value.VS._2.VObj;
          if ( (v201->Flags & 0x1F) <= 9 )
            continue;
          if ( (v201->Flags & 0x200) != 0 )
          {
            ++v201->Bonus.pWeakProxy->RefCount;
          }
          else
          {
            pRF = v201;
LABEL_263:
            Scaleform::GFx::AS3::Value::AddRefInternal(pRF);
          }
          continue;
        case 0x63u:
          v203 = &this->RegisterFile.pRF[*CP++];
          Scaleform::GFx::AS3::Value::Pick(v203, this->OpStack.pCurrent);
          --this->OpStack.pCurrent;
          continue;
        case 0x64u:
          v204 = Scaleform::GFx::AS3::VM::GetGlobalObject(this);
          v205 = v204;
          v480.Flags = 12;
          v480.Bonus.pWeakProxy = 0;
          v480.value.VS._1.VInt = (int)v204;
          if ( v204 )
            v204->RefCount = (v204->RefCount + 1) & 0x8FBFFFFF;
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v206 = this->OpStack.pCurrent;
          if ( !v188 )
          {
            v206->value.VS._1.VInt = (int)v205;
            v206->value.VS._2.VObj = v480.value.VS._2.VObj;
            v206->Flags = 12;
            v206->Bonus.pWeakProxy = 0;
            Scaleform::GFx::AS3::Value::AddRefInternal(&v480);
          }
          Scaleform::GFx::AS3::Value::~Value(&v480);
          continue;
        case 0x65u:
          v_4v = *CP++ + v4->ScopeStackBaseInd;
          Scaleform::GFx::AS3::VM::exec_getscopeobject(this, v_4v);
          continue;
        case 0x66u:
          v_4w = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_getproperty(this, file, v_4w);
          goto LABEL_184;
        case 0x67u:
          v_4x = *CP++;
          Scaleform::GFx::AS3::VM::exec_getouterscope(this, v4, v_4x);
          continue;
        case 0x68u:
          v_4y = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_initproperty(this, file, v_4y);
          goto LABEL_184;
        case 0x69u:
          v207 = this->OpStack.pCurrent;
          this->OpStack.pCurrent = v207 + 1;
          v208 = this->OpStack.pCurrent;
          if ( v207 != (Scaleform::GFx::AS3::Value *)-16 )
          {
            v208->Flags = v207->Flags;
            v208->Bonus.pWeakProxy = v207->Bonus.pWeakProxy;
            v208->value.VS._1.VInt = v207->value.VS._1.VInt;
            v208->value.VS._2.VObj = v207->value.VS._2.VObj;
          }
          continue;
        case 0x6Au:
          v_4z = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_deleteproperty(this, file, v_4z);
          goto LABEL_184;
        case 0x6Bu:
$LN199_0:
          --this->OpStack.pCurrent;
          continue;
        case 0x6Cu:
          v_4ba = *CP++;
          Scaleform::GFx::AS3::VM::exec_getslot(this, v_4ba);
          goto LABEL_194;
        case 0x6Du:
          v_4bb = *CP++;
          Scaleform::GFx::AS3::VM::exec_setslot(this, v_4bb);
          goto LABEL_194;
        case 0x6Eu:
          v_4bc = *CP++;
          Scaleform::GFx::AS3::VM::exec_getglobalslot(this, v_4bc);
          goto LABEL_194;
        case 0x6Fu:
          v_4bd = *CP++;
          Scaleform::GFx::AS3::VM::exec_setglobalslot(this, v_4bd);
          goto LABEL_194;
        case 0x70u:
          Scaleform::GFx::AS3::Value::ToStringValue(
            this->OpStack.pCurrent,
            &v389,
            (Scaleform::GFx::ASStringNode *)this->StringManagerRef);
          goto LABEL_184;
        case 0x71u:
          Scaleform::GFx::AS3::VM::exec_esc_xelem(this);
          goto LABEL_184;
        case 0x72u:
          Scaleform::GFx::AS3::VM::exec_esc_xattr(this);
          goto LABEL_184;
        case 0x73u:
          Scaleform::GFx::AS3::Value::ToInt32Value(this->OpStack.pCurrent, &v423);
          goto LABEL_184;
        case 0x74u:
          Scaleform::GFx::AS3::Value::ToUInt32Value(this->OpStack.pCurrent, &v391);
          goto LABEL_184;
        case 0x75u:
          Scaleform::GFx::AS3::Value::ToNumberValue(this->OpStack.pCurrent, &v425);
          goto LABEL_184;
        case 0x76u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          v209 = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)LODWORD(default_offset));
          Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), v209);
          continue;
        case 0x77u:
          v210 = this->OpStack.pCurrent;
          if ( (v210->Flags & 0x1F) == 0 || (v210->Flags & 0x1F) - 12 <= 3 && !v210->value.VS._1.VInt )
          {
            Scaleform::GFx::AS3::VM::Error::Error(&v485, eConvertNullToObjectError, this);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              this,
              v211,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
            v212 = v485.Message.pNode;
            --v485.Message.pNode->RefCount;
            if ( !v212->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v212);
          }
          goto LABEL_184;
        case 0x78u:
          Scaleform::GFx::AS3::VM::exec_checkfilter(this);
          continue;
        case 0x79u:
          v293 = this->OpStack.pCurrent;
          v294 = v293->value.VS._1;
          this->OpStack.pCurrent = v293 - 1;
          v293[-1].value.VS._1.VInt += v294.VInt;
          continue;
        case 0x7Au:
          v301 = this->OpStack.pCurrent;
          v302 = v301->value.VS._1;
          this->OpStack.pCurrent = v301 - 1;
          v301[-1].value.VS._1.VInt -= v302.VInt;
          continue;
        case 0x7Bu:
          v309 = this->OpStack.pCurrent;
          v310 = v309->value.VS._1;
          this->OpStack.pCurrent = v309 - 1;
          v309[-1].value.VS._1.VInt *= v310.VInt;
          continue;
        case 0x7Cu:
          v295 = this->OpStack.pCurrent;
          VNumber = v295->value.VNumber;
          this->OpStack.pCurrent = v295 - 1;
          v295[-1].value.VNumber = VNumber + v295[-1].value.VNumber;
          continue;
        case 0x7Du:
          v303 = this->OpStack.pCurrent;
          v304 = v303->value.VNumber;
          this->OpStack.pCurrent = v303 - 1;
          v303[-1].value.VNumber = v303[-1].value.VNumber - v304;
          continue;
        case 0x7Eu:
          v311 = this->OpStack.pCurrent;
          v312 = v311->value.VNumber;
          this->OpStack.pCurrent = v311 - 1;
          v311[-1].value.VNumber = v312 * v311[-1].value.VNumber;
          continue;
        case 0x7Fu:
          v236 = this->OpStack.pCurrent;
          v237 = v236->value.VNumber;
          this->OpStack.pCurrent = v236 - 1;
          v236[-1].value.VNumber = v236[-1].value.VNumber / v237;
          continue;
        case 0x80u:
          v_4be = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_coerce(this, file, v_4be);
          goto LABEL_184;
        case 0x85u:
          v213 = this->OpStack.pCurrent;
          if ( (v213->Flags & 0x1F) != 0 && ((v213->Flags & 0x1F) - 12 > 3 || v213->value.VS._1.VInt) )
            Scaleform::GFx::AS3::Value::ToStringValue(
              v213,
              &v393,
              (Scaleform::GFx::ASStringNode *)this->StringManagerRef);
          else
            Scaleform::GFx::AS3::Value::SetNull(v213);
          goto LABEL_184;
        case 0x86u:
          v_4bf = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_astype(this, file, v_4bf);
          goto LABEL_184;
        case 0x87u:
          Scaleform::GFx::AS3::VM::exec_astypelate(this);
          goto LABEL_184;
        case 0x8Au:
          v25 = this->OpStack.pCurrent;
          position = *CP;
          v26 = v25 - 1;
          this->OpStack.pCurrent = v25 - 1;
          v27 = v25->value.VS._1;
          this->OpStack.pCurrent = v26 - 1;
          v28 = CP + 1;
          v29 = 0;
          if ( v26->value.VS._1.VInt >= v27.VInt )
            v29 = position;
          goto LABEL_48;
        case 0x8Bu:
          position = *CP;
          v38 = this->OpStack.pCurrent;
          v39 = v38 - 1;
          this->OpStack.pCurrent = v38 - 1;
          v40 = v38->value.VS._1;
          this->OpStack.pCurrent = v39 - 1;
          v28 = CP + 1;
          v29 = 0;
          if ( v39->value.VS._1.VInt <= v40.VInt )
            goto LABEL_48;
          CP = &v28[position];
          continue;
        case 0x8Cu:
          position = *CP;
          v47 = this->OpStack.pCurrent;
          v48 = v47 - 1;
          this->OpStack.pCurrent = v47 - 1;
          v49 = v47->value.VS._1;
          this->OpStack.pCurrent = v48 - 1;
          v28 = CP + 1;
          v29 = 0;
          if ( v48->value.VS._1.VInt > v49.VInt )
            goto LABEL_48;
          CP = &v28[position];
          continue;
        case 0x8Du:
          position = *CP;
          v55 = this->OpStack.pCurrent;
          v56 = v55 - 1;
          this->OpStack.pCurrent = v55 - 1;
          v57 = v55->value.VS._1;
          this->OpStack.pCurrent = v56 - 1;
          v28 = CP + 1;
          v29 = 0;
          if ( v56->value.VS._1.VInt >= v57.VInt )
            goto LABEL_48;
          CP = &v28[position];
          continue;
        case 0x8Eu:
          position = *CP;
          v79 = this->OpStack.pCurrent;
          v80 = v79 - 1;
          this->OpStack.pCurrent = v79 - 1;
          v81 = v79->value.VS._1;
          this->OpStack.pCurrent = v80 - 1;
          v28 = CP + 1;
          v29 = 0;
          if ( v80->value.VS._1.VInt != v81.VInt )
            goto LABEL_48;
          CP = &v28[position];
          continue;
        case 0x8Fu:
          case_count = *CP;
          v111 = this->OpStack.pCurrent;
          v112 = v111 - 1;
          this->OpStack.pCurrent = v111 - 1;
          v113 = v111->value.VS._1;
          this->OpStack.pCurrent = v112 - 1;
          v98 = CP + 1;
          v99 = 0;
          if ( v112->value.VS._1.VInt < v113.VInt )
            goto LABEL_123;
          CP = &v98[case_count];
          continue;
        case 0x90u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v427)->Result )
            *(double *)(LODWORD(default_offset) + 8) = -*(double *)(LODWORD(default_offset) + 8);
          goto LABEL_184;
        case 0x91u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v395)->Result )
            *(double *)(LODWORD(default_offset) + 8) = *(double *)(LODWORD(default_offset) + 8) + 1.0;
          goto LABEL_184;
        case 0x92u:
          v214 = &this->RegisterFile.pRF[*CP++];
          LODWORD(default_offset) = v214;
          if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v214, &v429, &v490)->Result )
            Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), v490 + 1.0);
          goto LABEL_184;
        case 0x93u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v397)->Result )
            *(double *)(LODWORD(default_offset) + 8) = *(double *)(LODWORD(default_offset) + 8) - 1.0;
          goto LABEL_184;
        case 0x94u:
          v215 = &this->RegisterFile.pRF[*CP++];
          LODWORD(default_offset) = v215;
          if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v215, &v431, &v489)->Result )
            Scaleform::GFx::AS3::Value::SetNumber((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), v489 - 1.0);
          goto LABEL_184;
        case 0x95u:
          Scaleform::GFx::AS3::VM::exec_typeof(this);
          continue;
        case 0x96u:
          position = (int)this->OpStack.pCurrent;
          v216 = Scaleform::GFx::AS3::Value::Convert2Boolean((Scaleform::GFx::AS3::Value *)position);
          Scaleform::GFx::AS3::Value::SetBool((Scaleform::GFx::AS3::Value *)position, v216);
          *(_BYTE *)(position + 8) = *(_BYTE *)(position + 8) == 0;
          continue;
        case 0x97u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::Convert2Int32(
                 (Scaleform::GFx::AS3::Value *)LODWORD(default_offset),
                 &v399,
                 (Scaleform::GFx::AS3::Value::V1U *)&v453)->Result )
            Scaleform::GFx::AS3::Value::SetSInt32((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), ~v453);
          goto LABEL_194;
        case 0x9Bu:
          v217 = this->OpStack.pCurrent;
          v376 |= 1u;
          LODWORD(default_offset) = v217;
          v218 = Scaleform::GFx::AS3::Value::ToNumberValue(v217, &v433)->Result;
          if ( (v376 & 1) != 0 )
            v376 &= ~1u;
          if ( v218 )
            v219 = (double *)(LODWORD(default_offset) + 8);
          else
            v219 = (double *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
          v220 = *v219;
          v221 = this->OpStack.pCurrent - 1;
          v492 = v220;
          position = (int)v221;
          if ( !v218
            || (v376 |= 2u,
                v188 = !Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)position, &v401)->Result,
                v491 = 1,
                v188) )
          {
            v491 = 0;
          }
          if ( (v376 & 2) != 0 )
            v376 &= ~2u;
          if ( v491 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v491 )
            *(double *)position = v492 + *(double *)position;
          goto LABEL_194;
        case 0x9Cu:
          case_count = *CP;
          v107 = this->OpStack.pCurrent;
          v108 = v107 - 1;
          this->OpStack.pCurrent = v107 - 1;
          v109 = v107->value.VS._1;
          this->OpStack.pCurrent = v108 - 1;
          v98 = CP + 1;
          v99 = 0;
          if ( v108->value.VS._1.VInt <= v109.VInt )
            goto LABEL_123;
          CP = &v98[case_count];
          continue;
        case 0x9Du:
          case_count = *CP;
          v102 = this->OpStack.pCurrent;
          v103 = v102 - 1;
          this->OpStack.pCurrent = v102 - 1;
          v104 = v102->value.VS._1;
          this->OpStack.pCurrent = v103 - 1;
          v98 = CP + 1;
          v99 = 0;
          if ( v103->value.VS._1.VInt > v104.VInt )
            goto LABEL_123;
          CP = &v98[case_count];
          continue;
        case 0x9Eu:
          case_count = *CP;
          v95 = this->OpStack.pCurrent;
          v96 = v95 - 1;
          this->OpStack.pCurrent = v95 - 1;
          v97 = v95->value.VS._1;
          this->OpStack.pCurrent = v96 - 1;
          v98 = CP + 1;
          v99 = 0;
          if ( v96->value.VS._1.VInt < v97.VInt )
            v99 = case_count;
LABEL_123:
          CP = &v98[v99];
          continue;
        case 0x9Fu:
          position = *CP;
          v87 = this->OpStack.pCurrent;
          v88 = v87 - 1;
          this->OpStack.pCurrent = v87 - 1;
          v89 = v87->value.VS._1;
          this->OpStack.pCurrent = v88 - 1;
          v28 = CP + 1;
          v29 = 0;
          if ( v88->value.VS._1.VInt == v89.VInt )
LABEL_48:
            CP = &v28[v29];
          else
            CP = &v28[position];
          continue;
        case 0xA0u:
          v222 = this->OpStack.pCurrent;
          r._2.Flags = v222->Flags;
          r._2.Bonus.pWeakProxy = v222->Bonus.pWeakProxy;
          r._2.value.VS._1.VInt = v222->value.VS._1.VInt;
          v223.VObj = (Scaleform::GFx::AS3::Object *)v222->value.VS._2;
          this->OpStack.pCurrent = v222 - 1;
          r._1 = v222 - 1;
          StringManagerRef = this->StringManagerRef;
          r._2.value.VS._2 = v223;
          Scaleform::GFx::AS3::Add(&v435, StringManagerRef, r._1, r._1, &r._2);
          Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
          goto LABEL_194;
        case 0xA1u:
          v225 = this->OpStack.pCurrent;
          v376 |= 4u;
          default_offset = 0.0;
          r._2.Flags = v225->Flags;
          r._2.Bonus.pWeakProxy = v225->Bonus.pWeakProxy;
          r._2.value.VNumber = v225->value.VNumber;
          this->OpStack.pCurrent = v225 - 1;
          r._1 = v225 - 1;
          v226 = 0;
          if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v225 - 1, &v403, &v486)->Result )
          {
            v376 |= 8u;
            if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(&r._2, &v437, &default_offset)->Result )
              v226 = 1;
          }
          v227 = v376;
          if ( (v376 & 8) != 0 )
          {
            v227 = v376 & 0xFFFFFFF7;
            v376 &= ~8u;
          }
          if ( (v227 & 4) != 0 )
            v376 = v227 & 0xFFFFFFFB;
          if ( v226 )
            Scaleform::GFx::AS3::Value::SetNumber(r._1, v486 - default_offset);
          goto LABEL_342;
        case 0xA2u:
          v228 = this->OpStack.pCurrent;
          v376 |= 0x10u;
          default_offset = 0.0;
          r._2.Flags = v228->Flags;
          r._2.Bonus.pWeakProxy = v228->Bonus.pWeakProxy;
          r._2.value.VNumber = v228->value.VNumber;
          this->OpStack.pCurrent = v228 - 1;
          r._1 = v228 - 1;
          v229 = 0;
          if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(v228 - 1, &v405, &v493)->Result )
          {
            v376 |= 0x20u;
            if ( Scaleform::GFx::AS3::Value::Convert2NumberInline(&r._2, &v439, &default_offset)->Result )
              v229 = 1;
          }
          v230 = v376;
          if ( (v376 & 0x20) != 0 )
          {
            v230 = v376 & 0xFFFFFFDF;
            v376 &= ~0x20u;
          }
          if ( (v230 & 0x10) != 0 )
            v376 = v230 & 0xFFFFFFEF;
          if ( v229 )
            Scaleform::GFx::AS3::Value::SetNumber(r._1, v493 * default_offset);
          goto LABEL_353;
        case 0xA3u:
          v231 = this->OpStack.pCurrent;
          v376 |= 0x40u;
          LODWORD(default_offset) = v231;
          v232 = Scaleform::GFx::AS3::Value::ToNumberValue(v231, &v441)->Result;
          if ( (v376 & 0x40) != 0 )
            v376 &= ~0x40u;
          if ( v232 )
            v233 = (double *)(LODWORD(default_offset) + 8);
          else
            v233 = (double *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
          v234 = *v233;
          v235 = this->OpStack.pCurrent - 1;
          v495 = v234;
          position = (int)v235;
          if ( !v232
            || (v376 |= 0x80u,
                v188 = !Scaleform::GFx::AS3::Value::ToNumberValue((Scaleform::GFx::AS3::Value *)position, &v408)->Result,
                v494 = 1,
                v188) )
          {
            v494 = 0;
          }
          if ( (v376 & 0x80u) != 0 )
            v376 &= ~0x80u;
          if ( v494 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v494 )
            *(double *)position = *(double *)position / v495;
          goto LABEL_194;
        case 0xA4u:
          v238 = this->OpStack.pCurrent;
          v376 |= 0x100u;
          LODWORD(default_offset) = v238;
          v239 = Scaleform::GFx::AS3::Value::ToNumberValue(v238, &v428)->Result;
          if ( (v376 & 0x100) != 0 )
            v376 &= ~0x100u;
          if ( v239 )
            v240 = (double *)(LODWORD(default_offset) + 8);
          else
            v240 = (double *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
          v241 = *v240;
          v242 = this->OpStack.pCurrent - 1;
          v488 = v241;
          position = (int)v242;
          if ( !v239
            || (v376 |= 0x200u, v188 = !Scaleform::GFx::AS3::Value::ToNumberValue(v242, &v410)->Result, v487 = 1, v188) )
          {
            v487 = 0;
          }
          if ( (v376 & 0x200) != 0 )
            v376 &= ~0x200u;
          if ( v487 )
            curr_cp = (const unsigned int *)(position + 8);
          else
            curr_cp = (const unsigned int *)&`Scaleform::GFx::AS3::ToType<double>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v487 )
            *(long double *)curr_cp = fmod(*(double *)curr_cp, v488);
          goto LABEL_194;
        case 0xA5u:
          v243 = this->OpStack.pCurrent;
          v376 |= 0x400u;
          LODWORD(default_offset) = v243;
          v244 = Scaleform::GFx::AS3::Value::ToUInt32Value(v243, &v438)->Result;
          if ( (v376 & 0x400) != 0 )
            v376 &= ~0x400u;
          if ( v244 )
            v245 = (int *)(LODWORD(default_offset) + 8);
          else
            v245 = (int *)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
          v450 = *v245;
          v246 = this->OpStack.pCurrent - 1;
          position = (int)v246;
          if ( !v244
            || (v376 |= 0x800u, v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v246, &v412)->Result, v449 = 1, v188) )
          {
            v449 = 0;
          }
          if ( (v376 & 0x800) != 0 )
            v376 &= ~0x800u;
          if ( v449 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v449 )
            *(_DWORD *)position <<= v450 & 0x1F;
          goto LABEL_184;
        case 0xA6u:
          v247 = this->OpStack.pCurrent;
          v376 |= 0x1000u;
          LODWORD(default_offset) = v247;
          v248 = Scaleform::GFx::AS3::Value::ToUInt32Value(v247, &v430)->Result;
          if ( (v376 & 0x1000) != 0 )
            v376 &= ~0x1000u;
          if ( v248 )
            v249 = (int *)(LODWORD(default_offset) + 8);
          else
            v249 = (int *)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
          v452 = *v249;
          v250 = this->OpStack.pCurrent - 1;
          position = (int)v250;
          if ( !v248
            || (v376 |= 0x2000u, v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v250, &v414)->Result, v451 = 1, v188) )
          {
            v451 = 0;
          }
          if ( (v376 & 0x2000) != 0 )
            v376 &= ~0x2000u;
          if ( v451 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v451 )
            *(int *)position >>= v452 & 0x1F;
          goto LABEL_184;
        case 0xA7u:
          v251 = this->OpStack.pCurrent;
          v376 |= 0x4000u;
          LODWORD(default_offset) = v251;
          v252 = Scaleform::GFx::AS3::Value::ToUInt32Value(v251, &v446)->Result;
          if ( (v376 & 0x4000) != 0 )
            v376 &= ~0x4000u;
          if ( v252 )
            v253 = (int *)(LODWORD(default_offset) + 8);
          else
            v253 = (int *)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
          v455 = *v253;
          v254 = this->OpStack.pCurrent - 1;
          position = (int)v254;
          if ( !v252
            || (v376 |= 0x8000u, v188 = !Scaleform::GFx::AS3::Value::ToUInt32Value(v254, &v416)->Result, v454 = 1, v188) )
          {
            v454 = 0;
          }
          if ( (v376 & 0x8000) != 0 )
            v376 &= ~0x8000u;
          if ( v454 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<unsigned long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v454 )
            *(_DWORD *)position >>= v455 & 0x1F;
          goto LABEL_184;
        case 0xA8u:
          v255 = this->OpStack.pCurrent;
          v376 |= (unsigned int)&_sbh_sizeHeaderList;
          LODWORD(default_offset) = v255;
          v256 = Scaleform::GFx::AS3::Value::ToInt32Value(v255, &v432)->Result;
          if ( ((unsigned int)&_sbh_sizeHeaderList & v376) != 0 )
            v376 &= ~0x10000u;
          if ( v256 )
            v257 = (int *)(LODWORD(default_offset) + 8);
          else
            v257 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          v458 = *v257;
          v258 = this->OpStack.pCurrent - 1;
          position = (int)v258;
          if ( !v256
            || (v376 |= (unsigned int)&loc_20000,
                v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v258, &v418)->Result,
                v457 = 1,
                v188) )
          {
            v457 = 0;
          }
          if ( ((unsigned int)&loc_20000 & v376) != 0 )
            v376 &= ~0x20000u;
          if ( v457 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v457 )
            *(_DWORD *)position &= v458;
          goto LABEL_194;
        case 0xA9u:
          v259 = this->OpStack.pCurrent;
          v376 |= 0x40000u;
          LODWORD(default_offset) = v259;
          v260 = Scaleform::GFx::AS3::Value::ToInt32Value(v259, &v440)->Result;
          if ( (v376 & 0x40000) != 0 )
            v376 &= ~0x40000u;
          if ( v260 )
            v261 = (int *)(LODWORD(default_offset) + 8);
          else
            v261 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          v460 = *v261;
          v262 = this->OpStack.pCurrent - 1;
          position = (int)v262;
          if ( !v260
            || (v376 |= 0x80000u, v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v262, &v420)->Result, v459 = 1, v188) )
          {
            v459 = 0;
          }
          if ( (v376 & 0x80000) != 0 )
            v376 &= ~0x80000u;
          if ( v459 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v459 )
            *(_DWORD *)position |= v460;
          goto LABEL_194;
        case 0xAAu:
          v263 = this->OpStack.pCurrent;
          v376 |= (unsigned int)&loc_100000;
          LODWORD(default_offset) = v263;
          v264 = Scaleform::GFx::AS3::Value::ToInt32Value(v263, &v434)->Result;
          if ( ((unsigned int)&loc_100000 & v376) != 0 )
            v376 &= ~0x100000u;
          if ( v264 )
            v265 = (int *)(LODWORD(default_offset) + 8);
          else
            v265 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          v462 = *v265;
          v266 = this->OpStack.pCurrent - 1;
          position = (int)v266;
          if ( !v264
            || (v376 |= (unsigned int)&loc_200000,
                v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v266, &v422)->Result,
                v461 = 1,
                v188) )
          {
            v461 = 0;
          }
          if ( ((unsigned int)&loc_200000 & v376) != 0 )
            v376 &= ~0x200000u;
          if ( v461 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v461 )
            *(_DWORD *)position ^= v462;
          goto LABEL_194;
        case 0xABu:
          v267 = this->OpStack.pCurrent;
          r._2.Flags = v267->Flags;
          r._2.Bonus.pWeakProxy = v267->Bonus.pWeakProxy;
          r._2.value.VS._1.VInt = v267->value.VS._1.VInt;
          v268.VObj = (Scaleform::GFx::AS3::Object *)v267->value.VS._2;
          this->OpStack.pCurrent = v267 - 1;
          r._1 = v267 - 1;
          r._2.value.VS._2 = v268;
          if ( !Scaleform::GFx::AS3::AbstractEqual(&v444, v466, v267 - 1, &r._2)->Result )
            goto LABEL_342;
          v269 = v466[0];
          goto LABEL_477;
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
          position = 0;
          if ( !Scaleform::GFx::AS3::AbstractLessThan(
                  &v424,
                  (Scaleform::GFx::AS3::Boolean3 *)&position,
                  v272 - 1,
                  &r._2)->Result )
            goto LABEL_342;
          v269 = position == 1;
          goto LABEL_477;
        case 0xAEu:
          v273 = this->OpStack.pCurrent;
          r._2.Flags = v273->Flags;
          r._2.Bonus.pWeakProxy = v273->Bonus.pWeakProxy;
          r._2.value.VS._1.VInt = v273->value.VS._1.VInt;
          v274.VObj = (Scaleform::GFx::AS3::Object *)v273->value.VS._2;
          this->OpStack.pCurrent = v273 - 1;
          r._1 = v273 - 1;
          r._2.value.VS._2 = v274;
          position = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v436, (Scaleform::GFx::AS3::Boolean3 *)&position, &r._2, v273 - 1)->Result )
            Scaleform::GFx::AS3::Value::SetBool(r._1, position == 2);
LABEL_353:
          Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
          goto LABEL_194;
        case 0xAFu:
          v275 = this->OpStack.pCurrent;
          r._2.Flags = v275->Flags;
          r._2.Bonus.pWeakProxy = v275->Bonus.pWeakProxy;
          r._2.value.VS._1.VInt = v275->value.VS._1.VInt;
          v276.VObj = (Scaleform::GFx::AS3::Object *)v275->value.VS._2;
          this->OpStack.pCurrent = v275 - 1;
          r._1 = v275 - 1;
          r._2.value.VS._2 = v276;
          position = 0;
          if ( Scaleform::GFx::AS3::AbstractLessThan(&v426, (Scaleform::GFx::AS3::Boolean3 *)&position, &r._2, v275 - 1)->Result )
            Scaleform::GFx::AS3::Value::SetBool(r._1, position == 1);
          goto LABEL_342;
        case 0xB0u:
          v277 = this->OpStack.pCurrent;
          r._2.Flags = v277->Flags;
          r._2.Bonus.pWeakProxy = v277->Bonus.pWeakProxy;
          r._2.value.VNumber = v277->value.VNumber;
          this->OpStack.pCurrent = v277 - 1;
          r._1 = v277 - 1;
          position = 0;
          if ( !Scaleform::GFx::AS3::AbstractLessThan(
                  &v406,
                  (Scaleform::GFx::AS3::Boolean3 *)&position,
                  v277 - 1,
                  &r._2)->Result )
            goto LABEL_342;
          v269 = position == 2;
LABEL_477:
          Scaleform::GFx::AS3::Value::SetBool(r._1, v269);
          goto LABEL_342;
        case 0xB1u:
          Scaleform::GFx::AS3::VM::exec_instanceof(this);
          goto LABEL_184;
        case 0xB2u:
          v_4bg = &constp->const_multiname.Data.Data[*CP++];
          Scaleform::GFx::AS3::VM::exec_istype(this, file, v_4bg);
          goto LABEL_184;
        case 0xB3u:
          v278 = this->OpStack.pCurrent;
          v279 = v278->Flags;
          r._2.Bonus.pWeakProxy = v278->Bonus.pWeakProxy;
          v280 = v278->value.VS._1;
          r._2.Flags = v279;
          r._2.value.VS._1 = v280;
          v281.VObj = (Scaleform::GFx::AS3::Object *)v278->value.VS._2;
          --v278;
          r._2.value.VS._2 = v281;
          this->OpStack.pCurrent = v278;
          r._1 = v278;
          if ( (v279 & 0x1F) == 0xD )
          {
            v_4bh = *(Scaleform::GFx::AS3::ClassTraits::fl::Object **)(r._2.value.VS._1.VInt + 20);
            v484.Flags = 1;
            v484.Bonus.pWeakProxy = 0;
            v484.value.VS._1.VBool = Scaleform::GFx::AS3::VM::IsOfType(this, r._1, v_4bh);
            Scaleform::GFx::AS3::Value::Assign(r._1, &v484);
            Scaleform::GFx::AS3::Value::~Value(&v484);
            Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
          }
          else
          {
            Scaleform::GFx::AS3::VM::Error::Error(&v447, eIsTypeMustBeClassError, this);
            Scaleform::GFx::AS3::VM::ThrowErrorInternal(
              this,
              v282,
              (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
            v283 = v447.Message.pNode;
            --v447.Message.pNode->RefCount;
            if ( v283->RefCount )
            {
LABEL_342:
              Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            }
            else
            {
              Scaleform::GFx::ASStringNode::ReleaseNode(v283);
              Scaleform::GFx::AS3::SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>::~SH2<1,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value>(&r);
            }
          }
LABEL_184:
          if ( !this->HandleException )
            continue;
          LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v13 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - LODWORD(default_offset)) >> 2, (unsigned int)v4);
          if ( v13 < 0 )
            goto LABEL_597;
          v14 = LODWORD(default_offset);
          goto LABEL_20;
        case 0xB4u:
          Scaleform::GFx::AS3::VM::exec_in(this);
          goto LABEL_184;
        case 0xB5u:
          v_4bi = *CP++;
          AbsObject = Scaleform::GFx::AS3::GetAbsObject(&v496, v_4bi);
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v285 = this->OpStack.pCurrent;
          if ( v188 )
            goto LABEL_501;
          v285->Flags = AbsObject->Flags;
          v285->Bonus.pWeakProxy = AbsObject->Bonus.pWeakProxy;
          v285->value.VS._1.VInt = AbsObject->value.VS._1.VInt;
          v285->value.VS._2.VObj = AbsObject->value.VS._2.VObj;
          if ( (AbsObject->Flags & 0x1F) <= 9 )
            goto LABEL_501;
          if ( (AbsObject->Flags & 0x200) != 0 )
          {
            ++AbsObject->Bonus.pWeakProxy->RefCount;
            Scaleform::GFx::AS3::Value::~Value(&v496);
          }
          else
          {
            Scaleform::GFx::AS3::Value::AddRefInternal(AbsObject);
LABEL_501:
            Scaleform::GFx::AS3::Value::~Value(&v496);
          }
          continue;
        case 0xB6u:
          v_4bj = *CP++;
          Scaleform::GFx::AS3::VM::exec_getabsslot(this, v_4bj);
          goto LABEL_184;
        case 0xB7u:
          v_4bk = *CP++;
          Scaleform::GFx::AS3::VM::exec_setabsslot(this, v_4bk);
          goto LABEL_184;
        case 0xB8u:
          v_4bl = *CP++;
          Scaleform::GFx::AS3::VM::exec_initabsslot(this, v_4bl);
          goto LABEL_184;
        case 0xB9u:
          v176 = *CP;
          v177 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callsupermethod(this, v4->OriginationTraits, v176, v177);
          goto LABEL_232;
        case 0xBAu:
          v178 = *CP;
          v179 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callgetter(this, v178, v179);
LABEL_240:
          if ( !this->HandleException )
            goto LABEL_243;
          LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v192 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - LODWORD(default_offset)) >> 2, (unsigned int)v4);
          if ( v192 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(LODWORD(default_offset) + 4 * v192);
LABEL_243:
          v188 = call_stack_size == this->CallStack.Size;
          goto LABEL_237;
        case 0xBBu:
          v180 = *CP;
          v181 = CP[1];
          CP += 2;
          Scaleform::GFx::AS3::VM::exec_callsupergetter(this, v4->OriginationTraits, v180, v181);
LABEL_232:
          if ( !this->HandleException )
            goto LABEL_236;
          LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v114 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - LODWORD(default_offset)) >> 2, (unsigned int)v4);
          if ( v114 < 0 )
            goto LABEL_597;
          v115 = LODWORD(default_offset);
          goto LABEL_235;
        case 0xBCu:
        case 0xC9u:
          v41 = this->OpStack.pCurrent;
          v42 = v41->value.VNumber;
          v43 = *CP;
          v44 = v41[-1].value.VNumber;
          this->OpStack.pCurrent = v41 - 2;
          v34 = CP + 1;
          v35 = 0;
          if ( v44 <= v42 )
            goto LABEL_51;
          CP = &v34[v43];
          continue;
        case 0xBDu:
        case 0xCAu:
          v50 = this->OpStack.pCurrent;
          v51 = v50->value.VNumber;
          v52 = *CP;
          v53 = v50[-1].value.VNumber;
          this->OpStack.pCurrent = v50 - 2;
          v34 = CP + 1;
          v35 = 0;
          if ( v53 > v51 )
            goto LABEL_51;
          CP = &v34[v52];
          continue;
        case 0xBEu:
        case 0xCBu:
          v58 = this->OpStack.pCurrent;
          v59 = v58->value.VNumber;
          v60 = *CP;
          v61 = v58[-1].value.VNumber;
          this->OpStack.pCurrent = v58 - 2;
          v34 = CP + 1;
          v35 = 0;
          if ( v61 >= v59 )
            goto LABEL_51;
          CP = &v34[v60];
          continue;
        case 0xBFu:
          v90 = this->OpStack.pCurrent;
          v91 = v90->value.VNumber;
          v92 = *CP;
          v93 = v90[-1].value.VNumber;
          this->OpStack.pCurrent = v90 - 2;
          v34 = CP + 1;
          v35 = 0;
          if ( v93 == v91 )
            goto LABEL_51;
          CP = &v34[v92];
          continue;
        case 0xC0u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::ToInt32Value((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v407)->Result )
            ++*(_DWORD *)(LODWORD(default_offset) + 8);
          goto LABEL_184;
        case 0xC1u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::ToInt32Value((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v387)->Result )
            --*(_DWORD *)(LODWORD(default_offset) + 8);
          goto LABEL_184;
        case 0xC2u:
          v286 = &this->RegisterFile.pRF[*CP++];
          LODWORD(default_offset) = v286;
          if ( Scaleform::GFx::AS3::Value::ToInt32Value(v286, &v411)->Result )
            ++*(_DWORD *)(LODWORD(default_offset) + 8);
          goto LABEL_194;
        case 0xC3u:
          v288 = &this->RegisterFile.pRF[*CP++];
          LODWORD(default_offset) = v288;
          if ( Scaleform::GFx::AS3::Value::ToInt32Value(v288, &v413)->Result )
            --*(_DWORD *)(LODWORD(default_offset) + 8);
          goto LABEL_194;
        case 0xC4u:
          LODWORD(default_offset) = this->OpStack.pCurrent;
          if ( Scaleform::GFx::AS3::Value::ToInt32Value((Scaleform::GFx::AS3::Value *)LODWORD(default_offset), &v415)->Result )
            *(_DWORD *)(LODWORD(default_offset) + 8) = -*(_DWORD *)(LODWORD(default_offset) + 8);
          goto LABEL_194;
        case 0xC5u:
          v289 = this->OpStack.pCurrent;
          v376 |= (unsigned int)&loc_400000;
          LODWORD(default_offset) = v289;
          v290 = Scaleform::GFx::AS3::Value::ToInt32Value(v289, &v417)->Result;
          if ( ((unsigned int)&loc_400000 & v376) != 0 )
            v376 &= ~0x400000u;
          if ( v290 )
            v291 = (int *)(LODWORD(default_offset) + 8);
          else
            v291 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          v465 = *v291;
          v292 = this->OpStack.pCurrent - 1;
          position = (int)v292;
          if ( !v290
            || (v376 |= 0x800000u, v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v292, &v419)->Result, v464 = 1, v188) )
          {
            v464 = 0;
          }
          if ( (v376 & 0x800000) != 0 )
            v376 &= ~0x800000u;
          if ( v464 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v464 )
            *(_DWORD *)position += v465;
          goto LABEL_194;
        case 0xC6u:
          v297 = this->OpStack.pCurrent;
          v376 |= 0x1000000u;
          LODWORD(default_offset) = v297;
          v298 = Scaleform::GFx::AS3::Value::ToInt32Value(v297, &v421)->Result;
          if ( (v376 & 0x1000000) != 0 )
            v376 &= ~0x1000000u;
          if ( v298 )
            v299 = (int *)(LODWORD(default_offset) + 8);
          else
            v299 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          v468 = *v299;
          v300 = this->OpStack.pCurrent - 1;
          position = (int)v300;
          if ( !v298
            || (v376 |= 0x2000000u, v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v300, &v388)->Result,
                                    v467 = 1,
                                    v188) )
          {
            v467 = 0;
          }
          if ( (v376 & 0x2000000) != 0 )
            v376 &= ~0x2000000u;
          if ( v467 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v467 )
            *(_DWORD *)position -= v468;
          goto LABEL_194;
        case 0xC7u:
          v305 = this->OpStack.pCurrent;
          v376 |= 0x4000000u;
          LODWORD(default_offset) = v305;
          v306 = Scaleform::GFx::AS3::Value::ToInt32Value(v305, &v390)->Result;
          if ( (v376 & 0x4000000) != 0 )
            v376 &= ~0x4000000u;
          if ( v306 )
            v307 = (int *)(LODWORD(default_offset) + 8);
          else
            v307 = (int *)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          v471 = *v307;
          v308 = this->OpStack.pCurrent - 1;
          position = (int)v308;
          if ( !v306
            || (v376 |= 0x8000000u, v188 = !Scaleform::GFx::AS3::Value::ToInt32Value(v308, &v392)->Result,
                                    v470 = 1,
                                    v188) )
          {
            v470 = 0;
          }
          if ( (v376 & 0x8000000) != 0 )
            v376 &= ~0x8000000u;
          if ( v470 )
            position += 8;
          else
            position = (int)&`Scaleform::GFx::AS3::ToType<long>'::`2'::tmp;
          Scaleform::GFx::AS3::Value::`scalar deleting destructor'(this->OpStack.pCurrent, 0);
          --this->OpStack.pCurrent;
          if ( v470 )
            *(_DWORD *)position *= v471;
LABEL_194:
          if ( !this->HandleException )
            continue;
          LODWORD(default_offset) = Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v140 = Scaleform::GFx::AS3::VM::OnException(this, ((int)CP - LODWORD(default_offset)) >> 2, (unsigned int)v4);
          if ( v140 < 0 )
            goto LABEL_597;
          CP = (const unsigned int *)(LODWORD(default_offset) + 4 * v140);
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
          v82 = this->OpStack.pCurrent;
          v83 = v82->value.VNumber;
          v84 = *CP;
          v85 = v82[-1].value.VNumber;
          this->OpStack.pCurrent = v82 - 2;
          v34 = CP + 1;
          v35 = 0;
          if ( v85 == v83 )
            CP = &v34[v84];
          else
LABEL_51:
            CP = &v34[v35];
          continue;
        case 0xCEu:
          v_4g = *CP++;
          Scaleform::GFx::AS3::VM::exec_callobject(this, v_4g);
          if ( !this->HandleException )
            goto LABEL_236;
          case_count = (unsigned int)Scaleform::GFx::AS3::VMAbcFile::GetOpCode(v4->pFile, v4->MBIIndex, v4)->Data.Data;
          v114 = Scaleform::GFx::AS3::VM::OnException(this, (int)((int)CP - case_count) >> 2, (unsigned int)v4);
          if ( v114 < 0 )
            goto LABEL_597;
          v115 = case_count;
LABEL_235:
          CP = (const unsigned int *)(v115 + 4 * v114);
LABEL_236:
          v188 = call_stack_size == this->CallStack.Size;
LABEL_237:
          if ( v188 )
            continue;
          v189 = 1;
          break;
        case 0xD0u:
          pRF = this->RegisterFile.pRF;
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v313 = this->OpStack.pCurrent;
          if ( v188 )
            continue;
          v313->Flags = pRF->Flags;
          v313->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
          v313->value.VS._1.VInt = pRF->value.VS._1.VInt;
          v313->value.VS._2.VObj = pRF->value.VS._2.VObj;
          if ( (pRF->Flags & 0x1F) <= 9 )
            continue;
          if ( (pRF->Flags & 0x200) == 0 )
            goto LABEL_263;
          ++pRF->Bonus.pWeakProxy->RefCount;
          continue;
        case 0xD1u:
          pRF = this->RegisterFile.pRF + 1;
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v314 = this->OpStack.pCurrent;
          if ( v188 )
            continue;
          v314->Flags = pRF->Flags;
          v314->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
          v314->value.VS._1.VInt = pRF->value.VS._1.VInt;
          v314->value.VS._2.VObj = pRF->value.VS._2.VObj;
          if ( (pRF->Flags & 0x1F) <= 9 )
            continue;
          if ( (pRF->Flags & 0x200) == 0 )
            goto LABEL_263;
          ++pRF->Bonus.pWeakProxy->RefCount;
          continue;
        case 0xD2u:
          pRF = this->RegisterFile.pRF + 2;
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v315 = this->OpStack.pCurrent;
          if ( v188 )
            continue;
          v315->Flags = pRF->Flags;
          v315->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
          v315->value.VS._1.VInt = pRF->value.VS._1.VInt;
          v315->value.VS._2.VObj = pRF->value.VS._2.VObj;
          if ( (pRF->Flags & 0x1F) <= 9 )
            continue;
          if ( (pRF->Flags & 0x200) == 0 )
            goto LABEL_263;
          ++pRF->Bonus.pWeakProxy->RefCount;
          continue;
        case 0xD3u:
          pRF = this->RegisterFile.pRF + 3;
          v188 = this->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-16;
          v316 = this->OpStack.pCurrent;
          if ( v188 )
            continue;
          v316->Flags = pRF->Flags;
          v316->Bonus.pWeakProxy = pRF->Bonus.pWeakProxy;
          v316->value.VS._1.VInt = pRF->value.VS._1.VInt;
          v316->value.VS._2.VObj = pRF->value.VS._2.VObj;
          if ( (pRF->Flags & 0x1F) <= 9 )
            continue;
          if ( (pRF->Flags & 0x200) == 0 )
            goto LABEL_263;
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
          v_4bm = *CP++;
          Scaleform::GFx::AS3::VM::exec_debugline(this, v4, v_4bm);
          continue;
        case 0xF1u:
          v_4bn = (Scaleform::GFx::ASStringNode *)*CP++;
          Scaleform::GFx::AS3::VM::exec_debugfile(this, v4, v_4bn);
          continue;
        case 0xF2u:
          ++CP;
          continue;
        default:
          continue;
      }
      break;
    }
call_stack_label:
    Scaleform::GFx::AS3::VM::SetActiveLine(this, 0);
    Scaleform::GFx::AS3::VM::SetActiveFile(this, 0);
    if ( v189 != 1 )
      break;
    ++max_stack_depth;
    this->CallStack.Pages[(call_stack_size - 1) >> 6][(call_stack_size - 1) & 0x3F].CP = CP;
LABEL_610:
    Scaleform::GFx::AS3::Value::~Value(&tmpExceptionValue);
    if ( !this->CallStack.Size )
      return max_stack_depth;
  }
  if ( this->GetAdvanceStats(this) )
  {
    v318 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F];
    v319 = 0;
    v479 = 0;
    Instance = Scaleform::AmpServer::GetInstance();
    if ( Instance->IsProfiling(Instance) )
    {
      v321 = Scaleform::AmpServer::GetInstance();
      if ( v321->GetProfileLevel(v321) >= Amp_Profile_Level_Medium )
      {
        StartTicks_high = HIDWORD(v318->StartTicks);
        LODWORD(v456) = v318->StartTicks;
        HIDWORD(v456) = StartTicks_high;
        v323 = Scaleform::Timer::GetProfileTicks() - v456;
        v479 = HIDWORD(v323);
        v319 = v323;
      }
    }
    v324 = &v318->pFile->File.pObject->__vftable;
    vb = __PAIR64__(v479, v319);
    v330 = v324[5];
    v329 = v324[4] + (*(_DWORD *)(*(_DWORD *)(v324[45] + 4 * v318->MBIIndex.Ind) + 12) << 16);
    v325 = this->GetAdvanceStats(this);
    Scaleform::GFx::AMP::ViewStats::PopCallstack(
      v325,
      (Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>)v329,
      v330,
      vb);
  }
  if ( this->HandleException )
  {
    v326 = &this->CallStack.Pages[(this->CallStack.Size - 1) >> 6][(this->CallStack.Size - 1) & 0x3F];
    Scaleform::GFx::AS3::ValueStack::PopReserved(&v326->pFile->VMRef->OpStack, v326->PrevInitialStackPos);
  }
  Size = this->CallStack.Size;
  if ( Size )
  {
    Scaleform::GFx::AS3::CallFrame::~CallFrame(&this->CallStack.Pages[(Size - 1) >> 6][(Size - 1) & 0x3F]);
    --this->CallStack.Size;
  }
  if ( --max_stack_depth )
    goto LABEL_610;
  Scaleform::GFx::AS3::Value::~Value(&tmpExceptionValue);
  return max_stack_depth;
}
