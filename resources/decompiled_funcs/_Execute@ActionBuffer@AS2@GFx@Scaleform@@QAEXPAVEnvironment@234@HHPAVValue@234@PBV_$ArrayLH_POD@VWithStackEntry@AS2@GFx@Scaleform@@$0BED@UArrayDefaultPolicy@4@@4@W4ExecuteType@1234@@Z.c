// local variable allocation has failed, the output may be wrong!
void __thiscall Scaleform::GFx::AS2::ActionBuffer::Execute(
        Scaleform::GFx::AS2::ActionBuffer *this,
        Scaleform::GFx::AS2::Environment *env,
        int startPc,
        int execBytes,
        Scaleform::GFx::AS2::Value *retval,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pinitialWithStack,
        Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  Scaleform::GFx::PlayState p_Stack; // edi
  Scaleform::GFx::InteractiveObject *v8; // eax
  Scaleform::GFx::AS2::ActionBufferData *pObject; // eax
  const unsigned __int8 *pBuffer; // eax
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v13; // eax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v14; // eax
  char v15; // al
  bool (__thiscall *IsVerboseActionErrors)(struct Scaleform::GFx::AS2::ActionLogger *); // eax
  bool v17; // al
  char v18; // dl
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  signed int PC; // ebx
  unsigned int Size; // eax
  unsigned int v24; // ecx
  unsigned int v25; // eax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pWithStackArray; // ebx
  unsigned int v27; // eax
  int v28; // ebx
  int v29; // eax
  int v30; // ebx
  int v31; // eax
  Scaleform::GFx::AS2::MovieRoot *v32; // ecx
  Scaleform::GFx::Sprite *LevelMovie; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::AS2::Value *pPrevPageTop; // ecx
  Scaleform::GFx::AS2::Value *v36; // eax
  Scaleform::GFx::AS2::Value *v37; // ecx
  Scaleform::GFx::AS2::Value *v38; // eax
  Scaleform::GFx::AS2::Value *v39; // ecx
  Scaleform::GFx::AS2::Value *v40; // eax
  Scaleform::GFx::AS2::Value *v41; // ecx
  Scaleform::GFx::AS2::Value *v42; // eax
  Scaleform::GFx::AS2::Value *v43; // ecx
  Scaleform::GFx::AS2::Value *v44; // ebx
  bool IsEqual; // al
  Scaleform::GFx::AS2::Value *v46; // eax
  Scaleform::GFx::AS2::Value *v47; // ecx
  Scaleform::GFx::AS2::Value *v48; // ebx
  Scaleform::GFx::AS2::Value *v49; // ecx
  Scaleform::GFx::AS2::Value *v50; // eax
  Scaleform::GFx::AS2::Value *v51; // ecx
  bool v52; // dl
  Scaleform::GFx::AS2::Value *v53; // ecx
  Scaleform::GFx::AS2::Value *v54; // eax
  Scaleform::GFx::AS2::Value *v55; // ecx
  char v56; // al
  Scaleform::GFx::AS2::Value *v57; // eax
  Scaleform::GFx::AS2::Value *v58; // ecx
  Scaleform::GFx::InteractiveObject_vtbl **v59; // ebx
  Scaleform::GFx::AS2::Value *v60; // eax
  Scaleform::GFx::ASStringNode *v61; // ebx
  Scaleform::GFx::AS2::Value *pNode; // ecx
  Scaleform::GFx::ASString *v63; // eax
  Scaleform::GFx::AS2::Value *v64; // ebx
  unsigned int Length; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v66; // edi
  unsigned int v67; // eax
  Scaleform::GFx::AS2::Value *v68; // ecx
  Scaleform::GFx::ASString *v69; // eax
  Scaleform::GFx::AS2::Value *v70; // ecx
  Scaleform::GFx::AS2::Value *v71; // ebx
  int v72; // eax
  Scaleform::GFx::ASString *v73; // eax
  Scaleform::GFx::AS2::Value *v74; // ecx
  const Scaleform::GFx::ASString *v75; // ebx
  Scaleform::GFx::ASStringNode *v76; // ecx
  unsigned int v77; // eax
  Scaleform::GFx::ASMovieRootBase *v78; // eax
  double v79; // st7
  char **v80; // eax
  double v81; // st7
  double v82; // st7
  Scaleform::GFx::AS2::Value *v83; // eax
  Scaleform::GFx::AS2::Value *v84; // ecx
  Scaleform::GFx::AS2::Value *v85; // ecx
  int v86; // ebx
  Scaleform::GFx::AS2::Value *v87; // eax
  Scaleform::GFx::AS2::Value *v88; // ecx
  const Scaleform::GFx::ASString *v89; // ebx
  Scaleform::GFx::AS2::Value *v90; // eax
  bool v91; // zf
  Scaleform::GFx::AS2::Value *v92; // eax
  Scaleform::GFx::AS2::Value *v93; // eax
  Scaleform::GFx::InteractiveObject *TargetByValue; // eax
  Scaleform::GFx::AS2::Value *v95; // eax
  long double (__thiscall **p_GetYRotation)(Scaleform::GFx::DisplayObjectBase *); // ebx
  int v97; // eax
  Scaleform::GFx::AS2::Value *v98; // ebx
  unsigned int v99; // eax
  Scaleform::GFx::AS2::Value *v100; // ecx
  Scaleform::GFx::InteractiveObject *v101; // eax
  Scaleform::GFx::InteractiveObject *v102; // eax
  Scaleform::GFx::AS2::Value *v103; // edx
  Scaleform::GFx::AS2::Value *v104; // ecx
  void (__thiscall **p_SetYRotation)(Scaleform::GFx::DisplayObjectBase *, long double); // ebx
  int v106; // eax
  unsigned int v107; // eax
  Scaleform::GFx::AS2::Value *v108; // ecx
  Scaleform::GFx::InteractiveObject *v109; // ebx
  Scaleform::GFx::AS2::Value *v110; // ecx
  int AvmObjOffset; // edx
  int v112; // eax
  Scaleform::GFx::AS2::AvmCharacter *v113; // ebx
  unsigned int v114; // eax
  Scaleform::GFx::ASStringNode *v115; // eax
  Scaleform::GFx::InteractiveObject *v116; // eax
  Scaleform::GFx::ASString *Name; // eax
  Scaleform::GFx::ASStringNode *v118; // eax
  const Scaleform::GFx::AS2::FnCall *v119; // eax
  const Scaleform::GFx::AS2::FnCall *v120; // ebx
  Scaleform::GFx::AS2::Value *v121; // eax
  Scaleform::GFx::AS2::Value *v122; // ecx
  Scaleform::GFx::ASString *v123; // eax
  Scaleform::GFx::AS2::Value *v124; // ecx
  const Scaleform::GFx::ASString *v125; // ebx
  Scaleform::GFx::InteractiveObject *v126; // eax
  bool v127; // al
  Scaleform::GFx::ASStringNode *v128; // ebx
  signed int v129; // ebx
  unsigned int NextRandom; // eax
  unsigned int v131; // eax
  unsigned __int8 v132; // al
  Scaleform::GFx::AS2::GlobalContext *v133; // edx
  Scaleform::GFx::ASStringNode *StringNode; // eax
  Scaleform::GFx::AS2::Value *v135; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  double v137; // rax
  long double v138; // st7
  unsigned int v139; // eax
  Scaleform::GFx::AS2::Value *v140; // ecx
  Scaleform::GFx::InteractiveObject *v141; // eax
  Scaleform::GFx::AS2::Value *v142; // ecx
  Scaleform::GFx::AS2::Value *v143; // ebx
  int v144; // eax
  Scaleform::GFx::ASString *v145; // eax
  Scaleform::GFx::AS2::Value *v146; // ecx
  Scaleform::GFx::ASString *v147; // ebx
  unsigned int CharAt; // eax
  unsigned __int16 v149; // ax
  Scaleform::GFx::AS2::GlobalContext *v150; // edx
  Scaleform::GFx::AS2::Value *v151; // eax
  Scaleform::GFx::AS2::Value *v152; // ebx
  Scaleform::GFx::AS2::ObjectInterface *v153; // eax
  Scaleform::GFx::AS2::Value *v154; // ecx
  Scaleform::GFx::AS2::ObjectInterface *v155; // eax
  const Scaleform::GFx::AS2::Environment::GetVarParams *v156; // eax
  Scaleform::GFx::AS2::ObjectInterface *v157; // eax
  Scaleform::GFx::AS2::Value *v158; // eax
  Scaleform::GFx::AS2::Value *v159; // ecx
  Scaleform::GFx::AS2::Value *v160; // ecx
  Scaleform::GFx::AS2::Value *v161; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v162; // ebx
  Scaleform::GFx::AS2::Object *v163; // eax
  Scaleform::GFx::AS2::Object *v164; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *v166; // ecx
  int v167; // eax
  unsigned int v168; // eax
  Scaleform::GFx::AS2::Value *v169; // ecx
  Scaleform::GFx::AS2::Value *v170; // eax
  Scaleform::GFx::PlayState v171; // eax
  Scaleform::GFx::AS2::Value *v172; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v173; // edi
  Scaleform::GFx::AS2::Value *v174; // ecx
  long double v175; // st7
  double v176; // st7
  Scaleform::GFx::AS2::Value *v177; // ecx
  long double v178; // st7
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v179; // edi
  Scaleform::GFx::AS2::Value *v180; // eax
  Scaleform::GFx::AS2::Value *v181; // ecx
  Scaleform::GFx::AS2::Object *v182; // ecx
  unsigned int v183; // eax
  Scaleform::GFx::AS2::Object *v184; // ebx
  Scaleform::GFx::AS2::Value *v185; // eax
  unsigned int v186; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v187; // edi
  long double v188; // st7
  Scaleform::GFx::AS2::Value *v189; // ecx
  bool v190; // cf
  const Scaleform::GFx::AS2::FnCall *v191; // eax
  const Scaleform::GFx::AS2::FnCall *v192; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v193; // edi
  int v194; // ebx
  Scaleform::GFx::InteractiveObject *v195; // eax
  Scaleform::GFx::AS2::Object *v196; // ecx
  unsigned int v197; // eax
  Scaleform::GFx::AS2::Value *v198; // eax
  Scaleform::GFx::AS2::Value *v199; // ecx
  Scaleform::GFx::AS2::Value *v200; // ecx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v201; // ebx
  unsigned int v202; // eax
  Scaleform::GFx::AS2::Value *v203; // ecx
  Scaleform::GFx::InteractiveObject *v204; // eax
  Scaleform::GFx::InteractiveObject *v205; // eax
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  Scaleform::GFx::AS2::Value *v207; // eax
  Scaleform::GFx::AS2::Value *v208; // eax
  Scaleform::GFx::AS2::Value *v209; // ecx
  Scaleform::GFx::AS2::Value *v210; // ebx
  bool v211; // al
  Scaleform::GFx::AS2::Value *v212; // ebx
  Scaleform::GFx::AS2::Value *v213; // eax
  Scaleform::GFx::AS2::Value *v214; // eax
  Scaleform::GFx::PlayState v215; // eax
  Scaleform::GFx::AS2::Value *v216; // ecx
  Scaleform::GFx::AS2::Value *v217; // ecx
  Scaleform::GFx::AS2::Value *v218; // edi
  Scaleform::GFx::AS2::Value *v219; // edi
  Scaleform::GFx::InteractiveObject *v220; // ebx
  Scaleform::GFx::AS2::Object *v221; // eax
  Scaleform::GFx::AS2::Object *v222; // ebx
  unsigned int v223; // eax
  Scaleform::GFx::AS2::Object *v224; // ecx
  int v225; // eax
  const Scaleform::GFx::AS2::Value *v226; // eax
  Scaleform::GFx::AS2::Value *v227; // ecx
  Scaleform::GFx::AS2::Object *v228; // eax
  Scaleform::GFx::AS2::Object *v229; // ecx
  unsigned int v230; // eax
  unsigned int v231; // eax
  Scaleform::GFx::AS2::Value *v232; // ecx
  Scaleform::GFx::AS2::Value *v233; // eax
  Scaleform::GFx::AS2::ObjectInterface *v234; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  long double v236; // st7
  Scaleform::GFx::AS2::Value *v237; // eax
  Scaleform::GFx::AS2::Value *v238; // ecx
  Scaleform::GFx::AS2::Value *v239; // eax
  Scaleform::GFx::AS2::Value *v240; // eax
  Scaleform::GFx::AS2::Value *v241; // ecx
  Scaleform::GFx::AS2::Value *v242; // ecx
  Scaleform::GFx::AS2::Value *v243; // eax
  Scaleform::GFx::AS2::Value *v244; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *Owner; // eax
  Scaleform::GFx::AS2::Object *v246; // ebx
  unsigned int v247; // eax
  Scaleform::GFx::AS2::Object *v248; // ecx
  unsigned int v249; // eax
  Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *v250; // eax
  Scaleform::GFx::InteractiveObject *v251; // ecx
  Scaleform::GFx::InteractiveObject *v252; // eax
  void (__thiscall ***v253)(_DWORD, _DWORD); // eax
  void (__thiscall ***v254)(_DWORD, _DWORD); // ebx
  int v255; // eax
  void (__thiscall *v256)(_DWORD, _DWORD, _DWORD, _DWORD); // edx
  Scaleform::GFx::AS2::Value *v257; // ecx
  Scaleform::GFx::AS2::Value *v258; // ebx
  Scaleform::GFx::AS2::Value *v259; // eax
  Scaleform::GFx::InteractiveObject *v260; // eax
  void (__thiscall ***v261)(_DWORD, _DWORD); // eax
  void (__thiscall ***v262)(_DWORD, _DWORD); // ebx
  int v263; // eax
  void (__thiscall *v264)(_DWORD, _DWORD, _DWORD, _DWORD); // edx
  Scaleform::GFx::AS2::Value *v265; // eax
  Scaleform::GFx::AS2::Object *v266; // eax
  Scaleform::GFx::AS2::ObjectInterface *v267; // ebx
  Scaleform::GFx::InteractiveObject *v268; // eax
  void (__thiscall ***v269)(_DWORD, _DWORD); // eax
  void (__thiscall ***v270)(_DWORD, _DWORD); // ebx
  int v271; // eax
  void (__thiscall *v272)(_DWORD, _DWORD, _DWORD, _DWORD); // edx
  Scaleform::GFx::AS2::Value *v273; // eax
  Scaleform::GFx::AS2::Object *v274; // ecx
  Scaleform::GFx::InteractiveObject *v275; // eax
  Scaleform::GFx::InteractiveObject *v276; // ebx
  unsigned int v277; // eax
  Scaleform::GFx::AS2::Object *v278; // eax
  Scaleform::GFx::AS2::Object *v279; // ebx
  Scaleform::GFx::InteractiveObject *v280; // eax
  Scaleform::GFx::InteractiveObject *v281; // ebx
  Scaleform::GFx::AS2::FunctionRef *v282; // eax
  void (__thiscall ***v283)(_DWORD, _DWORD); // eax
  void (__thiscall ***v284)(_DWORD, _DWORD); // ebx
  Scaleform::GFx::AS2::Object *v285; // ecx
  unsigned int v286; // eax
  Scaleform::GFx::AS2::ObjectInterface_vtbl *v287; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v288; // edi
  Scaleform::GFx::AS2::Value *v289; // eax
  Scaleform::GFx::AS2::Value *v290; // ebx
  Scaleform::GFx::AS2::Value *v291; // eax
  Scaleform::GFx::AS2::Value *v292; // eax
  Scaleform::GFx::AS2::Value *v293; // eax
  Scaleform::GFx::AS2::Value *v294; // eax
  Scaleform::GFx::AS2::ObjectInterface *v295; // eax
  Scaleform::GFx::AS2::FunctionRef *v296; // ebx
  Scaleform::GFx::InteractiveObject *v297; // eax
  Scaleform::GFx::AS2::FunctionRef *v298; // ebx
  unsigned int v299; // eax
  Scaleform::GFx::AS2::Object *v300; // ecx
  Scaleform::GFx::AS2::Object *v301; // ebx
  Scaleform::GFx::AS2::Object *v302; // ecx
  unsigned int v303; // eax
  unsigned int v304; // eax
  Scaleform::GFx::AS2::Value *v305; // eax
  Scaleform::GFx::AS2::Value *v306; // ecx
  Scaleform::GFx::AS2::Value *v307; // eax
  Scaleform::GFx::AS2::Value *v308; // ecx
  Scaleform::GFx::AS2::Value *v309; // eax
  Scaleform::GFx::AS2::Value *v310; // ecx
  Scaleform::GFx::AS2::Value *v311; // eax
  Scaleform::GFx::AS2::Value *v312; // ecx
  Scaleform::GFx::AS2::Value *v313; // eax
  Scaleform::GFx::AS2::Value *v314; // ecx
  Scaleform::GFx::AS2::Value *v315; // eax
  Scaleform::GFx::AS2::Value *v316; // ecx
  Scaleform::GFx::AS2::Value *v317; // eax
  Scaleform::GFx::AS2::Value *v318; // ecx
  Scaleform::GFx::AS2::Value *v319; // eax
  Scaleform::GFx::AS2::Value *v320; // ecx
  Scaleform::GFx::AS2::Value *v321; // eax
  Scaleform::GFx::AS2::Value *v322; // ecx
  Scaleform::GFx::AS2::Value *v323; // ebx
  Scaleform::GFx::AS2::Value *v324; // eax
  Scaleform::GFx::AS2::Value *v325; // eax
  Scaleform::GFx::AS2::Value *v326; // ecx
  Scaleform::GFx::ASString *v327; // ebx
  Scaleform::GFx::AS2::Value *v328; // eax
  bool v329; // al
  Scaleform::GFx::InteractiveObject *v330; // ecx
  char *v331; // ebx
  Scaleform::GFx::FSCommandHandler *v332; // ecx
  unsigned int v333; // eax
  Scaleform::GFx::AS2::Value *v334; // eax
  Scaleform::GFx::InteractiveObject *v335; // eax
  Scaleform::GFx::Sprite *v336; // ecx
  int v337; // eax
  unsigned int v338; // ecx
  Scaleform::GFx::AS2::Value *v339; // ecx
  int v340; // edi
  Scaleform::GFx::InteractiveObject *v341; // eax
  const Scaleform::GFx::AS2::WithStackEntry *v342; // eax
  Scaleform::GFx::AS2::Object *v343; // eax
  const Scaleform::GFx::AS2::WithStackEntry *v344; // eax
  int v345; // eax
  unsigned int v346; // eax
  Scaleform::GFx::AS2::Value *v347; // eax
  Scaleform::GFx::AS2::Value *v348; // eax
  Scaleform::GFx::AS2::Value *v349; // ecx
  unsigned int v350; // eax
  Scaleform::GFx::ASString *Data; // ecx
  Scaleform::GFx::ASString *v352; // edx
  Scaleform::GFx::AS2::Value *v353; // eax
  int *v354; // eax
  int v355; // eax
  Scaleform::GFx::AS2::Value *v356; // eax
  int v357; // eax
  Scaleform::GFx::ASStringNode *v358; // eax
  int v359; // edx
  Scaleform::GFx::AS2::Value *v360; // eax
  double v361; // st7
  Scaleform::GFx::AS2::Value *v362; // ecx
  bool v363; // cl
  double v364; // rax
  double v365; // st7
  int v366; // edi
  int v367; // ecx
  int v368; // edx
  int v369; // eax
  Scaleform::GFx::AS2::Value *v370; // eax
  unsigned int v371; // eax
  Scaleform::GFx::ASString *v372; // edx
  int *v373; // ecx
  int v374; // eax
  Scaleform::GFx::AS2::Value *v375; // eax
  Scaleform::GFx::AS2::ActionBufferData *v376; // edx
  Scaleform::GFx::AS2::Object *v377; // ecx
  unsigned int v378; // eax
  Scaleform::GFx::AS2::Value *v379; // eax
  Scaleform::GFx::FSCommandHandler *v380; // ecx
  Scaleform::GFx::InteractiveObject *v381; // ecx
  unsigned int v382; // eax
  Scaleform::GFx::AS2::Value *v383; // ecx
  Scaleform::GFx::ASStringNode *v384; // eax
  __int16 v385; // bx
  char v386; // al
  Scaleform::GFx::AS2::Value *v387; // ecx
  unsigned __int8 v388; // al
  Scaleform::GFx::ASStringNode *v389; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v390; // ebx
  unsigned int v391; // eax
  const unsigned __int8 *pTryBlock; // eax
  int v393; // ebx
  int v394; // ecx
  unsigned int v395; // edx
  Scaleform::GFx::InteractiveObject *pOriginalTarget; // ecx
  unsigned __int8 Version; // al
  Scaleform::GFx::AS2::Object *v398; // ecx
  unsigned int v399; // eax
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v400; // esi
  Scaleform::GFx::ASStringNode *v401; // [esp-4h] [ebp-18Ch]
  Scaleform::GFx::AS2::Value *val; // [esp+0h] [ebp-188h]
  Scaleform::GFx::AS2::Value *vala; // [esp+0h] [ebp-188h]
  Scaleform::GFx::AS2::Value *valb; // [esp+0h] [ebp-188h]
  Scaleform::GFx::AS2::Value *valc; // [esp+0h] [ebp-188h]
  Scaleform::GFx::AS2::Value *vald; // [esp+0h] [ebp-188h]
  int val_4; // [esp+4h] [ebp-184h]
  int val_4a; // [esp+4h] [ebp-184h]
  bool val_4b; // [esp+4h] [ebp-184h]
  int val_4c; // [esp+4h] [ebp-184h]
  Scaleform::GFx::AS2::Value *val_4d; // [esp+4h] [ebp-184h]
  int v412; // [esp+8h] [ebp-180h]
  Scaleform::GFx::AS2::ASStringContext *v413; // [esp+Ch] [ebp-17Ch]
  char tmpStr1Buf[4]; // [esp+34h] [ebp-154h] BYREF
  Scaleform::GFx::InteractiveObject *target; // [esp+38h] [ebp-150h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> pobj; // [esp+3Ch] [ebp-14Ch]
  bool test; // [esp+43h] [ebp-145h] BYREF
  int nargs; // [esp+44h] [ebp-144h]
  int sceneOffset; // [esp+48h] [ebp-140h] BYREF
  int tryCount; // [esp+4Ch] [ebp-13Ch] BYREF
  Scaleform::GFx::AS2::ActionBuffer *pactBuf; // [esp+50h] [ebp-138h]
  Scaleform::GFx::AS2::Value *object; // [esp+54h] [ebp-134h]
  char valBuf1[16]; // [esp+58h] [ebp-130h] BYREF
  Scaleform::GFx::AS2::ExecutionContext execContext; // [esp+68h] [ebp-120h] BYREF
  long double u; // [esp+A0h] [ebp-E8h] OVERLAPPED
  char tmpStr2Buf[4]; // [esp+ACh] [ebp-DCh] BYREF
  long double nargsf; // [esp+B0h] [ebp-D8h] BYREF
  char v428; // [esp+BDh] [ebp-CBh] BYREF
  bool isOriginalTargetValid; // [esp+BEh] [ebp-CAh]
  char v430; // [esp+BFh] [ebp-C9h] BYREF
  int tc; // [esp+C0h] [ebp-C8h] BYREF
  char valBuf2[16]; // [esp+C4h] [ebp-C4h] BYREF
  char valBuf3[16]; // [esp+D4h] [ebp-B4h] BYREF
  bool retVal; // [esp+E4h] [ebp-A4h]
  char funcBuf[12]; // [esp+E8h] [ebp-A0h] BYREF
  Scaleform::GFx::AS2::Environment::TryDescr tryDescr; // [esp+F4h] [ebp-94h] BYREF
  bool caseSensitive[4]; // [esp+100h] [ebp-88h]
  Scaleform::GFx::ASString result; // [esp+104h] [ebp-84h] BYREF
  __int64 v439; // [esp+108h] [ebp-80h]
  unsigned __int64 v440; // [esp+110h] [ebp-78h]
  double v441; // [esp+118h] [ebp-70h]
  Scaleform::GFx::AS2::WithStackEntry v442; // [esp+124h] [ebp-64h] BYREF
  Scaleform::GFx::AS2::WithStackEntry v443; // [esp+12Ch] [ebp-5Ch] BYREF
  char fnCallBuf[36]; // [esp+134h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::ValueGuard valStorage; // [esp+158h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams v446; // [esp+170h] [ebp-18h] BYREF
  int savedregs; // [esp+188h] [ebp+0h] BYREF

  p_Stack = (Scaleform::GFx::PlayState)this;
  pactBuf = this;
  if ( execType && execType != Exec_Event
    || (v8 = env->Target, (v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0)
    && v8->Depth >= -1 )
  {
    if ( (env->Target->Flags & 0x10) == 0 )
    {
      ++env->ExecutionNestingLevel;
      pObject = this->pBufferData.pObject;
      tryCount = 0;
      if ( !pObject->BufferLen || (pBuffer = pObject->pBuffer, !*pBuffer) )
        pBuffer = 0;
      pContext = env->StringContext.pContext;
      execContext.pEnv = env;
      execContext.pOriginalTarget = env->Target;
      execContext.pBuffer = pBuffer;
      pHeap = pContext->pHeap;
      execContext.WithStack.pHeap = pHeap;
      if ( pinitialWithStack
        && (v13 = (Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)pHeap->Alloc(pHeap, 12u, 0)) != 0 )
      {
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy>::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy>(
          v13,
          pinitialWithStack);
      }
      else
      {
        v14 = 0;
      }
      execContext.WithStack.pWithStackArray = v14;
      Scaleform::GFx::AS2::ActionLogger::ActionLogger(&execContext.LogF, execContext.pOriginalTarget, 0);
      execContext.pPrevLog = execContext.pEnv->pASLogger;
      execContext.Version = Scaleform::GFx::DisplayObjectBase::GetVersion(execContext.pEnv->Target);
      v15 = (*((_BYTE *)&execContext + 54) ^ (4 * (execType == Exec_Function2))) & 4 ^ *((_BYTE *)&execContext + 54);
      *((_BYTE *)&execContext + 54) = (v15 ^ (2 * execContext.LogF.VerboseAction)) & 2 ^ v15;
      IsVerboseActionErrors = execContext.LogF.IsVerboseActionErrors;
      execContext.ExecType = execType;
      v17 = IsVerboseActionErrors(&execContext.LogF);
      v18 = (v17 ^ *((_BYTE *)&execContext + 54)) & 1;
      isOriginalTargetValid = (*((_BYTE *)env + 194) & 2) == 0;
      v19 = *(_DWORD *)(p_Stack + 8);
      *((_BYTE *)&execContext + 54) ^= v18;
      v20 = *(_DWORD *)(v19 + 12);
      v21 = execBytes;
      if ( execBytes >= v20 )
        v21 = v20;
      PC = startPc;
      execContext.StopPC = startPc + v21;
      execContext.NextPC = startPc;
      execContext.PC = startPc;
      pobj.pObject = 0;
      if ( startPc < startPc + v21 )
      {
        while ( 1 )
        {
          if ( execContext.WithStack.pWithStackArray )
          {
            Size = execContext.WithStack.pWithStackArray->Data.Size;
            v24 = 0;
            if ( Size )
            {
              p_Stack = execContext.WithStack.pWithStackArray->Data.Data[Size - 1].BlockEndPc & 0x7FFFFFFF;
              do
              {
                if ( PC < p_Stack )
                  break;
                ++v24;
              }
              while ( v24 < Size );
              if ( v24 )
              {
                v25 = Size - v24;
                p_Stack = v25;
                pWithStackArray = execContext.WithStack.pWithStackArray;
                if ( v25 >= execContext.WithStack.pWithStackArray->Data.Size )
                {
                  if ( v25 >= execContext.WithStack.pWithStackArray->Data.Policy.Capacity )
                    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
                      (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)execContext.WithStack.pWithStackArray,
                      execContext.WithStack.pWithStackArray,
                      v25 + (v25 >> 2));
                }
                else if ( v25 < execContext.WithStack.pWithStackArray->Data.Policy.Capacity >> 1 )
                {
                  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *)execContext.WithStack.pWithStackArray,
                    execContext.WithStack.pWithStackArray,
                    v25);
                }
                pWithStackArray->Data.Size = p_Stack;
                PC = execContext.PC;
              }
            }
          }
          v27 = execContext.pBuffer[PC];
          if ( (v27 & 0x80u) != 0 )
            break;
          execContext.NextPC = PC + 1;
          switch ( v27 )
          {
            case 0u:
              execContext.NextPC = execContext.StopPC;
              tryCount = 0;
              goto LABEL_869;
            case 4u:
              if ( (*((_BYTE *)env + 194) & 2) == 0 )
              {
                p_Stack = (Scaleform::GFx::PlayState)env->Target;
                v28 = *(_DWORD *)p_Stack;
                v29 = (*(int (__thiscall **)(Scaleform::GFx::PlayState))(*(_DWORD *)p_Stack + 420))(p_Stack);
                (*(void (__thiscall **)(Scaleform::GFx::PlayState, int))(v28 + 432))(p_Stack, v29 + 1);
              }
              goto LABEL_867;
            case 5u:
              if ( (*((_BYTE *)env + 194) & 2) == 0 )
              {
                p_Stack = (Scaleform::GFx::PlayState)env->Target;
                v30 = *(_DWORD *)p_Stack;
                v31 = (*(int (__thiscall **)(Scaleform::GFx::PlayState))(*(_DWORD *)p_Stack + 420))(p_Stack);
                (*(void (__thiscall **)(Scaleform::GFx::PlayState, int))(v30 + 432))(p_Stack, v31 - 1);
              }
              goto LABEL_727;
            case 6u:
              if ( (*((_BYTE *)env + 194) & 2) == 0 )
                env->Target->SetPlayState(env->Target, State_Playing);
              goto LABEL_869;
            case 7u:
              if ( (*((_BYTE *)env + 194) & 2) == 0 )
                env->Target->SetPlayState(env->Target, State_Stopped);
              goto LABEL_869;
            case 9u:
              v32 = (Scaleform::GFx::AS2::MovieRoot *)env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject;
              if ( v32 )
              {
                LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v32, 0);
                if ( LevelMovie )
                  LevelMovie->StopActiveSounds(LevelMovie);
              }
              goto LABEL_869;
            case 0xAu:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              pCurrent = env->Stack.pCurrent;
              pPrevPageTop = pCurrent - 1;
              if ( pCurrent <= env->Stack.pPageStart )
                pPrevPageTop = env->Stack.pPrevPageTop;
              goto LABEL_46;
            case 0xBu:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v36 = env->Stack.pCurrent;
              v37 = v36 - 1;
              if ( v36 <= env->Stack.pPageStart )
                v37 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Sub(v37, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0xCu:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v38 = env->Stack.pCurrent;
              v39 = v38 - 1;
              if ( v38 <= env->Stack.pPageStart )
                v39 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Mul(v39, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0xDu:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v40 = env->Stack.pCurrent;
              v41 = v40 - 1;
              if ( v40 <= env->Stack.pPageStart )
                v41 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Div(v41, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0xEu:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v42 = env->Stack.pCurrent;
              v43 = v42 - 1;
              if ( v42 > env->Stack.pPageStart )
              {
                v44 = v42 - 1;
              }
              else
              {
                v43 = env->Stack.pPrevPageTop;
                v44 = v43;
              }
              IsEqual = Scaleform::GFx::AS2::Value::IsEqual(v43, env, env->Stack.pCurrent);
              goto LABEL_59;
            case 0xFu:
            case 0x48u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v46 = env->Stack.pCurrent;
              v47 = v46 - 1;
              if ( v46 <= env->Stack.pPageStart )
                v47 = env->Stack.pPrevPageTop;
              v48 = Scaleform::GFx::AS2::Value::Compare(
                      v47,
                      (Scaleform::GFx::AS2::Value *)valBuf1,
                      env,
                      env->Stack.pCurrent,
                      -1);
              v49 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v49 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::operator=(v49, v48);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              if ( v48->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v48);
              goto LABEL_869;
            case 0x10u:
              v50 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v51 = v50 - 1;
              if ( v50 <= env->Stack.pPageStart )
                v51 = env->Stack.pPrevPageTop;
              v52 = Scaleform::GFx::AS2::Value::ToBool(v51, env)
                 && Scaleform::GFx::AS2::Value::ToBool(*(Scaleform::GFx::AS2::Value **)p_Stack, env);
              v53 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v53 = env->Stack.pPrevPageTop;
              goto LABEL_79;
            case 0x11u:
              v54 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v55 = v54 - 1;
              if ( v54 <= env->Stack.pPageStart )
                v55 = env->Stack.pPrevPageTop;
              v52 = Scaleform::GFx::AS2::Value::ToBool(v55, env)
                 || Scaleform::GFx::AS2::Value::ToBool(*(Scaleform::GFx::AS2::Value **)p_Stack, env);
              v53 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v53 = env->Stack.pPrevPageTop;
LABEL_79:
              Scaleform::GFx::AS2::Value::SetBool(v53, v52);
              goto LABEL_855;
            case 0x12u:
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( *(_BYTE *)p_Stack == 2 )
              {
                *(_BYTE *)(p_Stack + 4) = *(_BYTE *)(p_Stack + 4) == 0;
              }
              else if ( Scaleform::GFx::AS2::Value::IsUndefined(env->Stack.pCurrent) )
              {
                *(_BYTE *)p_Stack = 2;
                *(_BYTE *)(p_Stack + 4) = 1;
              }
              else
              {
                v56 = Scaleform::GFx::AS2::Value::ToBool((Scaleform::GFx::AS2::Value *)p_Stack, env);
                Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)p_Stack, v56 == 0);
              }
              goto LABEL_869;
            case 0x13u:
              v57 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v58 = v57 - 1;
              if ( v57 <= env->Stack.pPageStart )
                v58 = env->Stack.pPrevPageTop;
              v59 = (Scaleform::GFx::InteractiveObject_vtbl **)Scaleform::GFx::AS2::Value::ToStringVersioned(
                                                                 v58,
                                                                 (Scaleform::GFx::ASString *)tmpStr1Buf,
                                                                 env,
                                                                 execContext.Version);
              target = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Value::ToStringVersioned(
                                                              *(Scaleform::GFx::AS2::Value **)p_Stack,
                                                              (Scaleform::GFx::ASString *)tmpStr2Buf,
                                                              env,
                                                              execContext.Version);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v60 = env->Stack.pPrevPageTop;
              else
                v60 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              Scaleform::GFx::AS2::Value::SetBool(
                v60,
                *v59 == target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              v61 = (Scaleform::GFx::ASStringNode *)*v59;
              v91 = v61->RefCount-- == 1;
              if ( v91 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v61);
              pNode = (Scaleform::GFx::AS2::Value *)target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
              v91 = target->SetMatrix-- == (void (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, const Scaleform::Render::Matrix2x4<float> *))1;
              if ( v91 )
                goto LABEL_843;
              goto LABEL_869;
            case 0x14u:
              v63 = Scaleform::GFx::AS2::Value::ToStringVersioned(
                      env->Stack.pCurrent,
                      (Scaleform::GFx::ASString *)tmpStr1Buf,
                      env,
                      execContext.Version);
              v64 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)v63;
              Length = Scaleform::GFx::ASConstString::GetLength(v63);
              Scaleform::GFx::AS2::Value::SetInt(v64, Length);
              pNode = *(Scaleform::GFx::AS2::Value **)p_Stack;
              v91 = (*(_DWORD *)(*(_DWORD *)p_Stack + 12))-- == 1;
              if ( v91 )
                goto LABEL_843;
              goto LABEL_869;
            case 0x15u:
              v66 = &env->Stack;
              v67 = 32 * (env->Stack.Pages.Data.Size - 1) + env->Stack.pCurrent - env->Stack.pPageStart;
              v68 = 0;
              if ( v67 >= 2 )
                v68 = &env->Stack.Pages.Data.Data[(v67 - 2) >> 5]->Values[(v67 - 2) & 0x1F];
              v69 = Scaleform::GFx::AS2::Value::ToStringVersioned(
                      v68,
                      (Scaleform::GFx::ASString *)tmpStr1Buf,
                      env,
                      execContext.Version);
              v70 = v66->pCurrent;
              nargs = (int)v69;
              v71 = v70 - 1;
              if ( v70 <= env->Stack.pPageStart )
                v71 = env->Stack.pPrevPageTop;
              val_4 = Scaleform::GFx::AS2::Value::ToInt32(v70, env);
              v72 = Scaleform::GFx::AS2::Value::ToInt32(v71, env);
              v73 = Scaleform::GFx::AS2::StringProto::StringSubstring(
                      (Scaleform::GFx::ASString *)tmpStr2Buf,
                      (const Scaleform::GFx::ASString *)nargs,
                      (const char *)(v72 - 1),
                      val_4);
              v74 = v66->pCurrent;
              v75 = v73;
              if ( &v66->pCurrent[-2] >= env->Stack.pPageStart )
              {
                if ( v74->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v74);
                --v66->pCurrent;
                if ( v66->pCurrent->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v66->pCurrent);
                --v66->pCurrent;
              }
              else
              {
                target = (Scaleform::GFx::InteractiveObject *)2;
                do
                {
                  if ( v66->pCurrent->T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(v66->pCurrent);
                  --v66->pCurrent;
                  if ( env->Stack.pCurrent < env->Stack.pPageStart )
                    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
                  target = (Scaleform::GFx::InteractiveObject *)((char *)target - 1);
                }
                while ( target );
              }
              Scaleform::GFx::AS2::Value::SetString(v66->pCurrent, v75);
              v76 = *(Scaleform::GFx::ASStringNode **)nargs;
              p_Stack = -1;
              v91 = (*(_DWORD *)(*(_DWORD *)nargs + 12))-- == 1;
              if ( v91 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v76);
              pNode = (Scaleform::GFx::AS2::Value *)v75->pNode;
              v91 = v75->pNode->RefCount-- == 1;
              if ( v91 )
                goto LABEL_843;
              goto LABEL_869;
            case 0x17u:
              goto $LN69_0;
            case 0x18u:
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              v77 = Scaleform::GFx::AS2::Value::ToInt32((Scaleform::GFx::AS2::Value *)p_Stack, env);
              Scaleform::GFx::AS2::Value::SetInt((Scaleform::GFx::AS2::Value *)p_Stack, v77);
              goto LABEL_869;
            case 0x1Cu:
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              Scaleform::GFx::AS2::Value::ToStringImpl(
                (Scaleform::GFx::AS2::Value *)p_Stack,
                (Scaleform::GFx::ASString *)tmpStr1Buf,
                env,
                -1,
                0);
              if ( env->StringContext.SWFVersion <= 6u )
              {
                if ( Scaleform::GFx::ASString::Compare_CaseInsensitive_Resolved(
                       (Scaleform::GFx::ASString *)&env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23],
                       (const Scaleform::GFx::ASString *)tmpStr1Buf) )
                {
LABEL_133:
                  v79 = Scaleform::GFx::NumberUtil::NaN();
                  Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)p_Stack, v79);
                  v80 = *(char ***)tmpStr1Buf;
                  goto LABEL_841;
                }
                if ( Scaleform::GFx::ASString::Compare_CaseInsensitive_Resolved(
                       (Scaleform::GFx::ASString *)&env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].RefCount,
                       (const Scaleform::GFx::ASString *)tmpStr1Buf) )
                {
LABEL_135:
                  v81 = Scaleform::GFx::NumberUtil::POSITIVE_INFINITY();
                  Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)p_Stack, v81);
                  v80 = *(char ***)tmpStr1Buf;
                  goto LABEL_841;
                }
                if ( !Scaleform::GFx::ASString::Compare_CaseInsensitive_Resolved(
                        (Scaleform::GFx::ASString *)&env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
                        (const Scaleform::GFx::ASString *)tmpStr1Buf) )
                {
LABEL_137:
                  Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)p_Stack);
                  *(_BYTE *)p_Stack = 0;
                  Scaleform::GFx::AS2::Environment::GetVariable(
                    env,
                    (const Scaleform::GFx::ASString *)tmpStr1Buf,
                    (Scaleform::GFx::AS2::Value *)p_Stack,
                    execContext.WithStack.pWithStackArray,
                    0,
                    0,
                    0);
                  v80 = *(char ***)tmpStr1Buf;
                  goto LABEL_841;
                }
              }
              else
              {
                v78 = env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
                if ( *(Scaleform::GFx::ASMovieRootBase_vtbl **)tmpStr1Buf == v78[23].__vftable )
                  goto LABEL_133;
                if ( *(_DWORD *)tmpStr1Buf == v78[23].RefCount )
                  goto LABEL_135;
                if ( *(Scaleform::GFx::MovieImpl **)tmpStr1Buf != v78[23].pMovieImpl )
                  goto LABEL_137;
              }
              v82 = Scaleform::GFx::NumberUtil::NEGATIVE_INFINITY();
              Scaleform::GFx::AS2::Value::SetNumber((Scaleform::GFx::AS2::Value *)p_Stack, v82);
              v80 = *(char ***)tmpStr1Buf;
LABEL_841:
              --v80[3];
              pNode = (Scaleform::GFx::AS2::Value *)v80;
              v91 = v80[3] == 0;
LABEL_842:
              if ( v91 )
LABEL_843:
                Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pNode);
              goto LABEL_869;
            case 0x1Du:
              v83 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v84 = v83 - 1;
              if ( v83 <= env->Stack.pPageStart )
                v84 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::ToStringImpl(v84, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
              Scaleform::GFx::AS2::Environment::SetVariable(
                env,
                (int)&savedregs,
                (Scaleform::GFx::ASString *)tmpStr1Buf,
                *(const Scaleform::GFx::AS2::Value **)p_Stack,
                execContext.WithStack.pWithStackArray,
                1);
              v85 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              if ( (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 32) >= env->Stack.pPageStart )
              {
                if ( v85->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v85);
                *(_DWORD *)p_Stack -= 16;
                if ( **(_BYTE **)p_Stack >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
                *(_DWORD *)p_Stack -= 16;
                v80 = *(char ***)tmpStr1Buf;
              }
              else
              {
                v86 = 2;
                do
                {
                  if ( **(_BYTE **)p_Stack >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
                  *(_DWORD *)p_Stack -= 16;
                  if ( env->Stack.pCurrent < env->Stack.pPageStart )
                    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
                  --v86;
                }
                while ( v86 );
                v80 = *(char ***)tmpStr1Buf;
              }
              goto LABEL_841;
            case 0x20u:
              Scaleform::GFx::AS2::ExecutionContext::SetTargetOpCode(&execContext);
              goto LABEL_869;
            case 0x21u:
              v87 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v88 = v87 - 1;
              if ( v87 <= env->Stack.pPageStart )
                v88 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::ConvertToStringVersioned(
                v88,
                env,
                (Scaleform::GFx::ASStringNode *)execContext.Version);
              v89 = Scaleform::GFx::AS2::Value::ToStringVersioned(
                      *(Scaleform::GFx::AS2::Value **)p_Stack,
                      (Scaleform::GFx::ASString *)tmpStr1Buf,
                      env,
                      execContext.Version);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v90 = env->Stack.pPrevPageTop;
              else
                v90 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              Scaleform::GFx::AS2::Value::StringConcat(v90, env, v89);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              pNode = (Scaleform::GFx::AS2::Value *)v89->pNode;
              v91 = v89->pNode->RefCount-- == 1;
              goto LABEL_842;
            case 0x22u:
              v92 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              if ( v92 <= env->Stack.pPageStart )
                v93 = env->Stack.pPrevPageTop;
              else
                v93 = v92 - 1;
              TargetByValue = Scaleform::GFx::AS2::Environment::FindTargetByValue(env, v93);
              if ( TargetByValue )
              {
                target = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int))(*((_DWORD *)&TargetByValue->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                           + TargetByValue->AvmObjOffset)
                                                                                         + 4))((int)TargetByValue + 4 * TargetByValue->AvmObjOffset);
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v95 = env->Stack.pPrevPageTop;
                else
                  v95 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                val = v95;
                p_GetYRotation = &target->GetYRotation;
                v97 = Scaleform::GFx::AS2::Value::ToInt32(*(Scaleform::GFx::AS2::Value **)p_Stack, env);
                ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, int, Scaleform::GFx::AS2::Value *, int))*p_GetYRotation)(
                  target,
                  v97,
                  val,
                  1);
              }
              else
              {
                v98 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v98 = env->Stack.pPrevPageTop;
                Scaleform::GFx::AS2::Value::DropRefs(v98);
                v98->T.Type = 0;
              }
              goto LABEL_855;
            case 0x23u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v99 = 32 * (env->Stack.Pages.Data.Size - 1) + env->Stack.pCurrent - env->Stack.pPageStart;
              v100 = 0;
              if ( v99 >= 2 )
                v100 = &env->Stack.Pages.Data.Data[(v99 - 2) >> 5]->Values[(v99 - 2) & 0x1F];
              v101 = Scaleform::GFx::AS2::Environment::FindTargetByValue(env, v100);
              if ( v101 )
              {
                v102 = (Scaleform::GFx::InteractiveObject *)(*(int (__thiscall **)(int))(*((_DWORD *)&v101->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                                                         + v101->AvmObjOffset)
                                                                                       + 4))((int)v101 + 4 * v101->AvmObjOffset);
                v103 = *(Scaleform::GFx::AS2::Value **)p_Stack;
                target = v102;
                v104 = v103 - 1;
                if ( v103 <= env->Stack.pPageStart )
                  v104 = env->Stack.pPrevPageTop;
                vala = v103;
                p_SetYRotation = &target->SetYRotation;
                v106 = Scaleform::GFx::AS2::Value::ToInt32(v104, env);
                ((void (__thiscall *)(Scaleform::GFx::InteractiveObject *, int, Scaleform::GFx::AS2::Value *, int))*p_SetYRotation)(
                  target,
                  v106,
                  vala,
                  1);
              }
              goto LABEL_186;
            case 0x24u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v107 = 32 * (env->Stack.Pages.Data.Size - 1) + env->Stack.pCurrent - env->Stack.pPageStart;
              v108 = 0;
              if ( v107 >= 2 )
                v108 = &env->Stack.Pages.Data.Data[(v107 - 2) >> 5]->Values[(v107 - 2) & 0x1F];
              v109 = Scaleform::GFx::AS2::Environment::FindTargetByValue(env, v108);
              if ( v109 )
              {
                v110 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v110 = env->Stack.pPrevPageTop;
                Scaleform::GFx::AS2::Value::ToStringImpl(v110, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
                AvmObjOffset = v109->AvmObjOffset;
                v112 = *((_DWORD *)&v109->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                       + AvmObjOffset);
                sceneOffset = *(_DWORD *)p_Stack;
                v113 = (Scaleform::GFx::AS2::AvmCharacter *)(*(int (__thiscall **)(int))(v112 + 4))((int)v109 + 4 * AvmObjOffset);
                v114 = Scaleform::GFx::AS2::Value::ToInt32((Scaleform::GFx::AS2::Value *)sceneOffset, env);
                Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject(
                  v113,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  v114,
                  0);
                v115 = *(Scaleform::GFx::ASStringNode **)tmpStr1Buf;
                --*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 12);
                if ( !v115->RefCount )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v115);
              }
LABEL_186:
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&env->Stack);
              goto LABEL_869;
            case 0x25u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v116 = Scaleform::GFx::AS2::Environment::FindTargetByValue(env, env->Stack.pCurrent);
              if ( v116 )
              {
                if ( v116->Depth >= 0x4000 )
                {
                  Scaleform::GFx::InteractiveObject::RemoveDisplayObject(v116);
                }
                else
                {
                  Name = Scaleform::GFx::DisplayObject::GetName(v116, &result);
                  Scaleform::GFx::AS2::ActionLogger::LogScriptWarning(
                    &execContext.LogF,
                    "removeMovieClip(\"%s\") failed - depth must be >= 0",
                    Name->pNode->pData);
                  v118 = result.pNode;
                  --result.pNode->RefCount;
                  if ( !v118->RefCount )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v118);
                }
              }
              goto LABEL_855;
            case 0x26u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              Scaleform::GFx::AS2::FnCall::FnCall(
                (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                env->Stack.pCurrent,
                0,
                env,
                1,
                env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 32);
              v120 = v119;
              Scaleform::GFx::AS2::GAS_GlobalTrace(v119);
              if ( env->Stack.pCurrent->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(env->Stack.pCurrent);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              ((void (__thiscall *)(const Scaleform::GFx::AS2::FnCall *, _DWORD))v120->~Scaleform::GFx::AS2::FnCall)(
                v120,
                0);
              goto LABEL_869;
            case 0x27u:
              Scaleform::GFx::AS2::ExecutionContext::StartDragOpCode(&execContext);
              goto LABEL_869;
            case 0x28u:
              Scaleform::GFx::MovieImpl::StopDrag(env->Target->pASRoot->pMovieImpl, 0);
              goto LABEL_869;
            case 0x29u:
              v121 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v122 = v121 - 1;
              if ( v121 <= env->Stack.pPageStart )
                v122 = env->Stack.pPrevPageTop;
              v123 = Scaleform::GFx::AS2::Value::ToStringVersioned(
                       v122,
                       (Scaleform::GFx::ASString *)tmpStr1Buf,
                       env,
                       execContext.Version);
              v124 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              nargs = (int)v123;
              v125 = Scaleform::GFx::AS2::Value::ToStringVersioned(
                       v124,
                       (Scaleform::GFx::ASString *)tmpStr2Buf,
                       env,
                       execContext.Version);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v126 = (Scaleform::GFx::InteractiveObject *)env->Stack.pPrevPageTop;
              else
                v126 = (Scaleform::GFx::InteractiveObject *)(*(_DWORD *)p_Stack - 16);
              target = v126;
              v127 = Scaleform::GFx::ASString::operator<((Scaleform::GFx::ASString *)nargs, v125);
              Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)target, v127);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              v128 = v125->pNode;
              v91 = v128->RefCount-- == 1;
              if ( v91 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v128);
              pNode = *(Scaleform::GFx::AS2::Value **)nargs;
              v91 = (*(_DWORD *)(*(_DWORD *)nargs + 12))-- == 1;
              goto LABEL_842;
            case 0x2Au:
              Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, PC, &tryCount);
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              Scaleform::GFx::AS2::Value::operator=(&env->ThrowingValue, env->Stack.pCurrent);
              if ( env->Stack.pCurrent->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(env->Stack.pCurrent);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              goto LABEL_223;
            case 0x2Bu:
              Scaleform::GFx::AS2::ExecutionContext::CastObjectOpCode(&execContext);
              goto LABEL_869;
            case 0x2Cu:
              Scaleform::GFx::AS2::ExecutionContext::ImplementsOpCode(&execContext);
              goto LABEL_869;
            case 0x30u:
              v129 = Scaleform::GFx::AS2::Value::ToInt32(env->Stack.pCurrent, env);
              if ( v129 < 1 )
                v129 = 1;
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              NextRandom = Scaleform::GFx::AS2::Math::GetNextRandom(
                             v129,
                             (Scaleform::String)env->Target->pASRoot->pMovieImpl);
              Scaleform::GFx::AS2::Value::SetInt((Scaleform::GFx::AS2::Value *)p_Stack, NextRandom % v129);
              goto LABEL_869;
            case 0x31u:
              p_Stack = (Scaleform::GFx::PlayState)Scaleform::GFx::AS2::Value::ToStringVersioned(
                                                     env->Stack.pCurrent,
                                                     (Scaleform::GFx::ASString *)tmpStr1Buf,
                                                     env,
                                                     execContext.Version);
              v131 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)p_Stack);
              Scaleform::GFx::AS2::Value::SetInt(env->Stack.pCurrent, v131);
              pNode = *(Scaleform::GFx::AS2::Value **)p_Stack;
              v91 = (*(_DWORD *)(*(_DWORD *)p_Stack + 12))-- == 1;
              goto LABEL_842;
            case 0x32u:
              Scaleform::GFx::AS2::Value::ToStringImpl(
                env->Stack.pCurrent,
                (Scaleform::GFx::ASString *)tmpStr1Buf,
                env,
                -1,
                0);
              Scaleform::GFx::AS2::Value::SetInt(env->Stack.pCurrent, ***(char ***)tmpStr1Buf);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              goto LABEL_869;
            case 0x33u:
              v132 = Scaleform::GFx::AS2::Value::ToInt32(env->Stack.pCurrent, env);
              v133 = env->StringContext.pContext;
              LOWORD(nargsf) = v132;
              StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             (Scaleform::GFx::ASStringManager *)v133->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             (char *)&nargsf);
              goto LABEL_232;
            case 0x34u:
              pMovieImpl = env->Target->pASRoot->pMovieImpl;
              *(_QWORD *)&v137 = pMovieImpl->GetASTimerMs(pMovieImpl);
              ++env->Stack.pCurrent;
              v439 = *(_QWORD *)&v137 & 0x7FFFFFFFFFFFFFFFLL;
              nargsf = v137;
              LODWORD(v137) = env->Stack.pCurrent;
              v440 = *(_QWORD *)&v137 & 0x8000000000000000uLL;
              u = (double)__PAIR64__(HIDWORD(v137), v439);
              if ( (Scaleform::GFx::AS2::Value *)LODWORD(v137) >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( p_Stack )
              {
                v138 = u;
                *(_BYTE *)p_Stack = 3;
                *(long double *)(p_Stack + 4) = v138;
              }
              goto LABEL_869;
            case 0x35u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v139 = 32 * (env->Stack.Pages.Data.Size - 1) + env->Stack.pCurrent - env->Stack.pPageStart;
              v140 = 0;
              if ( v139 >= 2 )
                v140 = &env->Stack.Pages.Data.Data[(v139 - 2) >> 5]->Values[(v139 - 2) & 0x1F];
              v141 = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Value::ToStringVersioned(
                                                            v140,
                                                            (Scaleform::GFx::ASString *)tmpStr1Buf,
                                                            env,
                                                            execContext.Version);
              v142 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              target = v141;
              v143 = v142 - 1;
              if ( v142 <= env->Stack.pPageStart )
                v143 = env->Stack.pPrevPageTop;
              val_4a = Scaleform::GFx::AS2::Value::ToInt32(v142, env);
              v144 = Scaleform::GFx::AS2::Value::ToInt32(v143, env);
              v145 = Scaleform::GFx::AS2::StringProto::StringSubstring(
                       (Scaleform::GFx::ASString *)tmpStr2Buf,
                       (const Scaleform::GFx::ASString *)target,
                       (const char *)(v144 - 1),
                       val_4a);
              v146 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              v147 = v145;
              if ( (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 32) >= env->Stack.pPageStart )
              {
                if ( v146->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v146);
                *(_DWORD *)p_Stack -= 16;
                if ( **(_BYTE **)p_Stack >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
                *(_DWORD *)p_Stack -= 16;
              }
              else
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, 2u);
              }
              Scaleform::GFx::AS2::Value::SetString(*(Scaleform::GFx::AS2::Value **)p_Stack, v147);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)target, 0);
              Scaleform::GFx::ASString::`scalar deleting destructor'(v147, 0);
              goto LABEL_869;
            case 0x36u:
              p_Stack = (Scaleform::GFx::PlayState)Scaleform::GFx::AS2::Value::ToStringVersioned(
                                                     env->Stack.pCurrent,
                                                     (Scaleform::GFx::ASString *)tmpStr1Buf,
                                                     env,
                                                     execContext.Version);
              if ( *(_DWORD *)(*(_DWORD *)p_Stack + 20) )
                CharAt = Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)p_Stack, 0);
              else
                CharAt = 0;
              Scaleform::GFx::AS2::Value::SetInt(env->Stack.pCurrent, CharAt);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)p_Stack, 0);
              goto LABEL_869;
            case 0x37u:
              v149 = Scaleform::GFx::AS2::Value::ToUInt32(env->Stack.pCurrent, env);
              v150 = env->StringContext.pContext;
              LODWORD(nargsf) = v149;
              StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                             (Scaleform::GFx::ASStringManager *)v150->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                             (const wchar_t *)&nargsf,
                             -1);
LABEL_232:
              ++StringNode->RefCount;
              v135 = env->Stack.pCurrent;
              target = (Scaleform::GFx::InteractiveObject *)StringNode;
              Scaleform::GFx::AS2::Value::SetString(v135, (const Scaleform::GFx::ASString *)&target);
              Scaleform::GFx::ASString::~ASString((Scaleform::GFx::ASString *)&target);
              goto LABEL_869;
            case 0x3Au:
              v151 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              retVal = 0;
              v152 = v151 - 1;
              if ( v151 <= env->Stack.pPageStart )
                v152 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::ToStringImpl(v151, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
              if ( execContext.Version <= 6u && (v152->T.Type == 1 || Scaleform::GFx::AS2::Value::IsUndefined(v152)) )
              {
                valBuf1[0] = 0;
                if ( Scaleform::GFx::AS2::Environment::FindOwnerOfMember(
                       env,
                       (const Scaleform::GFx::ASString *)tmpStr1Buf,
                       (Scaleform::GFx::AS2::Value *)valBuf1,
                       execContext.WithStack.pWithStackArray) )
                {
                  v153 = Scaleform::GFx::AS2::Value::ToObjectInterface((Scaleform::GFx::AS2::Value *)valBuf1, env);
                  if ( v153 )
                    retVal = v153->DeleteMember(v153, &env->StringContext, (const Scaleform::GFx::ASString *)tmpStr1Buf);
                }
                Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
              }
              else
              {
                v154 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v154 = env->Stack.pPrevPageTop;
                v155 = Scaleform::GFx::AS2::Value::ToObjectInterface(v154, env);
                if ( v155 )
                  retVal = v155->DeleteMember(v155, &env->StringContext, (const Scaleform::GFx::ASString *)tmpStr1Buf);
              }
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              Scaleform::GFx::AS2::Value::SetBool(*(Scaleform::GFx::AS2::Value **)p_Stack, retVal);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              goto LABEL_869;
            case 0x3Bu:
              Scaleform::GFx::AS2::Value::ToStringImpl(
                env->Stack.pCurrent,
                (Scaleform::GFx::ASString *)tmpStr1Buf,
                env,
                -1,
                0);
              valBuf1[0] = 0;
              if ( (*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 16) & 0x2000000) != 0
                || !Scaleform::GFx::AS2::Environment::IsPath((const Scaleform::GFx::ASString *)tmpStr1Buf) )
              {
                if ( !Scaleform::GFx::AS2::Environment::FindOwnerOfMember(
                        env,
                        (const Scaleform::GFx::ASString *)tmpStr1Buf,
                        (Scaleform::GFx::AS2::Value *)valBuf1,
                        execContext.WithStack.pWithStackArray) )
                  goto LABEL_276;
              }
              else
              {
                Scaleform::GFx::AS2::Environment::GetVarParams::GetVarParams(
                  &v446,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  0,
                  execContext.WithStack.pWithStackArray,
                  0,
                  (Scaleform::GFx::AS2::Value *)valBuf1,
                  0);
                if ( !Scaleform::GFx::AS2::Environment::FindVariable(
                        env,
                        (int)&savedregs,
                        (int)env,
                        v156,
                        0,
                        (Scaleform::GFx::ASString *)tmpStr1Buf)
                  || Scaleform::GFx::AS2::Value::IsUndefined((Scaleform::GFx::AS2::Value *)valBuf1) )
                {
LABEL_276:
                  Scaleform::GFx::AS2::Value::SetBool(env->Stack.pCurrent, 0);
                  goto LABEL_277;
                }
              }
              v157 = Scaleform::GFx::AS2::Value::ToObjectInterface((Scaleform::GFx::AS2::Value *)valBuf1, env);
              if ( !v157 )
                goto LABEL_276;
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              val_4b = v157->DeleteMember(v157, &env->StringContext, (const Scaleform::GFx::ASString *)tmpStr1Buf);
              Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)p_Stack, val_4b);
LABEL_277:
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
              goto LABEL_869;
            case 0x3Cu:
              v158 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v159 = v158 - 1;
              if ( v158 <= env->Stack.pPageStart )
                v159 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::ToStringImpl(v159, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
              if ( (*((_BYTE *)&execContext + 54) & 4) != 0 || execType == Exec_Function )
                Scaleform::GFx::AS2::Environment::SetLocal(
                  env,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  *(const Scaleform::GFx::AS2::Value **)p_Stack);
              else
                Scaleform::GFx::AS2::Environment::SetVariable(
                  env,
                  (int)&savedregs,
                  (Scaleform::GFx::ASString *)tmpStr1Buf,
                  *(const Scaleform::GFx::AS2::Value **)p_Stack,
                  execContext.WithStack.pWithStackArray,
                  1);
              v160 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              if ( (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 32) >= env->Stack.pPageStart )
              {
                if ( v160->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v160);
                *(_DWORD *)p_Stack -= 16;
                if ( **(_BYTE **)p_Stack >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
                *(_DWORD *)p_Stack -= 16;
                Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              }
              else
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, 2u);
                Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              }
              goto LABEL_869;
            case 0x3Du:
              v161 = env->Stack.pCurrent;
              v162 = &env->Stack;
              valBuf1[0] = 0;
              valBuf2[0] = 0;
              v91 = v161->T.Type == 5;
              nargs = (int)valBuf1;
              test = 1;
              if ( v91 )
              {
                Scaleform::GFx::AS2::Value::ToStringImpl(v161, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
                Scaleform::GFx::AS2::Environment::GetVariable(
                  env,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  (Scaleform::GFx::AS2::Value *)valBuf1,
                  execContext.WithStack.pWithStackArray,
                  0,
                  (Scaleform::GFx::AS2::Value *)valBuf2,
                  0);
                if ( Scaleform::GFx::AS2::Value::IsFunction((Scaleform::GFx::AS2::Value *)valBuf1) )
                  goto LABEL_311;
                if ( valBuf1[0] != 6 )
                  goto LABEL_305;
                v163 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)valBuf1, env);
                p_Stack = (Scaleform::GFx::PlayState)v163;
                if ( v163 )
                  v163->RefCount = (v163->RefCount + 1) & 0x8FFFFFFF;
                v164 = pobj.pObject;
                if ( pobj.pObject )
                {
                  RefCount = pobj.pObject->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
                  {
                    pobj.pObject->RefCount = RefCount - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v164);
                  }
                }
                v166 = (Scaleform::GFx::AS2::Object *)p_Stack;
                pobj.pObject = (Scaleform::GFx::AS2::Object *)p_Stack;
                if ( p_Stack )
                {
                  if ( (*(unsigned __int8 (__thiscall **)(__int32))(*(_DWORD *)(p_Stack + 16) + 60))(p_Stack + 16) )
                  {
                    Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
                    sceneOffset = (*(int (__thiscall **)(__int32, char *, Scaleform::GFx::AS2::ASStringContext *))(*(_DWORD *)(p_Stack + 16) + 56))(
                                    p_Stack + 16,
                                    funcBuf,
                                    &env->StringContext);
                    Scaleform::GFx::AS2::Value::Value(
                      (Scaleform::GFx::AS2::Value *)valBuf1,
                      (const Scaleform::GFx::AS2::FunctionRef *)sceneOffset);
                    nargs = v167;
                    Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                      (Scaleform::GFx::AS2::FunctionRef *)sceneOffset,
                      0);
                    Scaleform::GFx::AS2::Value::SetAsObject(
                      (Scaleform::GFx::AS2::Value *)valBuf2,
                      (Scaleform::GFx::AS2::Object *)p_Stack);
                    v166 = (Scaleform::GFx::AS2::Object *)p_Stack;
LABEL_307:
                    if ( v166 )
                    {
                      v168 = v166->RefCount;
                      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v168) != 0 )
                      {
                        v166->RefCount = v168 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v166);
                      }
                    }
                    pobj.pObject = 0;
LABEL_311:
                    Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
                    goto LABEL_313;
                  }
LABEL_305:
                  v166 = pobj.pObject;
                }
                test = 0;
                goto LABEL_307;
              }
              Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)valBuf1, v161);
LABEL_313:
              v169 = v162->pCurrent - 1;
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v169 = env->Stack.pPrevPageTop;
              nargsf = Scaleform::GFx::AS2::Value::ToNumber(v169, env);
              if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(nargsf) )
                target = 0;
              else
                target = (Scaleform::GFx::InteractiveObject *)(int)nargsf;
              valBuf3[0] = 0;
              if ( test )
              {
                p_Stack = (Scaleform::GFx::PlayState)Scaleform::GFx::AS2::Value::ToObjectInterface(
                                                       (Scaleform::GFx::AS2::Value *)valBuf2,
                                                       env);
                v170 = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Value::ToFunction(
                                                       (Scaleform::GFx::AS2::Value *)nargs,
                                                       (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                                                       env);
                v91 = *(_DWORD *)&v170->T.Type == 0;
                object = v170;
                if ( v91 )
                {
                  if ( env->IsVerboseActionErrors(env) )
                    Scaleform::GFx::AS2::Environment::LogScriptError(
                      env,
                      "CallFunction - attempt to call invalid function");
                }
                else
                {
                  Scaleform::GFx::AS2::FnCall::FnCall(
                    (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                    (Scaleform::GFx::AS2::Value *)valBuf3,
                    (Scaleform::GFx::AS2::ObjectInterface *)p_Stack,
                    env,
                    (int)target,
                    env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 34);
                  p_Stack = v171;
                  (*(void (__thiscall **)(_DWORD, Scaleform::GFx::PlayState, int, _DWORD))(**(_DWORD **)&object->T.Type
                                                                                         + 40))(
                    *(_DWORD *)&object->T.Type,
                    v171,
                    object->NV.Int32Value,
                    0);
                  (**(void (__thiscall ***)(Scaleform::GFx::PlayState, _DWORD))p_Stack)(p_Stack, 0);
                }
                Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                  (Scaleform::GFx::AS2::FunctionRef *)object,
                  0);
              }
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
                &env->Stack,
                (unsigned int)&target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + 1);
              Scaleform::GFx::AS2::Value::operator=(v162->pCurrent, (const Scaleform::GFx::AS2::Value *)valBuf3);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf2, 0);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)nargs, 0);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf3, 0);
              if ( env->ThrowingValue.T.Type != 10 )
              {
                Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, execContext.PC, &tryCount);
                execContext.NextPC = Scaleform::GFx::AS2::Environment::CheckExceptions(
                                       env,
                                       pactBuf,
                                       execContext.NextPC,
                                       &tryCount,
                                       retval,
                                       execContext.WithStack.pWithStackArray,
                                       execType);
              }
LABEL_727:
              if ( Scaleform::GFx::AS2::Environment::NeedTermination(env, execType) )
                execContext.NextPC = execContext.StopPC;
LABEL_869:
              execContext.PC = execContext.NextPC;
              if ( execContext.NextPC >= execContext.StopPC )
              {
                if ( tryCount > 0 )
                {
                  for ( tc = tryCount; tc > 0; --tc )
                  {
                    Scaleform::GFx::AS2::Environment::PopTryBlock(env, &tryDescr);
                    v391 = 32 * (env->Stack.Pages.Data.Size - 1) + env->Stack.pCurrent - env->Stack.pPageStart;
                    if ( v391 > tryDescr.TopStackIndex )
                      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
                        &env->Stack,
                        v391 - tryDescr.TopStackIndex);
                    pTryBlock = tryDescr.pTryBlock;
                    if ( (*tryDescr.pTryBlock & 2) != 0 )
                    {
                      v393 = *((unsigned __int8 *)tryDescr.pTryBlock + 1);
                      v394 = *((unsigned __int8 *)tryDescr.pTryBlock + 2);
                      v395 = tryDescr.TryBeginPC + *(unsigned __int16 *)(tryDescr.pTryBlock + 3);
                      *((_BYTE *)env + 194) |= 1u;
                      execContext.PC = v395 + (v393 | (v394 << 8));
                      Scaleform::GFx::AS2::ActionBuffer::Execute(
                        pactBuf,
                        env,
                        execContext.PC,
                        *(unsigned __int16 *)(pTryBlock + 5),
                        retval,
                        execContext.WithStack.pWithStackArray,
                        execType);
                      *((_BYTE *)env + 194) &= ~1u;
                    }
                  }
                }
                goto LABEL_877;
              }
              PC = execContext.PC;
              break;
            case 0x3Eu:
              if ( retval )
                Scaleform::GFx::AS2::Value::operator=(retval, env->Stack.pCurrent);
              v172 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              if ( v172->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v172);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              goto LABEL_868;
            case 0x3Fu:
              v173 = &env->Stack;
              u = Scaleform::GFx::AS2::Value::ToNumber(env->Stack.pCurrent, env);
              v174 = env->Stack.pCurrent - 1;
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v174 = env->Stack.pPrevPageTop;
              v175 = Scaleform::GFx::AS2::Value::ToNumber(v174, env);
              if ( u == 0.0 )
                v176 = Scaleform::GFx::NumberUtil::NaN();
              else
                v176 = fmod(v175, u);
              v177 = v173->pCurrent;
              u = v176;
              if ( &v177[-2] >= env->Stack.pPageStart )
              {
                if ( v177->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v177);
                --v173->pCurrent;
                if ( v173->pCurrent->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v173->pCurrent);
                --v173->pCurrent;
              }
              else
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, 2u);
              }
              ++v173->pCurrent;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)v173->pCurrent;
              if ( p_Stack )
              {
                v178 = u;
                *(_BYTE *)p_Stack = 3;
                *(long double *)(p_Stack + 4) = v178;
              }
              goto LABEL_869;
            case 0x40u:
              v179 = &env->Stack;
              Scaleform::GFx::AS2::Value::ToStringImpl(
                env->Stack.pCurrent,
                (Scaleform::GFx::ASString *)tmpStr1Buf,
                env,
                -1,
                0);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v180 = env->Stack.pPrevPageTop;
              else
                v180 = env->Stack.pCurrent - 1;
              nargsf = Scaleform::GFx::AS2::Value::ToNumber(v180, env);
              if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(nargsf) )
                target = 0;
              else
                target = (Scaleform::GFx::InteractiveObject *)(int)nargsf;
              v181 = v179->pCurrent;
              if ( &v179->pCurrent[-2] >= env->Stack.pPageStart )
              {
                if ( v181->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v181);
                --v179->pCurrent;
                if ( v179->pCurrent->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(v179->pCurrent);
                --v179->pCurrent;
              }
              else
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, 2u);
              }
              v182 = pobj.pObject;
              if ( pobj.pObject )
              {
                v183 = pobj.pObject->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v183) != 0 )
                {
                  pobj.pObject->RefCount = v183 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v182);
                }
              }
              v184 = 0;
              valBuf1[0] = 0;
              if ( Scaleform::GFx::AS2::Environment::GetVariable(
                     env,
                     (const Scaleform::GFx::ASString *)tmpStr1Buf,
                     (Scaleform::GFx::AS2::Value *)valBuf1,
                     execContext.WithStack.pWithStackArray,
                     0,
                     0,
                     0)
                && Scaleform::GFx::AS2::Value::IsFunction((Scaleform::GFx::AS2::Value *)valBuf1) )
              {
                sceneOffset = (int)Scaleform::GFx::AS2::Value::ToFunction(
                                     (Scaleform::GFx::AS2::Value *)valBuf1,
                                     (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                                     env);
                v184 = Scaleform::GFx::AS2::Environment::OperatorNew(
                         env,
                         (const Scaleform::GFx::AS2::FunctionRef *)sceneOffset,
                         (int)target,
                         -1);
                Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                  (Scaleform::GFx::AS2::FunctionRef *)sceneOffset,
                  0);
              }
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, (unsigned int)target);
              v185 = ++v179->pCurrent;
              if ( v184 )
              {
                if ( v185 >= env->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                p_Stack = (Scaleform::GFx::PlayState)v179->pCurrent;
                if ( p_Stack )
                  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)p_Stack, v184);
                v186 = v184->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v186) != 0 )
                {
                  v184->RefCount = v186 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v184);
                }
              }
              else
              {
                valBuf2[0] = 0;
                if ( v185 >= env->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                p_Stack = (Scaleform::GFx::PlayState)v179->pCurrent;
                if ( p_Stack )
                  Scaleform::GFx::AS2::Value::Value(
                    (Scaleform::GFx::AS2::Value *)p_Stack,
                    (const Scaleform::GFx::AS2::Value *)valBuf2);
                Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf2, 0);
              }
              pobj.pObject = 0;
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              if ( env->ThrowingValue.T.Type != 10 )
              {
                Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, execContext.PC, &tryCount);
                execContext.NextPC = Scaleform::GFx::AS2::Environment::CheckExceptions(
                                       env,
                                       pactBuf,
                                       execContext.NextPC,
                                       &tryCount,
                                       retval,
                                       execContext.WithStack.pWithStackArray,
                                       execType);
              }
              goto LABEL_867;
            case 0x41u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              Scaleform::GFx::AS2::Value::ToStringImpl(
                env->Stack.pCurrent,
                (Scaleform::GFx::ASString *)tmpStr1Buf,
                env,
                -1,
                0);
              if ( (*((_BYTE *)&execContext + 54) & 4) != 0 || execType == Exec_Function )
                Scaleform::GFx::AS2::Environment::DeclareLocal(env, (const Scaleform::GFx::ASString *)tmpStr1Buf);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              goto LABEL_388;
            case 0x42u:
              v187 = &env->Stack;
              v188 = Scaleform::GFx::AS2::Value::ToNumber(env->Stack.pCurrent, env);
              v189 = env->Stack.pCurrent;
              v190 = v189->T.Type < 5u;
              target = (Scaleform::GFx::InteractiveObject *)(int)v188;
              if ( !v190 )
                Scaleform::GFx::AS2::Value::DropRefs(v189);
              --v187->pCurrent;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              val_4c = env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 32;
              valBuf1[0] = 0;
              Scaleform::GFx::AS2::FnCall::FnCall(
                (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                (Scaleform::GFx::AS2::Value *)valBuf1,
                0,
                env,
                (int)target,
                val_4c);
              v192 = v191;
              Scaleform::GFx::AS2::ArrayCtorFunction::DeclareArray(v191);
              ((void (__thiscall *)(const Scaleform::GFx::AS2::FnCall *, _DWORD))v192->~Scaleform::GFx::AS2::FnCall)(
                v192,
                0);
              if ( (int)target > 0 )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, (unsigned int)target);
              ++v187->pCurrent;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)v187->pCurrent;
              if ( p_Stack )
                Scaleform::GFx::AS2::Value::Value(
                  (Scaleform::GFx::AS2::Value *)p_Stack,
                  (const Scaleform::GFx::AS2::Value *)valBuf1);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
              goto LABEL_869;
            case 0x43u:
              v193 = &env->Stack;
              v194 = (int)Scaleform::GFx::AS2::Value::ToNumber(env->Stack.pCurrent, env);
              v195 = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                            env,
                                                            env->StringContext.pContext->pGlobal.pObject,
                                                            (const Scaleform::GFx::ASString *)&env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
                                                            0,
                                                            -1);
              v196 = pobj.pObject;
              target = v195;
              if ( pobj.pObject )
              {
                v197 = pobj.pObject->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v197) != 0 )
                {
                  pobj.pObject->RefCount = v197 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v196);
                }
              }
              if ( v193->pCurrent->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v193->pCurrent);
              --v193->pCurrent;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              if ( target && v194 > 0 )
              {
                do
                {
                  if ( (signed int)(env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 32) >= 1 )
                  {
                    if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                      v198 = env->Stack.pPrevPageTop;
                    else
                      v198 = v193->pCurrent - 1;
                    if ( v198->T.Type == 5 )
                    {
                      if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                        v199 = env->Stack.pPrevPageTop;
                      else
                        v199 = v193->pCurrent - 1;
                      Scaleform::GFx::AS2::Value::ToStringImpl(v199, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
                      valb = v193->pCurrent;
                      v428 = 0;
                      ((void (__thiscall *)(Scaleform::GFx::ASMovieRootBase **, Scaleform::GFx::AS2::Environment *, char *, Scaleform::GFx::AS2::Value *, char *))target->pASRoot->pASSupport.pObject)(
                        &target->pASRoot,
                        env,
                        tmpStr1Buf,
                        valb,
                        &v428);
                      Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
                    }
                    v200 = v193->pCurrent;
                    if ( &v193->pCurrent[-2] >= env->Stack.pPageStart )
                    {
                      if ( v200->T.Type >= 5u )
                        Scaleform::GFx::AS2::Value::DropRefs(v200);
                      --v193->pCurrent;
                      if ( v193->pCurrent->T.Type >= 5u )
                        Scaleform::GFx::AS2::Value::DropRefs(v193->pCurrent);
                      --v193->pCurrent;
                    }
                    else
                    {
                      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, 2u);
                    }
                  }
                  --v194;
                }
                while ( v194 );
              }
              ++v193->pCurrent;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)v193->pCurrent;
              v201 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)target;
              if ( p_Stack )
                Scaleform::GFx::AS2::Value::Value(
                  (Scaleform::GFx::AS2::Value *)p_Stack,
                  (Scaleform::GFx::AS2::Object *)target);
              if ( v201 )
              {
                v202 = v201->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v202) != 0 )
                {
                  v201->RefCount = v202 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v201);
                }
              }
              v91 = env->ThrowingValue.T.Type == 10;
              pobj.pObject = 0;
              if ( !v91 )
              {
                Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, execContext.PC, &tryCount);
                execContext.NextPC = Scaleform::GFx::AS2::Environment::CheckExceptions(
                                       env,
                                       pactBuf,
                                       execContext.NextPC,
                                       &tryCount,
                                       retval,
                                       execContext.WithStack.pWithStackArray,
                                       execType);
              }
              if ( Scaleform::GFx::AS2::Environment::NeedTermination(env, execType) )
                execContext.NextPC = execContext.StopPC;
              goto LABEL_869;
            case 0x44u:
              v203 = env->Stack.pCurrent;
              p_Stack = 51;
              switch ( v203->T.Type )
              {
                case 0u:
                case 0xAu:
                  break;
                case 1u:
                  p_Stack = 52;
                  break;
                case 2u:
                  p_Stack = 57;
                  break;
                case 5u:
                  p_Stack = 55;
                  break;
                case 6u:
                  goto $LN211;
                case 7u:
                  v204 = Scaleform::GFx::AS2::Value::ToCharacter(v203, env);
                  if ( !v204
                    || (v204->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
                  {
                    p_Stack = 58;
                  }
                  else
                  {
$LN211:
                    p_Stack = 59;
                  }
                  break;
                case 8u:
                  p_Stack = 60;
                  break;
                default:
                  if ( Scaleform::GFx::AS2::Value::IsNumber(v203) )
                    p_Stack = 56;
                  break;
              }
              Scaleform::GFx::AS2::Value::SetString(
                env->Stack.pCurrent,
                (const Scaleform::GFx::ASString *)&env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount
              + p_Stack);
              goto LABEL_869;
            case 0x45u:
              v205 = Scaleform::GFx::AS2::Value::ToCharacter(env->Stack.pCurrent, env);
              if ( v205 )
              {
                if ( v205->pNameHandle.pObject )
                {
                  Scaleform::GFx::AS2::Value::SetString(env->Stack.pCurrent, &v205->pNameHandle.pObject->NamePath);
                }
                else
                {
                  CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v205);
                  Scaleform::GFx::AS2::Value::SetString(env->Stack.pCurrent, &CharacterHandle->NamePath);
                }
              }
              else
              {
                Scaleform::GFx::AS2::Value::SetUndefined(env->Stack.pCurrent);
              }
              goto LABEL_869;
            case 0x46u:
            case 0x55u:
              Scaleform::GFx::AS2::ExecutionContext::EnumerateOpCode(&execContext, (Scaleform::GFx::ASString)v27);
              goto LABEL_869;
            case 0x47u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v207 = env->Stack.pCurrent;
              pPrevPageTop = v207 - 1;
              if ( v207 <= env->Stack.pPageStart )
                pPrevPageTop = env->Stack.pPrevPageTop;
LABEL_46:
              Scaleform::GFx::AS2::Value::Add(pPrevPageTop, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x49u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v208 = env->Stack.pCurrent;
              v209 = v208 - 1;
              if ( v208 > env->Stack.pPageStart )
              {
                v210 = v208 - 1;
              }
              else
              {
                v209 = env->Stack.pPrevPageTop;
                v210 = v209;
              }
              v211 = Scaleform::GFx::AS2::Value::IsEqual(v209, env, env->Stack.pCurrent);
              Scaleform::GFx::AS2::Value::SetBool(v210, v211);
              goto LABEL_855;
            case 0x4Au:
              Scaleform::GFx::AS2::Value::ConvertToNumber(env->Stack.pCurrent, env);
              goto LABEL_869;
            case 0x4Bu:
              Scaleform::GFx::AS2::Value::ConvertToStringVersioned(
                env->Stack.pCurrent,
                env,
                (Scaleform::GFx::ASStringNode *)execContext.Version);
              goto LABEL_869;
            case 0x4Cu:
              v212 = env->Stack.pCurrent;
              env->Stack.pCurrent = v212 + 1;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( p_Stack )
                Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)p_Stack, v212);
              goto LABEL_869;
            case 0x4Du:
              v213 = env->Stack.pCurrent;
              if ( v213 <= env->Stack.pPageStart )
                v214 = env->Stack.pPrevPageTop;
              else
                v214 = v213 - 1;
              Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)valBuf1, v214);
              p_Stack = v215;
              v216 = env->Stack.pCurrent;
              if ( v216 <= env->Stack.pPageStart )
                v217 = env->Stack.pPrevPageTop;
              else
                v217 = v216 - 1;
              Scaleform::GFx::AS2::Value::operator=(v217, env->Stack.pCurrent);
              Scaleform::GFx::AS2::Value::operator=(env->Stack.pCurrent, (const Scaleform::GFx::AS2::Value *)p_Stack);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)p_Stack, 0);
              goto LABEL_869;
            case 0x4Eu:
              v218 = env->Stack.pCurrent;
              if ( v218 <= env->Stack.pPageStart )
                v219 = env->Stack.pPrevPageTop;
              else
                v219 = v218 - 1;
              v220 = (Scaleform::GFx::InteractiveObject *)env->Stack.pCurrent;
              target = v220;
              nargs = (int)Scaleform::GFx::AS2::Value::ToObjectInterface(v219, env);
              if ( !nargs )
              {
                sceneOffset = (int)Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(
                                     env,
                                     (Scaleform::GFx::AS2::Value *)valBuf1,
                                     1u);
                v221 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)sceneOffset, env);
                if ( !v221
                  || (nargs = (int)&v221->Scaleform::GFx::AS2::ObjectInterface,
                      v221 == (Scaleform::GFx::AS2::Object *)-16) )
                {
                  Scaleform::GFx::AS2::Value::SetUndefined(v219);
                  Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)sceneOffset, 0);
                }
                else
                {
                  Scaleform::GFx::AS2::Value::ToStringImpl(
                    (Scaleform::GFx::AS2::Value *)v220,
                    (Scaleform::GFx::ASString *)tmpStr1Buf,
                    env,
                    -1,
                    0);
                  if ( !Scaleform::GFx::AS2::Environment::GetMember(
                          env,
                          (Scaleform::GFx::AS2::ObjectInterface *)nargs,
                          (const Scaleform::GFx::ASString *)tmpStr1Buf,
                          v219) )
                    Scaleform::GFx::AS2::Value::SetUndefined(v219);
                  Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
                  Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)sceneOffset, 0);
                }
                goto LABEL_514;
              }
              if ( !Scaleform::GFx::AS2::Value::IsNumber((Scaleform::GFx::AS2::Value *)v220)
                || (*(int (__thiscall **)(int))(*(_DWORD *)nargs + 8))(nargs) != 7 )
              {
                Scaleform::GFx::AS2::Value::ToStringImpl(
                  (Scaleform::GFx::AS2::Value *)v220,
                  (Scaleform::GFx::ASString *)tmpStr1Buf,
                  env,
                  -1,
                  0);
                if ( v219->T.Type == 6 || Scaleform::GFx::AS2::Value::IsFunction(v219) )
                {
                  v228 = Scaleform::GFx::AS2::Value::ToObject(v219, env);
                  v222 = v228;
                  if ( v228 )
                    v228->RefCount = (v228->RefCount + 1) & 0x8FFFFFFF;
                  v229 = pobj.pObject;
                  if ( pobj.pObject )
                  {
                    v230 = pobj.pObject->RefCount;
                    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v230) != 0 )
                    {
                      pobj.pObject->RefCount = v230 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v229);
                    }
                  }
                }
                else
                {
                  v222 = pobj.pObject;
                }
                Scaleform::GFx::AS2::Value::SetUndefined(v219);
                Scaleform::GFx::AS2::Environment::GetMember(
                  env,
                  (Scaleform::GFx::AS2::ObjectInterface *)nargs,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  v219);
                goto LABEL_509;
              }
              v222 = (Scaleform::GFx::AS2::Object *)(nargs - 16);
              if ( nargs != 16 )
                v222->RefCount = (v222->RefCount + 1) & 0x8FFFFFFF;
              if ( pobj.pObject )
              {
                v223 = pobj.pObject->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v223) != 0 )
                {
                  v224 = pobj.pObject;
                  pobj.pObject->RefCount = v223 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v224);
                }
              }
              v225 = (int)Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)target, env);
              if ( v225 < 0 )
              {
                Scaleform::GFx::AS2::Value::ToStringImpl(
                  (Scaleform::GFx::AS2::Value *)target,
                  (Scaleform::GFx::ASString *)tmpStr1Buf,
                  env,
                  -1,
                  0);
                if ( !(unsigned __int8)Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::GetMember(
                                         (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::GASIme,Scaleform::GFx::AS2::Environment> *)&v222->Scaleform::GFx::AS2::ObjectInterface,
                                         env,
                                         (const Scaleform::GFx::ASString *)tmpStr1Buf,
                                         v219) )
                  Scaleform::GFx::AS2::Value::SetUndefined(v219);
LABEL_509:
                Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
                goto LABEL_510;
              }
              if ( v225 >= (signed int)v222[1].RootIndex )
              {
                v227 = v219;
              }
              else
              {
                v226 = (const Scaleform::GFx::AS2::Value *)(&v222[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$ADD6DCFDE39599335059E819E3D29E57::__vftable)[v225];
                v227 = v219;
                if ( v226 )
                {
                  Scaleform::GFx::AS2::Value::operator=(v219, v226);
                  goto LABEL_510;
                }
              }
              Scaleform::GFx::AS2::Value::SetUndefined(v227);
LABEL_510:
              if ( v222 )
              {
                v231 = v222->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v231) != 0 )
                {
                  v222->RefCount = v231 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v222);
                }
              }
              pobj.pObject = 0;
LABEL_514:
              v232 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              if ( v232->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v232);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
LABEL_518:
              if ( env->ThrowingValue.T.Type != 10 )
              {
                Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, execContext.PC, &tryCount);
LABEL_223:
                execContext.NextPC = Scaleform::GFx::AS2::Environment::CheckExceptions(
                                       env,
                                       pactBuf,
                                       execContext.NextPC,
                                       &tryCount,
                                       retval,
                                       execContext.WithStack.pWithStackArray,
                                       execType);
              }
              goto LABEL_869;
            case 0x4Fu:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v233 = Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Top(&env->Stack, 2u);
              v234 = Scaleform::GFx::AS2::Value::ToObjectInterface(v233, env);
              if ( !v234 )
                goto LABEL_531;
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                nargs = (int)env->Stack.pPrevPageTop;
              else
                nargs = *(_DWORD *)p_Stack - 16;
              if ( Scaleform::GFx::AS2::Value::IsNumber((Scaleform::GFx::AS2::Value *)nargs)
                && v234->GetObjectType(v234) == Object_Array )
              {
                p_pProto = &v234[-2].pProto;
                v236 = Scaleform::GFx::AS2::Value::ToNumber((Scaleform::GFx::AS2::Value *)nargs, env);
                if ( (int)v236 >= 0 )
                {
                  Scaleform::GFx::AS2::ArrayObject::SetElementSafe(
                    (Scaleform::GFx::AS2::ArrayObject *)p_pProto,
                    (int)v236,
                    *(const Scaleform::GFx::AS2::Value **)p_Stack);
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&env->Stack);
                  goto LABEL_518;
                }
                Scaleform::GFx::AS2::Value::ToStringImpl(
                  (Scaleform::GFx::AS2::Value *)nargs,
                  (Scaleform::GFx::ASString *)tmpStr1Buf,
                  env,
                  -1,
                  0);
                valc = *(Scaleform::GFx::AS2::Value **)p_Stack;
                test = 0;
                Scaleform::GFx::AS2::Object::SetMember(
                  (Scaleform::GFx::AS2::Object *)&p_pProto[4],
                  env,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  valc,
                  (const Scaleform::GFx::AS2::PropFlags *)&test);
              }
              else
              {
                Scaleform::GFx::AS2::Value::ToStringImpl(
                  (Scaleform::GFx::AS2::Value *)nargs,
                  (Scaleform::GFx::ASString *)tmpStr1Buf,
                  env,
                  -1,
                  0);
                vald = *(Scaleform::GFx::AS2::Value **)p_Stack;
                v430 = 0;
                v234->SetMember(
                  v234,
                  env,
                  (const Scaleform::GFx::ASString *)tmpStr1Buf,
                  vald,
                  (const Scaleform::GFx::AS2::PropFlags *)&v430);
              }
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
LABEL_531:
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&env->Stack);
              goto LABEL_518;
            case 0x50u:
              Scaleform::GFx::AS2::Value::Add(env->Stack.pCurrent, env, (Scaleform::GFx::ASStringNode *)1);
              goto LABEL_869;
            case 0x51u:
              Scaleform::GFx::AS2::Value::Sub(env->Stack.pCurrent, env, 1);
              goto LABEL_869;
            case 0x52u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v237 = Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Top(&env->Stack, 2u);
              nargsf = Scaleform::GFx::AS2::Value::ToNumber(v237, env);
              if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(nargsf) )
                nargs = 0;
              else
                nargs = (int)nargsf;
              v238 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              valBuf1[0] = 0;
              Scaleform::GFx::AS2::Value::ToStringImpl(v238, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
              v239 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              object = 0;
              if ( v239 <= env->Stack.pPageStart )
                v240 = env->Stack.pPrevPageTop;
              else
                v240 = v239 - 1;
              Scaleform::GFx::AS2::ValueGuard::ValueGuard(&valStorage, env, v240);
              if ( Scaleform::GFx::AS2::Value::IsUndefined(*(Scaleform::GFx::AS2::Value **)p_Stack)
                || !*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 20) )
              {
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v273 = env->Stack.pPrevPageTop;
                else
                  v273 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)valBuf2, v273);
                v274 = pobj.pObject;
                v276 = v275;
                target = v275;
                if ( pobj.pObject )
                {
                  v277 = pobj.pObject->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v277) != 0 )
                  {
                    pobj.pObject->RefCount = v277 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v274);
                  }
                }
                valBuf3[0] = 0;
                v91 = LOBYTE(v276->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable) == 6;
                pobj.pObject = 0;
                if ( !v91 )
                  goto LABEL_606;
                v278 = Scaleform::GFx::AS2::Value::ToObject((Scaleform::GFx::AS2::Value *)target, env);
                v279 = v278;
                if ( v278 )
                  v278->RefCount = (v278->RefCount + 1) & 0x8FFFFFFF;
                pobj.pObject = v278;
                if ( v278 && v278->IsSuper(&v278->Scaleform::GFx::AS2::ObjectInterface) )
                {
                  Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)target, 0);
                  LODWORD(u) = v279->Get__constructor__(
                                 &v279->Scaleform::GFx::AS2::ObjectInterface,
                                 (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                                 &env->StringContext);
                  Scaleform::GFx::AS2::Value::Value(
                    (Scaleform::GFx::AS2::Value *)valBuf2,
                    (const Scaleform::GFx::AS2::FunctionRef *)LODWORD(u));
                  target = v280;
                  Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                    (Scaleform::GFx::AS2::FunctionRef *)LODWORD(u),
                    0);
                  Scaleform::GFx::AS2::Value::SetAsObject((Scaleform::GFx::AS2::Value *)valBuf3, v279);
                }
                else
                {
LABEL_606:
                  Scaleform::GFx::AS2::Environment::GetVariable(
                    env,
                    (const Scaleform::GFx::ASString *)&env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl,
                    (Scaleform::GFx::AS2::Value *)valBuf3,
                    execContext.WithStack.pWithStackArray,
                    0,
                    0,
                    0);
                }
                v281 = target;
                if ( Scaleform::GFx::AS2::Value::IsFunction((Scaleform::GFx::AS2::Value *)target) )
                {
                  v282 = Scaleform::GFx::AS2::Value::ToFunction(
                           (Scaleform::GFx::AS2::Value *)v281,
                           (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                           env);
                  v91 = v282->Function == 0;
                  sceneOffset = (int)v282;
                  if ( !v91 )
                  {
                    Scaleform::GFx::AS2::FnCall::FnCall(
                      (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                      (Scaleform::GFx::AS2::Value *)valBuf1,
                      (Scaleform::GFx::AS2::Value *)valBuf3,
                      env,
                      nargs,
                      env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 35);
                    v284 = v283;
                    (*(void (__thiscall **)(_DWORD, void (__thiscall ***)(_DWORD, _DWORD), _DWORD, _DWORD))(**(_DWORD **)sceneOffset + 40))(
                      *(_DWORD *)sceneOffset,
                      v283,
                      *(_DWORD *)(sceneOffset + 4),
                      0);
                    (**v284)(v284, 0);
                    v282 = (Scaleform::GFx::AS2::FunctionRef *)sceneOffset;
                  }
                  Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(v282, 0);
                  v281 = target;
                }
                Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf3, 0);
                Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)v281, 0);
                v285 = pobj.pObject;
                if ( pobj.pObject )
                {
                  v286 = pobj.pObject->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v286) != 0 )
                  {
                    pobj.pObject->RefCount = v286 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v285);
                  }
                }
                pobj.pObject = 0;
              }
              else
              {
                v241 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v241 = env->Stack.pPrevPageTop;
                if ( !Scaleform::GFx::AS2::Value::IsFunction(v241) )
                {
                  v242 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                  if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                    v242 = env->Stack.pPrevPageTop;
                  v243 = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Value::ToObjectInterface(v242, env);
                  v244 = v243;
                  object = v243;
                  if ( v243 )
                  {
                    valBuf2[0] = 0;
                    if ( (*(unsigned __int8 (__thiscall **)(Scaleform::GFx::AS2::Value *))(*(_DWORD *)&v243->T.Type + 60))(v243) )
                    {
                      target = (Scaleform::GFx::InteractiveObject *)&v244[-1];
                      if ( v244 != (Scaleform::GFx::AS2::Value *)16 )
                        *((_DWORD *)&v244[-1].NV + 3) = (*((_DWORD *)&v244[-1].NV + 3) + 1) & 0x8FFFFFFF;
                      Owner = Scaleform::GFx::AS2::ObjectInterface::FindOwner(
                                (Scaleform::GFx::AS2::ObjectInterface *)&target->pPerspectiveData->ProjectionCenter,
                                &env->StringContext,
                                (const Scaleform::GFx::ASString *)tmpStr1Buf);
                      v246 = (Scaleform::GFx::AS2::Object *)Owner;
                      if ( Owner )
                        Owner[3].pObject = (Scaleform::GFx::AS2::Object *)(((int)&Owner[3].pObject->__vftable + 1)
                                                                         & 0x8FFFFFFF);
                      if ( pobj.pObject )
                      {
                        v247 = pobj.pObject->RefCount;
                        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v247) != 0 )
                        {
                          v248 = pobj.pObject;
                          pobj.pObject->RefCount = v247 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v248);
                        }
                      }
                      pobj.pObject = v246;
                      if ( v246 )
                      {
                        Scaleform::GFx::AS2::SuperObject::SetAltProto((Scaleform::GFx::AS2::SuperObject *)target, v246);
                        v249 = v246->RefCount;
                        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v249) != 0 )
                        {
                          v246->RefCount = v249 - 1;
                          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v246);
                        }
                        pobj.pObject = 0;
                      }
                      else
                      {
                        object = 0;
                      }
                      v250 = target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
                      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & (unsigned int)v250) != 0 )
                      {
                        v251 = target;
                        target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)((char *)v250 - 1);
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v251);
                      }
                    }
                    if ( object
                      && Scaleform::GFx::AS2::Environment::GetMember(
                           env,
                           (Scaleform::GFx::AS2::ObjectInterface *)object,
                           (const Scaleform::GFx::ASString *)tmpStr1Buf,
                           (Scaleform::GFx::AS2::Value *)valBuf2)
                      && Scaleform::GFx::AS2::Value::IsFunction((Scaleform::GFx::AS2::Value *)valBuf2) )
                    {
                      v252 = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Value::ToFunction(
                                                                    (Scaleform::GFx::AS2::Value *)valBuf2,
                                                                    (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                                                                    env);
                      v91 = v252->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable == 0;
                      target = v252;
                      if ( !v91 )
                      {
                        Scaleform::GFx::AS2::FnCall::FnCall(
                          (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                          (Scaleform::GFx::AS2::Value *)valBuf1,
                          (Scaleform::GFx::AS2::ObjectInterface *)object,
                          env,
                          nargs,
                          env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 35);
                        v254 = v253;
                        v255 = target->RefCount;
                        v256 = (void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*((_DWORD *)target->~Scaleform::GFx::DisplayObjectBase
                                                                                    + 10);
                        sceneOffset = (int)target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
                        v256(sceneOffset, v254, v255, **(_DWORD **)tmpStr1Buf);
                        (**v254)(v254, 0);
                        v252 = target;
                      }
                      Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                        (Scaleform::GFx::AS2::FunctionRef *)v252,
                        0);
                    }
LABEL_581:
                    Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf2, 0);
                    goto LABEL_615;
                  }
                }
                v257 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                  v257 = env->Stack.pPrevPageTop;
                if ( Scaleform::GFx::AS2::Value::IsFunction(v257) )
                {
                  v258 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
                  if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                    v258 = env->Stack.pPrevPageTop;
                  v259 = (Scaleform::GFx::AS2::Value *)Scaleform::GFx::AS2::Value::ToObject(v258, env);
                  if ( v259 )
                  {
                    object = v259 + 1;
                    if ( v259 == (Scaleform::GFx::AS2::Value *)-16 )
                      goto LABEL_615;
                    valBuf2[0] = 0;
                    if ( Scaleform::GFx::AS2::Environment::GetMember(
                           env,
                           (Scaleform::GFx::AS2::ObjectInterface *)object,
                           (const Scaleform::GFx::ASString *)tmpStr1Buf,
                           (Scaleform::GFx::AS2::Value *)valBuf2) )
                    {
                      v260 = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Value::ToFunction(
                                                                    (Scaleform::GFx::AS2::Value *)valBuf2,
                                                                    (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                                                                    env);
                      v91 = v260->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable == 0;
                      target = v260;
                      if ( !v91 )
                      {
                        Scaleform::GFx::AS2::FnCall::FnCall(
                          (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                          (Scaleform::GFx::AS2::Value *)valBuf1,
                          v258,
                          env,
                          nargs,
                          env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 35);
                        v262 = v261;
                        v263 = target->RefCount;
                        v264 = (void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*((_DWORD *)target->~Scaleform::GFx::DisplayObjectBase
                                                                                    + 10);
                        sceneOffset = (int)target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
                        v264(sceneOffset, v262, v263, **(_DWORD **)tmpStr1Buf);
                        (**v262)(v262, 0);
                        v260 = target;
                      }
                      Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                        (Scaleform::GFx::AS2::FunctionRef *)v260,
                        0);
                    }
                    goto LABEL_581;
                  }
                  object = 0;
                }
                else
                {
                  v265 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(
                           env,
                           (Scaleform::GFx::AS2::Value *)valBuf2,
                           1u);
                  v91 = v265->T.Type == 6;
                  LODWORD(u) = v265;
                  if ( v91 )
                  {
                    v266 = Scaleform::GFx::AS2::Value::ToObject(v265, env);
                    if ( v266 )
                      v267 = &v266->Scaleform::GFx::AS2::ObjectInterface;
                    else
                      v267 = 0;
                    valBuf3[0] = 0;
                    if ( Scaleform::GFx::AS2::Environment::GetMember(
                           env,
                           v267,
                           (const Scaleform::GFx::ASString *)tmpStr1Buf,
                           (Scaleform::GFx::AS2::Value *)valBuf3)
                      && valBuf3[0] == 8 )
                    {
                      v268 = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Value::ToFunction(
                                                                    (Scaleform::GFx::AS2::Value *)valBuf3,
                                                                    (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                                                                    env);
                      v91 = v268->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable == 0;
                      target = v268;
                      if ( !v91 )
                      {
                        Scaleform::GFx::AS2::FnCall::FnCall(
                          (Scaleform::GFx::AS2::FnCall *)fnCallBuf,
                          (Scaleform::GFx::AS2::Value *)valBuf1,
                          v267,
                          env,
                          nargs,
                          env->Stack.pCurrent - env->Stack.pPageStart + 32 * env->Stack.Pages.Data.Size - 35);
                        v270 = v269;
                        v271 = target->RefCount;
                        v272 = (void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*((_DWORD *)target->~Scaleform::GFx::DisplayObjectBase
                                                                                    + 10);
                        sceneOffset = (int)target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
                        v272(sceneOffset, v270, v271, **(_DWORD **)tmpStr1Buf);
                        (**v270)(v270, 0);
                        v268 = target;
                      }
                      Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
                        (Scaleform::GFx::AS2::FunctionRef *)v268,
                        0);
                    }
                    Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf3, 0);
                    v265 = (Scaleform::GFx::AS2::Value *)LODWORD(u);
                    object = 0;
                  }
                  Scaleform::GFx::AS2::Value::`scalar deleting destructor'(v265, 0);
                }
              }
LABEL_615:
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, nargs + 2);
              Scaleform::GFx::AS2::Value::operator=(
                *(Scaleform::GFx::AS2::Value **)p_Stack,
                (const Scaleform::GFx::AS2::Value *)valBuf1);
              if ( env->ThrowingValue.T.Type != 10 )
              {
                Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, execContext.PC, &tryCount);
                execContext.NextPC = Scaleform::GFx::AS2::Environment::CheckExceptions(
                                       env,
                                       pactBuf,
                                       execContext.NextPC,
                                       &tryCount,
                                       retval,
                                       execContext.WithStack.pWithStackArray,
                                       execType);
              }
              if ( object )
              {
                v287 = Scaleform::GFx::AS2::ObjectInterface::ToCharacter((Scaleform::GFx::AS2::ObjectInterface *)object);
                if ( (!v287 || (BYTE2(v287->IsSuper) & 0x10) == 0)
                  && Scaleform::GFx::AS2::Environment::NeedTermination(env, execType) )
                {
                  execContext.NextPC = execContext.StopPC;
                }
              }
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              Scaleform::GFx::AS2::ValueGuard::~ValueGuard(&valStorage);
              goto LABEL_869;
            case 0x53u:
              v288 = &env->Stack;
              Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)valBuf1, env->Stack.pCurrent);
              v290 = v289;
              v291 = env->Stack.pCurrent;
              sceneOffset = (int)v290;
              if ( v291 <= env->Stack.pPageStart )
                v292 = env->Stack.pPrevPageTop;
              else
                v292 = v291 - 1;
              Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)valBuf2, v292);
              object = v293;
              v294 = Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Top(&env->Stack, 2u);
              nargsf = Scaleform::GFx::AS2::Value::ToNumber(v294, env);
              if ( Scaleform::GFx::NumberUtil::IsNaNOrInfinity(nargsf) )
                nargs = 0;
              else
                nargs = (int)nargsf;
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&env->Stack);
              Scaleform::GFx::AS2::Value::ToStringImpl(v290, (Scaleform::GFx::ASString *)tmpStr1Buf, env, -1, 0);
              if ( Scaleform::GFx::AS2::Value::IsUndefined(v290)
                || v290->T.Type == 5 && !*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 20) )
              {
                v296 = Scaleform::GFx::AS2::Value::ToFunction(object, (Scaleform::GFx::AS2::FunctionRef *)funcBuf, env);
                Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)valBuf3, v296);
                target = v297;
                Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(v296, 0);
              }
              else
              {
                valBuf3[0] = 0;
                target = (Scaleform::GFx::InteractiveObject *)valBuf3;
                v295 = Scaleform::GFx::AS2::Value::ToObjectInterface(object, env);
                if ( v295 )
                  Scaleform::GFx::AS2::Environment::GetMember(
                    env,
                    v295,
                    (const Scaleform::GFx::ASString *)tmpStr1Buf,
                    (Scaleform::GFx::AS2::Value *)valBuf3);
              }
              if ( Scaleform::GFx::AS2::Value::IsFunction((Scaleform::GFx::AS2::Value *)target) )
              {
                v298 = Scaleform::GFx::AS2::Value::ToFunction(
                         (Scaleform::GFx::AS2::Value *)target,
                         (Scaleform::GFx::AS2::FunctionRef *)funcBuf,
                         env);
                LODWORD(u) = Scaleform::GFx::AS2::Environment::OperatorNew(env, v298, nargs, -1);
                if ( pobj.pObject )
                {
                  v299 = pobj.pObject->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v299) != 0 )
                  {
                    v300 = pobj.pObject;
                    pobj.pObject->RefCount = v299 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v300);
                  }
                }
                pobj.pObject = (Scaleform::GFx::AS2::Object *)LODWORD(u);
                Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(v298, 0);
                v301 = pobj.pObject;
              }
              else
              {
                v302 = pobj.pObject;
                if ( pobj.pObject )
                {
                  v303 = pobj.pObject->RefCount;
                  if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v303) != 0 )
                  {
                    pobj.pObject->RefCount = v303 - 1;
                    Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v302);
                  }
                }
                v301 = 0;
              }
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, nargs);
              ++v288->pCurrent;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)v288->pCurrent;
              if ( p_Stack )
                Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)p_Stack, v301);
              if ( v301 )
              {
                v304 = v301->RefCount;
                if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v304) != 0 )
                {
                  v301->RefCount = v304 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v301);
                }
              }
              pobj.pObject = 0;
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)sceneOffset, 0);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'(object, 0);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)target, 0);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              if ( env->ThrowingValue.T.Type != 10 )
              {
                Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, execContext.PC, &tryCount);
                execContext.NextPC = Scaleform::GFx::AS2::Environment::CheckExceptions(
                                       env,
                                       pactBuf,
                                       execContext.NextPC,
                                       &tryCount,
                                       retval,
                                       execContext.WithStack.pWithStackArray,
                                       execType);
              }
              if ( Scaleform::GFx::AS2::Environment::NeedTermination(env, execType) )
                execContext.NextPC = execContext.StopPC;
              goto LABEL_869;
            case 0x54u:
              Scaleform::GFx::AS2::ExecutionContext::InstanceOfOpCode(&execContext);
              goto LABEL_869;
            case 0x60u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v305 = env->Stack.pCurrent;
              v306 = v305 - 1;
              if ( v305 <= env->Stack.pPageStart )
                v306 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::And(v306, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x61u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v307 = env->Stack.pCurrent;
              v308 = v307 - 1;
              if ( v307 <= env->Stack.pPageStart )
                v308 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Or(v308, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x62u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v309 = env->Stack.pCurrent;
              v310 = v309 - 1;
              if ( v309 <= env->Stack.pPageStart )
                v310 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Xor(v310, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x63u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v311 = env->Stack.pCurrent;
              v312 = v311 - 1;
              if ( v311 <= env->Stack.pPageStart )
                v312 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Shl(v312, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x64u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v313 = env->Stack.pCurrent;
              v314 = v313 - 1;
              if ( v313 <= env->Stack.pPageStart )
                v314 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Asr(v314, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x65u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v315 = env->Stack.pCurrent;
              v316 = v315 - 1;
              if ( v315 <= env->Stack.pPageStart )
                v316 = env->Stack.pPrevPageTop;
              Scaleform::GFx::AS2::Value::Lsr(v316, env, env->Stack.pCurrent);
              goto LABEL_855;
            case 0x66u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v317 = env->Stack.pCurrent;
              v318 = v317 - 1;
              if ( v317 <= env->Stack.pPageStart )
                v318 = env->Stack.pPrevPageTop;
              v91 = !Scaleform::GFx::AS2::Value::TypesMatch(v318, env->Stack.pCurrent);
              v319 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              v320 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              if ( v91 )
              {
                if ( v319 <= env->Stack.pPageStart )
                  v320 = env->Stack.pPrevPageTop;
                Scaleform::GFx::AS2::Value::SetBool(v320, 0);
              }
              else
              {
                if ( v319 > env->Stack.pPageStart )
                {
                  v44 = v319 - 1;
                }
                else
                {
                  v320 = env->Stack.pPrevPageTop;
                  v44 = v320;
                }
                IsEqual = Scaleform::GFx::AS2::Value::IsEqual(v320, env, *(Scaleform::GFx::AS2::Value **)p_Stack);
LABEL_59:
                Scaleform::GFx::AS2::Value::SetBool(v44, IsEqual);
              }
              goto LABEL_855;
            case 0x67u:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v321 = env->Stack.pCurrent;
              v322 = v321 - 1;
              if ( v321 <= env->Stack.pPageStart )
                v322 = env->Stack.pPrevPageTop;
              v323 = Scaleform::GFx::AS2::Value::Compare(
                       v322,
                       (Scaleform::GFx::AS2::Value *)valBuf1,
                       env,
                       env->Stack.pCurrent,
                       1);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v324 = env->Stack.pPrevPageTop;
              else
                v324 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              Scaleform::GFx::AS2::Value::operator=(v324, v323);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'(v323, 0);
              goto LABEL_869;
            case 0x68u:
              v325 = env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              v326 = v325 - 1;
              if ( v325 <= env->Stack.pPageStart )
                v326 = env->Stack.pPrevPageTop;
              v327 = Scaleform::GFx::AS2::Value::ToStringVersioned(
                       v326,
                       (Scaleform::GFx::ASString *)tmpStr1Buf,
                       env,
                       execContext.Version);
              target = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::AS2::Value::ToStringVersioned(
                                                              *(Scaleform::GFx::AS2::Value **)p_Stack,
                                                              (Scaleform::GFx::ASString *)tmpStr2Buf,
                                                              env,
                                                              execContext.Version);
              if ( env->Stack.pCurrent <= env->Stack.pPageStart )
                v328 = env->Stack.pPrevPageTop;
              else
                v328 = (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 16);
              sceneOffset = (int)v328;
              v329 = Scaleform::GFx::ASString::operator>(v327, (const Scaleform::GFx::ASString *)target);
              Scaleform::GFx::AS2::Value::SetBool((Scaleform::GFx::AS2::Value *)sceneOffset, v329);
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
              if ( env->Stack.pCurrent < env->Stack.pPageStart )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
              Scaleform::GFx::ASString::`scalar deleting destructor'(v327, 0);
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)target, 0);
              goto LABEL_869;
            case 0x69u:
              Scaleform::GFx::AS2::ExecutionContext::ExtendsOpCode(&execContext);
              goto LABEL_869;
            default:
              goto LABEL_869;
          }
        }
        sceneOffset = *(unsigned __int16 *)&execContext.pBuffer[PC + 1];
        execContext.NextPC = sceneOffset + PC + 3;
        switch ( v27 )
        {
          case 0x81u:
            if ( (*((_BYTE *)env + 194) & 2) == 0 )
            {
              v330 = env->Target;
              if ( v330 )
              {
                p_Stack = *(unsigned __int16 *)&execContext.pBuffer[PC + 3];
                v330->GotoFrame(v330, p_Stack);
              }
            }
            goto LABEL_867;
          case 0x83u:
            p_Stack = (Scaleform::GFx::PlayState)&execContext.pBuffer[PC + 3];
            v331 = (char *)(p_Stack + strlen((const char *)p_Stack) + 1);
            if ( !strncmp((const char *)p_Stack, "FSCommand:", 0xAu) )
            {
              v332 = execContext.pOriginalTarget->pASRoot->pMovieImpl->pFSCommandHandler.pObject;
              if ( v332 )
              {
                p_Stack += 10;
                v332->Callback(v332, env->Target->pASRoot->pMovieImpl, (const char *)p_Stack, v331);
              }
            }
            else
            {
              Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
                (Scaleform::GFx::AS2::MovieRoot *)env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
                v331,
                (char *)p_Stack,
                env,
                LM_None,
                0);
            }
            goto LABEL_869;
          case 0x87u:
            v333 = execContext.pBuffer[PC + 3];
            if ( (*((_BYTE *)&execContext + 54) & 4) != 0 )
            {
              val_4d = env->Stack.pCurrent;
              v334 = Scaleform::GFx::AS2::Environment::LocalRegisterPtr(env, v333);
              Scaleform::GFx::AS2::Value::operator=(v334, val_4d);
            }
            else if ( v333 <= 3 )
            {
              Scaleform::GFx::AS2::Value::operator=(&env->GlobalRegister[v333], env->Stack.pCurrent);
            }
            goto LABEL_869;
          case 0x88u:
            Scaleform::GFx::AS2::ActionBuffer::ProcessDeclDict(
              pactBuf,
              &env->StringContext,
              PC,
              execContext.NextPC,
              &execContext.LogF);
            goto LABEL_869;
          case 0x8Au:
          case 0x8Du:
            Scaleform::GFx::AS2::ExecutionContext::WaitForFrameOpCode(&execContext, pactBuf, v27);
            goto LABEL_869;
          case 0x8Bu:
            if ( execContext.pBuffer[PC + 3] )
            {
              *(_DWORD *)tmpStr1Buf = Scaleform::GFx::ASStringManager::CreateStringNode(
                                        (Scaleform::GFx::ASStringManager *)env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                        (char *)&execContext.pBuffer[PC + 3]);
              ++*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 12);
              v335 = Scaleform::GFx::AS2::Environment::FindTarget(env, (const Scaleform::GFx::ASString *)tmpStr1Buf, 0);
              if ( v335 )
                Scaleform::GFx::AS2::Environment::SetTarget(env, v335);
              else
                Scaleform::GFx::AS2::Environment::SetInvalidTarget(env, execContext.pOriginalTarget);
LABEL_388:
              Scaleform::GFx::ASString::`scalar deleting destructor'((Scaleform::GFx::ASString *)tmpStr1Buf, 0);
            }
            else
            {
              Scaleform::GFx::AS2::Environment::SetTarget(env, execContext.pOriginalTarget);
            }
            goto LABEL_869;
          case 0x8Cu:
            if ( (*((_BYTE *)env + 194) & 2) == 0 )
            {
              v336 = (env->Target->Flags & 0x400) != 0 ? (Scaleform::GFx::Sprite *)env->Target : 0;
              if ( v336 )
                Scaleform::GFx::Sprite::GotoLabeledFrame(v336, (const char *)&execContext.pBuffer[PC + 3], 0);
            }
            goto LABEL_727;
          case 0x8Eu:
            Scaleform::GFx::AS2::ExecutionContext::Function2OpCode(
              &execContext,
              (int)&savedregs,
              (int)env,
              pactBuf,
              v412,
              v413);
            goto LABEL_869;
          case 0x8Fu:
            Scaleform::GFx::AS2::Environment::CheckTryBlocks(env, PC, &tryCount);
            ++tryCount;
            v337 = (char *)env->Stack.pCurrent - (char *)env->Stack.pPageStart;
            tryDescr.pTryBlock = &execContext.pBuffer[execContext.PC + 3];
            v338 = 32 * (env->Stack.Pages.Data.Size - 1);
            tryDescr.TryBeginPC = execContext.NextPC;
            tryDescr.TopStackIndex = v338 + (v337 >> 4);
            Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &env->TryBlocks.Data,
              &tryDescr);
            goto LABEL_869;
          case 0x94u:
            if ( execContext.WithStack.pWithStackArray && execContext.WithStack.pWithStackArray->Data.Size >= 8 )
              goto $LN69_0;
            v339 = env->Stack.pCurrent;
            v340 = execContext.NextPC + *(unsigned __int16 *)&execContext.pBuffer[PC + 3];
            if ( v339->T.Type == 7 )
            {
              v341 = Scaleform::GFx::AS2::Value::ToCharacter(v339, env);
              Scaleform::GFx::AS2::WithStackEntry::WithStackEntry(&v442, v341, v340);
              Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::PushBack(&execContext.WithStack, v342);
              Scaleform::GFx::AS2::WithStackEntry::~WithStackEntry(&v442);
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
            }
            else
            {
              v343 = Scaleform::GFx::AS2::Value::ToObject(v339, env);
              Scaleform::GFx::AS2::WithStackEntry::WithStackEntry(&v443, v343, v340);
              Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::PushBack(&execContext.WithStack, v344);
              Scaleform::GFx::AS2::WithStackEntry::~WithStackEntry(&v443);
$LN69_0:
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
            }
            goto LABEL_855;
          case 0x96u:
            goto $LL68;
          case 0x99u:
            v376 = pactBuf->pBufferData.pObject;
            execContext.NextPC += (unsigned __int8)execContext.pBuffer[PC + 3]
                                | (__int16)(execContext.pBuffer[PC + 4] << 8);
            if ( execContext.NextPC < v376->BufferLen )
              goto LABEL_869;
            Scaleform::GFx::AS2::Environment::SetTarget(env, execContext.pOriginalTarget);
            v377 = pobj.pObject;
            if ( pobj.pObject )
            {
              v378 = pobj.pObject->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v378) != 0 )
              {
                pobj.pObject->RefCount = v378 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v377);
              }
            }
            execContext.pEnv->pASLogger = execContext.pPrevLog;
            execContext.LogF.__vftable = (Scaleform::GFx::AS2::ActionLogger_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
            Scaleform::GFx::AS2::ExecutionContext::WithStackHolder::~WithStackHolder(&execContext.WithStack);
            return;
          case 0x9Au:
            LOBYTE(PC) = execContext.pBuffer[PC + 3];
            p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
            Scaleform::GFx::AS2::Value::ToStringImpl(
              env->Stack.pCurrent,
              (Scaleform::GFx::ASString *)tmpStr1Buf,
              env,
              -1,
              0);
            if ( env->Stack.pCurrent <= env->Stack.pPageStart )
              v379 = env->Stack.pPrevPageTop;
            else
              v379 = env->Stack.pCurrent - 1;
            Scaleform::GFx::AS2::Value::ToStringImpl(v379, (Scaleform::GFx::ASString *)tmpStr2Buf, env, -1, 0);
            if ( !strncmp(**(const char ***)tmpStr2Buf, "FSCommand:", 0xAu) )
            {
              v380 = execContext.pOriginalTarget->pASRoot->pMovieImpl->pFSCommandHandler.pObject;
              if ( v380 )
                v380->Callback(
                  v380,
                  env->Target->pASRoot->pMovieImpl,
                  (const char *)(**(_DWORD **)tmpStr2Buf + 10),
                  **(const char ***)tmpStr1Buf);
            }
            else
            {
              target = 0;
              if ( (PC & 3) == 1 )
              {
                target = (Scaleform::GFx::InteractiveObject *)1;
              }
              else if ( (PC & 3) == 2 )
              {
                target = (Scaleform::GFx::InteractiveObject *)2;
              }
              v381 = env->Target;
              sceneOffset = (int)&buf;
              caseSensitive[0] = (unsigned int)Scaleform::GFx::DisplayObjectBase::GetVersion(v381) > 6;
              v382 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(
                       (char *)&sceneOffset,
                       PC,
                       **(char ***)tmpStr1Buf,
                       (char **)&sceneOffset,
                       caseSensitive[0]);
              if ( (PC & 0x80u) == 0 )
              {
                if ( (PC & 0x40) != 0 || v382 != -1 && !*(_BYTE *)sceneOffset )
                  Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
                    (Scaleform::GFx::AS2::MovieRoot *)env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
                    **(char ***)tmpStr1Buf,
                    **(char ***)tmpStr2Buf,
                    env,
                    (Scaleform::GFx::LoadQueueEntry::LoadMethod)target,
                    0);
              }
              else
              {
                Scaleform::GFx::AS2::MovieRoot::AddVarLoadQueueEntry(
                  (Scaleform::GFx::AS2::MovieRoot *)env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
                  **(char ***)tmpStr1Buf,
                  **(char ***)tmpStr2Buf,
                  (Scaleform::GFx::LoadQueueEntry::LoadMethod)target);
              }
            }
            v383 = *(Scaleform::GFx::AS2::Value **)p_Stack;
            if ( (Scaleform::GFx::AS2::Value *)(*(_DWORD *)p_Stack - 32) >= env->Stack.pPageStart )
            {
              if ( v383->T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(v383);
              *(_DWORD *)p_Stack -= 16;
              if ( **(_BYTE **)p_Stack >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
              *(_DWORD *)p_Stack -= 16;
            }
            else
            {
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&env->Stack, 2u);
            }
            v384 = *(Scaleform::GFx::ASStringNode **)tmpStr1Buf;
            --*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 12);
            if ( !v384->RefCount )
              Scaleform::GFx::ASStringNode::ReleaseNode(v384);
            v80 = *(char ***)tmpStr2Buf;
            goto LABEL_841;
          case 0x9Bu:
            Scaleform::GFx::AS2::ExecutionContext::Function1OpCode(
              &execContext,
              (int)&savedregs,
              p_Stack,
              pactBuf,
              v412,
              (char)v413);
            goto LABEL_869;
          case 0x9Du:
            v385 = *(_WORD *)&execContext.pBuffer[PC + 3];
            p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
            v386 = Scaleform::GFx::AS2::Value::ToBool(env->Stack.pCurrent, env);
            v387 = env->Stack.pCurrent;
            v190 = v387->T.Type < 5u;
            test = v386;
            if ( !v190 )
              Scaleform::GFx::AS2::Value::DropRefs(v387);
            *(_DWORD *)p_Stack -= 16;
            if ( env->Stack.pCurrent < env->Stack.pPageStart )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
            if ( test )
              execContext.NextPC += v385;
            goto LABEL_869;
          case 0x9Eu:
            v91 = (*((_BYTE *)env + 194) & 2) == 0;
            sceneOffset = (int)env->Target;
            if ( !v91 )
              goto LABEL_869;
            p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
            v401 = (Scaleform::GFx::ASStringNode *)env->Stack.pCurrent;
            target = 0;
            if ( Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(
                   pactBuf,
                   env,
                   v401,
                   (Scaleform::GFx::InteractiveObject **)&sceneOffset,
                   (unsigned int *)&target)
              && ((*(_WORD *)(sceneOffset + 62) & 0x400) != 0 ? sceneOffset : 0) != 0 )
            {
              Scaleform::GFx::AS2::AvmSprite::CallFrameActions(
                (Scaleform::GFx::AS2::AvmSprite *)(((*(_WORD *)(sceneOffset + 62) & 0x400) != 0 ? sceneOffset : 0)
                                                 + 4
                                                 * *(unsigned __int8 *)((*(_WORD *)(sceneOffset + 62) & 0x400) != 0
                                                                      ? sceneOffset + 0x41
                                                                      : 65)),
                (unsigned int)target);
            }
LABEL_855:
            if ( **(_BYTE **)p_Stack >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(*(Scaleform::GFx::AS2::Value **)p_Stack);
            *(_DWORD *)p_Stack -= 16;
            if ( *(_DWORD *)p_Stack < *(_DWORD *)(p_Stack + 4) )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)p_Stack);
            goto LABEL_869;
          case 0x9Fu:
            v388 = execContext.pBuffer[PC + 3];
            p_Stack = (v388 & 1) == 0;
            sceneOffset = 0;
            if ( (v388 & 2) != 0 )
              sceneOffset = *(unsigned __int16 *)&execContext.pBuffer[PC + 4];
            v389 = (Scaleform::GFx::ASStringNode *)env->Stack.pCurrent;
            target = env->Target;
            v390 = &env->Stack;
            tc = 0;
            if ( Scaleform::GFx::AS2::ActionBuffer::ResolveFrameNumber(pactBuf, env, v389, &target, (unsigned int *)&tc) )
            {
              target->GotoFrame(target, sceneOffset + tc);
              target->SetPlayState(target, p_Stack);
            }
            if ( v390->pCurrent->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(v390->pCurrent);
            --v390->pCurrent;
            if ( env->Stack.pCurrent < env->Stack.pPageStart )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&env->Stack);
LABEL_867:
            if ( Scaleform::GFx::AS2::Environment::NeedTermination(env, execType) )
LABEL_868:
              execContext.NextPC = execContext.StopPC;
            goto LABEL_869;
          default:
            goto LABEL_869;
        }
        while ( 1 )
        {
$LL68:
          v345 = execContext.pBuffer[PC + 3];
          ++PC;
          switch ( v345 )
          {
            case 4:
              v346 = execContext.pBuffer[PC + 3];
              ++PC;
              LODWORD(u) = v346;
              if ( (*((_BYTE *)&execContext + 54) & 4) != 0 )
              {
                v347 = Scaleform::GFx::AS2::Environment::LocalRegisterPtr(env, v346);
                ++env->Stack.pCurrent;
                LODWORD(u) = v347;
                if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
                if ( p_Stack )
                  Scaleform::GFx::AS2::Value::Value(
                    (Scaleform::GFx::AS2::Value *)p_Stack,
                    (const Scaleform::GFx::AS2::Value *)LODWORD(u));
              }
              else
              {
                ++env->Stack.pCurrent;
                p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
                if ( v346 > 3 )
                {
                  v348 = *(Scaleform::GFx::AS2::Value **)p_Stack;
                  valBuf1[0] = 0;
                  if ( v348 >= env->Stack.pPageEnd )
                    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                  v349 = *(Scaleform::GFx::AS2::Value **)p_Stack;
                  if ( *(_DWORD *)p_Stack )
                    goto LABEL_761;
                  goto LABEL_762;
                }
                if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                {
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                  v346 = LODWORD(u);
                }
                p_Stack = *(_DWORD *)p_Stack;
                if ( p_Stack )
                  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)p_Stack, &env->GlobalRegister[v346]);
              }
              break;
            case 8:
              v350 = execContext.pBuffer[PC + 3];
              ++PC;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              if ( v350 < pactBuf->Dictionary.Data.Size )
              {
                Data = pactBuf->Dictionary.Data.Data;
                *(_DWORD *)p_Stack += 16;
                v352 = &Data[v350];
                v353 = *(Scaleform::GFx::AS2::Value **)p_Stack;
                LODWORD(u) = v352;
                if ( v353 >= env->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                p_Stack = *(_DWORD *)p_Stack;
                if ( p_Stack )
                {
                  v354 = (int *)LODWORD(u);
                  *(_BYTE *)p_Stack = 5;
                  v355 = *v354;
                  *(_DWORD *)(p_Stack + 4) = v355;
                  ++*(_DWORD *)(v355 + 12);
                }
                break;
              }
              *(_DWORD *)p_Stack += 16;
              v356 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              valBuf1[0] = 0;
              if ( v356 >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              v349 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              if ( *(_DWORD *)p_Stack )
LABEL_761:
                Scaleform::GFx::AS2::Value::Value(v349, (const Scaleform::GFx::AS2::Value *)valBuf1);
LABEL_762:
              if ( valBuf1[0] >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)valBuf1);
              break;
            case 0:
              *(_DWORD *)tmpStr1Buf = Scaleform::GFx::ASStringManager::CreateStringNode(
                                        (Scaleform::GFx::ASStringManager *)env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                        (char *)&execContext.pBuffer[PC + 3]);
              ++*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 12);
              v357 = *(_DWORD *)(*(_DWORD *)tmpStr1Buf + 20);
              ++env->Stack.pCurrent;
              PC += v357 + 1;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( p_Stack )
              {
                *(_BYTE *)p_Stack = 5;
                *(_DWORD *)(p_Stack + 4) = *(_DWORD *)tmpStr1Buf;
                ++*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 12);
              }
              v358 = *(Scaleform::GFx::ASStringNode **)tmpStr1Buf;
              --*(_DWORD *)(*(_DWORD *)tmpStr1Buf + 12);
              if ( !v358->RefCount )
                Scaleform::GFx::ASStringNode::ReleaseNode(v358);
              break;
            case 1:
              v359 = *(_DWORD *)&execContext.pBuffer[PC + 3];
              v360 = ++env->Stack.pCurrent;
              PC += 4;
              LODWORD(u) = v359;
              if ( v360 >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( p_Stack )
              {
                v361 = *(float *)&u;
                *(_BYTE *)p_Stack = 3;
                *(double *)(p_Stack + 4) = v361;
              }
              break;
            case 2:
              valBuf1[0] = 0;
              Scaleform::GFx::AS2::Value::SetNull((Scaleform::GFx::AS2::Value *)valBuf1);
              ++env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              v362 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              if ( *(_DWORD *)p_Stack )
                goto LABEL_806;
              goto LABEL_807;
            case 3:
              goto LABEL_803;
            case 5:
              test = execContext.pBuffer[PC + 3] != 0;
              ++env->Stack.pCurrent;
              ++PC;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( p_Stack )
              {
                v363 = test;
                *(_BYTE *)p_Stack = 2;
                *(_BYTE *)(p_Stack + 4) = v363;
              }
              break;
            case 6:
              LODWORD(v364) = *(_DWORD *)&execContext.pBuffer[PC + 7];
              HIDWORD(v364) = *(_DWORD *)&execContext.pBuffer[PC + 3];
              ++env->Stack.pCurrent;
              v441 = v364;
              PC += 8;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
              if ( p_Stack )
              {
                v365 = v441;
                *(_BYTE *)p_Stack = 3;
                *(double *)(p_Stack + 4) = v365;
              }
              break;
            case 7:
              v366 = execContext.pBuffer[PC + 6];
              v367 = execContext.pBuffer[PC + 5];
              v368 = execContext.pBuffer[PC + 4];
              v369 = execContext.pBuffer[PC + 3];
              ++env->Stack.pCurrent;
              p_Stack = v369 | ((v368 | ((v367 | (v366 << 8)) << 8)) << 8);
              PC += 4;
              if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              v370 = env->Stack.pCurrent;
              if ( v370 )
              {
                v370->T.Type = 4;
                v370->NV.Int32Value = p_Stack;
              }
              break;
            case 9:
              v371 = *(unsigned __int16 *)&execContext.pBuffer[PC + 3];
              PC += 2;
              if ( v371 < pactBuf->Dictionary.Data.Size )
              {
                v372 = pactBuf->Dictionary.Data.Data;
                ++env->Stack.pCurrent;
                LODWORD(u) = &v372[v371];
                if ( env->Stack.pCurrent >= env->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
                p_Stack = (Scaleform::GFx::PlayState)env->Stack.pCurrent;
                if ( p_Stack )
                {
                  v373 = (int *)LODWORD(u);
                  *(_BYTE *)p_Stack = 5;
                  v374 = *v373;
                  *(_DWORD *)(p_Stack + 4) = *v373;
                  ++*(_DWORD *)(v374 + 12);
                }
                break;
              }
LABEL_803:
              v375 = ++env->Stack.pCurrent;
              p_Stack = (Scaleform::GFx::PlayState)&env->Stack;
              valBuf1[0] = 0;
              if ( v375 >= env->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&env->Stack);
              v362 = *(Scaleform::GFx::AS2::Value **)p_Stack;
              if ( *(_DWORD *)p_Stack )
LABEL_806:
                Scaleform::GFx::AS2::Value::Value(v362, (const Scaleform::GFx::AS2::Value *)valBuf1);
LABEL_807:
              Scaleform::GFx::AS2::Value::`scalar deleting destructor'((Scaleform::GFx::AS2::Value *)valBuf1, 0);
              break;
          }
          if ( PC - execContext.PC >= sceneOffset )
            goto LABEL_869;
        }
      }
LABEL_877:
      v91 = env->ExecutionNestingLevel-- == 1;
      if ( v91 && env->ThrowingValue.T.Type != 10 )
      {
        Scaleform::GFx::AS2::Value::DropRefs(&env->ThrowingValue);
        env->ThrowingValue.T.Type = 10;
        *((_BYTE *)env + 194) &= ~1u;
      }
      v91 = !isOriginalTargetValid;
      pOriginalTarget = execContext.pOriginalTarget;
      env->Target = execContext.pOriginalTarget;
      if ( v91 )
        *((_BYTE *)env + 194) |= 2u;
      else
        *((_BYTE *)env + 194) &= ~2u;
      Version = Scaleform::GFx::DisplayObjectBase::GetVersion(pOriginalTarget);
      v398 = pobj.pObject;
      env->StringContext.SWFVersion = Version;
      if ( v398 )
      {
        v399 = v398->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v399) != 0 )
        {
          v398->RefCount = v399 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v398);
        }
      }
      execContext.pEnv->pASLogger = execContext.pPrevLog;
      execContext.LogF.__vftable = (Scaleform::GFx::AS2::ActionLogger_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
      if ( execContext.WithStack.pWithStackArray )
      {
        v400 = execContext.WithStack.pWithStackArray;
        Scaleform::Memory::pGlobalHeap->Free(
          Scaleform::Memory::pGlobalHeap,
          execContext.WithStack.pWithStackArray->Data.Data);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v400);
      }
    }
  }
}
