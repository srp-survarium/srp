void __usercall survarium::swf_input_translator::initialize(
        survarium::swf_input_translator *this@<ecx>,
        stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *a2@<esi>)
{
  stlp_std::less<enum vostok::input::enum_keyboard> *v2; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v3; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v4; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v5; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v6; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v7; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v8; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v9; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v10; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v11; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v12; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v13; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v14; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v15; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v16; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v17; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v18; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v19; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v20; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v21; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v22; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v23; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v24; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v25; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v26; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v27; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v28; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v29; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v30; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v31; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v32; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v33; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v34; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v35; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v36; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v37; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v38; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v39; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v40; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v41; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v42; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v43; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v44; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v45; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v46; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v47; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v48; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v49; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v50; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v51; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v52; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v53; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v54; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v55; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v56; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v57; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v58; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v59; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v60; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v61; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v62; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v63; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v64; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v65; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v66; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v67; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v68; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v69; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v70; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v71; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v72; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v73; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v74; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v75; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v76; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v77; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v78; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v79; // eax
  stlp_std::less<enum vostok::input::enum_keyboard> *v80; // eax
  vostok::input::enum_keyboard __k; // [esp+10h] [ebp-4h] BYREF

  __k = key_0;
  v2 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v2->gap0 = 11;
  *(_WORD *)&v2[4].gap0 = 48;
  *(_WORD *)&v2[6].gap0 = 41;
  *(_DWORD *)&v2[8].gap0 = 48;
  v2[12].gap0 = 1;
  v2[13].gap0 = 1;
  __k = key_numpad0;
  v3 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v3->gap0 = 82;
  *(_WORD *)&v3[4].gap0 = 48;
  *(_WORD *)&v3[6].gap0 = 48;
  *(_DWORD *)&v3[8].gap0 = 96;
  v3[12].gap0 = 0;
  v3[13].gap0 = 1;
  __k = key_1;
  v4 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v4->gap0 = 2;
  *(_WORD *)&v4[4].gap0 = 49;
  *(_WORD *)&v4[6].gap0 = 33;
  *(_DWORD *)&v4[8].gap0 = 49;
  v4[12].gap0 = 1;
  v4[13].gap0 = 1;
  __k = key_numpad1;
  v5 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v5->gap0 = 79;
  *(_WORD *)&v5[4].gap0 = 49;
  *(_WORD *)&v5[6].gap0 = 49;
  *(_DWORD *)&v5[8].gap0 = 97;
  v5[12].gap0 = 0;
  v5[13].gap0 = 1;
  __k = key_2;
  v6 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v6->gap0 = 3;
  *(_WORD *)&v6[4].gap0 = 50;
  *(_WORD *)&v6[6].gap0 = 64;
  *(_DWORD *)&v6[8].gap0 = 50;
  v6[12].gap0 = 1;
  v6[13].gap0 = 1;
  __k = key_numpad2;
  v7 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v7->gap0 = 80;
  *(_WORD *)&v7[4].gap0 = 50;
  *(_WORD *)&v7[6].gap0 = 50;
  *(_DWORD *)&v7[8].gap0 = 98;
  v7[12].gap0 = 0;
  v7[13].gap0 = 1;
  __k = key_3;
  v8 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v8->gap0 = 4;
  *(_WORD *)&v8[4].gap0 = 51;
  *(_WORD *)&v8[6].gap0 = 35;
  *(_DWORD *)&v8[8].gap0 = 51;
  v8[12].gap0 = 1;
  v8[13].gap0 = 1;
  __k = key_numpad3;
  v9 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &__k);
  *(_DWORD *)&v9->gap0 = 81;
  *(_WORD *)&v9[4].gap0 = 51;
  *(_WORD *)&v9[6].gap0 = 51;
  *(_DWORD *)&v9[8].gap0 = 99;
  v9[12].gap0 = 0;
  v9[13].gap0 = 1;
  __k = key_4;
  v10 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v10->gap0 = 5;
  *(_WORD *)&v10[4].gap0 = 52;
  *(_WORD *)&v10[6].gap0 = 36;
  *(_DWORD *)&v10[8].gap0 = 52;
  v10[12].gap0 = 1;
  v10[13].gap0 = 1;
  __k = key_numpad4;
  v11 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v11->gap0 = 75;
  *(_WORD *)&v11[4].gap0 = 52;
  *(_WORD *)&v11[6].gap0 = 52;
  *(_DWORD *)&v11[8].gap0 = 100;
  v11[12].gap0 = 0;
  v11[13].gap0 = 1;
  __k = key_5;
  v12 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v12->gap0 = 6;
  *(_WORD *)&v12[4].gap0 = 53;
  *(_WORD *)&v12[6].gap0 = 37;
  *(_DWORD *)&v12[8].gap0 = 53;
  v12[12].gap0 = 1;
  v12[13].gap0 = 1;
  __k = key_numpad5;
  v13 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v13->gap0 = 76;
  *(_WORD *)&v13[4].gap0 = 53;
  *(_WORD *)&v13[6].gap0 = 53;
  *(_DWORD *)&v13[8].gap0 = 101;
  v13[12].gap0 = 0;
  v13[13].gap0 = 1;
  __k = key_6;
  v14 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v14->gap0 = 7;
  *(_WORD *)&v14[4].gap0 = 54;
  *(_WORD *)&v14[6].gap0 = 94;
  *(_DWORD *)&v14[8].gap0 = 54;
  v14[12].gap0 = 1;
  v14[13].gap0 = 1;
  __k = key_numpad6;
  v15 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v15->gap0 = 77;
  *(_WORD *)&v15[4].gap0 = 54;
  *(_WORD *)&v15[6].gap0 = 54;
  *(_DWORD *)&v15[8].gap0 = 102;
  v15[12].gap0 = 0;
  v15[13].gap0 = 1;
  __k = key_7;
  v16 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v16->gap0 = 8;
  *(_WORD *)&v16[4].gap0 = 55;
  *(_WORD *)&v16[6].gap0 = 38;
  *(_DWORD *)&v16[8].gap0 = 55;
  v16[12].gap0 = 1;
  v16[13].gap0 = 1;
  __k = key_numpad7;
  v17 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v17->gap0 = 71;
  *(_WORD *)&v17[4].gap0 = 55;
  *(_WORD *)&v17[6].gap0 = 55;
  *(_DWORD *)&v17[8].gap0 = 103;
  v17[12].gap0 = 0;
  v17[13].gap0 = 1;
  __k = key_8;
  v18 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v18->gap0 = 9;
  *(_WORD *)&v18[4].gap0 = 56;
  *(_WORD *)&v18[6].gap0 = 42;
  *(_DWORD *)&v18[8].gap0 = 56;
  v18[12].gap0 = 1;
  v18[13].gap0 = 1;
  __k = key_numpad8;
  v19 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v19->gap0 = 72;
  *(_WORD *)&v19[4].gap0 = 56;
  *(_WORD *)&v19[6].gap0 = 56;
  *(_DWORD *)&v19[8].gap0 = 104;
  v19[12].gap0 = 0;
  v19[13].gap0 = 1;
  __k = key_9;
  v20 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v20->gap0 = 10;
  *(_WORD *)&v20[4].gap0 = 57;
  *(_WORD *)&v20[6].gap0 = 40;
  *(_DWORD *)&v20[8].gap0 = 57;
  v20[12].gap0 = 1;
  v20[13].gap0 = 1;
  __k = key_numpad9;
  v21 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v21->gap0 = 73;
  *(_WORD *)&v21[4].gap0 = 57;
  *(_WORD *)&v21[6].gap0 = 57;
  *(_DWORD *)&v21[8].gap0 = 105;
  v21[12].gap0 = 0;
  v21[13].gap0 = 1;
  __k = key_minus;
  v22 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v22->gap0 = 12;
  *(_WORD *)&v22[4].gap0 = 45;
  *(_WORD *)&v22[6].gap0 = 95;
  *(_DWORD *)&v22[8].gap0 = 189;
  v22[12].gap0 = 0;
  v22[13].gap0 = 1;
  __k = key_space;
  v23 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v23->gap0 = 57;
  *(_WORD *)&v23[4].gap0 = 32;
  *(_WORD *)&v23[6].gap0 = 32;
  *(_DWORD *)&v23[8].gap0 = 32;
  v23[12].gap0 = 0;
  v23[13].gap0 = 1;
  __k = key_backslash;
  v24 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v24->gap0 = 43;
  *(_WORD *)&v24[4].gap0 = 92;
  *(_WORD *)&v24[6].gap0 = 124;
  *(_DWORD *)&v24[8].gap0 = 220;
  v24[12].gap0 = 1;
  v24[13].gap0 = 1;
  __k = key_lbracket;
  v25 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v25->gap0 = 26;
  *(_WORD *)&v25[4].gap0 = 91;
  *(_WORD *)&v25[6].gap0 = 123;
  *(_DWORD *)&v25[8].gap0 = 219;
  v25[12].gap0 = 1;
  v25[13].gap0 = 1;
  __k = key_rbracket;
  v26 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v26->gap0 = 27;
  *(_WORD *)&v26[4].gap0 = 93;
  *(_WORD *)&v26[6].gap0 = 125;
  *(_DWORD *)&v26[8].gap0 = 221;
  v26[12].gap0 = 1;
  v26[13].gap0 = 1;
  __k = key_apostrophe;
  v27 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v27->gap0 = 40;
  *(_WORD *)&v27[4].gap0 = 39;
  *(_WORD *)&v27[6].gap0 = 34;
  *(_DWORD *)&v27[8].gap0 = 220;
  v27[12].gap0 = 1;
  v27[13].gap0 = 1;
  __k = key_comma;
  v28 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v28->gap0 = 51;
  *(_WORD *)&v28[4].gap0 = 44;
  *(_WORD *)&v28[6].gap0 = 60;
  *(_DWORD *)&v28[8].gap0 = 188;
  v28[12].gap0 = 1;
  v28[13].gap0 = 1;
  __k = key_period;
  v29 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v29->gap0 = 52;
  *(_WORD *)&v29[4].gap0 = 46;
  *(_WORD *)&v29[6].gap0 = 62;
  *(_DWORD *)&v29[8].gap0 = 190;
  v29[12].gap0 = 1;
  v29[13].gap0 = 1;
  __k = key_equals;
  v30 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v30->gap0 = 13;
  *(_WORD *)&v30[4].gap0 = 61;
  *(_WORD *)&v30[6].gap0 = 43;
  *(_DWORD *)&v30[8].gap0 = 187;
  v30[12].gap0 = 0;
  v30[13].gap0 = 1;
  __k = key_semicolon;
  v31 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v31->gap0 = 39;
  *(_WORD *)&v31[4].gap0 = 59;
  *(_WORD *)&v31[6].gap0 = 58;
  *(_DWORD *)&v31[8].gap0 = 186;
  v31[12].gap0 = 1;
  v31[13].gap0 = 1;
  __k = key_slash;
  v32 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v32->gap0 = 53;
  *(_WORD *)&v32[4].gap0 = 47;
  *(_WORD *)&v32[6].gap0 = 63;
  *(_DWORD *)&v32[8].gap0 = 191;
  v32[12].gap0 = 1;
  v32[13].gap0 = 1;
  __k = key_a;
  v33 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v33->gap0 = 30;
  *(_WORD *)&v33[4].gap0 = 0;
  *(_WORD *)&v33[6].gap0 = 0;
  *(_DWORD *)&v33[8].gap0 = 65;
  v33[12].gap0 = 1;
  v33[13].gap0 = 1;
  __k = key_b;
  v34 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v34->gap0 = 48;
  *(_WORD *)&v34[4].gap0 = 0;
  *(_WORD *)&v34[6].gap0 = 0;
  *(_DWORD *)&v34[8].gap0 = 66;
  v34[12].gap0 = 1;
  v34[13].gap0 = 1;
  __k = key_c;
  v35 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v35->gap0 = 46;
  *(_WORD *)&v35[4].gap0 = 0;
  *(_WORD *)&v35[6].gap0 = 0;
  *(_DWORD *)&v35[8].gap0 = 67;
  v35[12].gap0 = 1;
  v35[13].gap0 = 1;
  __k = key_d;
  v36 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v36->gap0 = 32;
  *(_WORD *)&v36[4].gap0 = 0;
  *(_WORD *)&v36[6].gap0 = 0;
  *(_DWORD *)&v36[8].gap0 = 68;
  v36[12].gap0 = 1;
  v36[13].gap0 = 1;
  __k = key_e;
  v37 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v37->gap0 = 18;
  *(_WORD *)&v37[4].gap0 = 0;
  *(_WORD *)&v37[6].gap0 = 0;
  *(_DWORD *)&v37[8].gap0 = 69;
  v37[12].gap0 = 1;
  v37[13].gap0 = 1;
  __k = key_f;
  v38 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v38->gap0 = 33;
  *(_WORD *)&v38[4].gap0 = 0;
  *(_WORD *)&v38[6].gap0 = 0;
  *(_DWORD *)&v38[8].gap0 = 70;
  v38[12].gap0 = 1;
  v38[13].gap0 = 1;
  __k = key_g;
  v39 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v39->gap0 = 34;
  *(_WORD *)&v39[4].gap0 = 0;
  *(_WORD *)&v39[6].gap0 = 0;
  *(_DWORD *)&v39[8].gap0 = 71;
  v39[12].gap0 = 1;
  v39[13].gap0 = 1;
  __k = key_h;
  v40 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v40->gap0 = 35;
  *(_WORD *)&v40[4].gap0 = 0;
  *(_WORD *)&v40[6].gap0 = 0;
  *(_DWORD *)&v40[8].gap0 = 72;
  v40[12].gap0 = 1;
  v40[13].gap0 = 1;
  __k = key_i;
  v41 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v41->gap0 = 23;
  *(_WORD *)&v41[4].gap0 = 0;
  *(_WORD *)&v41[6].gap0 = 0;
  *(_DWORD *)&v41[8].gap0 = 73;
  v41[12].gap0 = 1;
  v41[13].gap0 = 1;
  __k = key_j;
  v42 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v42->gap0 = 36;
  *(_WORD *)&v42[4].gap0 = 0;
  *(_WORD *)&v42[6].gap0 = 0;
  *(_DWORD *)&v42[8].gap0 = 74;
  v42[12].gap0 = 1;
  v42[13].gap0 = 1;
  __k = key_k;
  v43 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v43->gap0 = 37;
  *(_WORD *)&v43[4].gap0 = 0;
  *(_WORD *)&v43[6].gap0 = 0;
  *(_DWORD *)&v43[8].gap0 = 75;
  v43[12].gap0 = 1;
  v43[13].gap0 = 1;
  __k = key_l;
  v44 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v44->gap0 = 38;
  *(_WORD *)&v44[4].gap0 = 0;
  *(_WORD *)&v44[6].gap0 = 0;
  *(_DWORD *)&v44[8].gap0 = 76;
  v44[12].gap0 = 1;
  v44[13].gap0 = 1;
  __k = key_m;
  v45 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v45->gap0 = 50;
  *(_WORD *)&v45[4].gap0 = 0;
  *(_WORD *)&v45[6].gap0 = 0;
  *(_DWORD *)&v45[8].gap0 = 77;
  v45[12].gap0 = 1;
  v45[13].gap0 = 1;
  __k = key_n;
  v46 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v46->gap0 = 49;
  *(_WORD *)&v46[4].gap0 = 0;
  *(_WORD *)&v46[6].gap0 = 0;
  *(_DWORD *)&v46[8].gap0 = 78;
  v46[12].gap0 = 1;
  v46[13].gap0 = 1;
  __k = key_o;
  v47 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v47->gap0 = 24;
  *(_WORD *)&v47[4].gap0 = 0;
  *(_WORD *)&v47[6].gap0 = 0;
  *(_DWORD *)&v47[8].gap0 = 79;
  v47[12].gap0 = 1;
  v47[13].gap0 = 1;
  __k = key_p;
  v48 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v48->gap0 = 25;
  *(_WORD *)&v48[4].gap0 = 0;
  *(_WORD *)&v48[6].gap0 = 0;
  *(_DWORD *)&v48[8].gap0 = 80;
  v48[12].gap0 = 1;
  v48[13].gap0 = 1;
  __k = key_q;
  v49 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v49->gap0 = 16;
  *(_WORD *)&v49[4].gap0 = 0;
  *(_WORD *)&v49[6].gap0 = 0;
  *(_DWORD *)&v49[8].gap0 = 81;
  v49[12].gap0 = 1;
  v49[13].gap0 = 1;
  __k = key_r;
  v50 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v50->gap0 = 19;
  *(_WORD *)&v50[4].gap0 = 0;
  *(_WORD *)&v50[6].gap0 = 0;
  *(_DWORD *)&v50[8].gap0 = 82;
  v50[12].gap0 = 1;
  v50[13].gap0 = 1;
  __k = key_s;
  v51 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v51->gap0 = 31;
  *(_WORD *)&v51[4].gap0 = 0;
  *(_WORD *)&v51[6].gap0 = 0;
  *(_DWORD *)&v51[8].gap0 = 83;
  v51[12].gap0 = 1;
  v51[13].gap0 = 1;
  __k = key_t;
  v52 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v52->gap0 = 20;
  *(_WORD *)&v52[4].gap0 = 0;
  *(_WORD *)&v52[6].gap0 = 0;
  *(_DWORD *)&v52[8].gap0 = 84;
  v52[12].gap0 = 1;
  v52[13].gap0 = 1;
  __k = key_u;
  v53 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v53->gap0 = 22;
  *(_WORD *)&v53[4].gap0 = 0;
  *(_WORD *)&v53[6].gap0 = 0;
  *(_DWORD *)&v53[8].gap0 = 85;
  v53[12].gap0 = 1;
  v53[13].gap0 = 1;
  __k = key_v;
  v54 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v54->gap0 = 47;
  *(_WORD *)&v54[4].gap0 = 0;
  *(_WORD *)&v54[6].gap0 = 0;
  *(_DWORD *)&v54[8].gap0 = 86;
  v54[12].gap0 = 1;
  v54[13].gap0 = 1;
  __k = key_w;
  v55 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v55->gap0 = 17;
  *(_WORD *)&v55[4].gap0 = 0;
  *(_WORD *)&v55[6].gap0 = 0;
  *(_DWORD *)&v55[8].gap0 = 87;
  v55[12].gap0 = 1;
  v55[13].gap0 = 1;
  __k = key_x;
  v56 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v56->gap0 = 45;
  *(_WORD *)&v56[4].gap0 = 0;
  *(_WORD *)&v56[6].gap0 = 0;
  *(_DWORD *)&v56[8].gap0 = 88;
  v56[12].gap0 = 1;
  v56[13].gap0 = 1;
  __k = key_y;
  v57 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v57->gap0 = 21;
  *(_WORD *)&v57[4].gap0 = 0;
  *(_WORD *)&v57[6].gap0 = 0;
  *(_DWORD *)&v57[8].gap0 = 89;
  v57[12].gap0 = 1;
  v57[13].gap0 = 1;
  __k = key_z;
  v58 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v58->gap0 = 44;
  *(_WORD *)&v58[4].gap0 = 0;
  *(_WORD *)&v58[6].gap0 = 0;
  *(_DWORD *)&v58[8].gap0 = 90;
  v58[12].gap0 = 1;
  v58[13].gap0 = 1;
  __k = key_delete;
  v59 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v59->gap0 = 211;
  *(_WORD *)&v59[4].gap0 = 0;
  *(_WORD *)&v59[6].gap0 = 0;
  *(_DWORD *)&v59[8].gap0 = 46;
  v59[12].gap0 = 0;
  v59[13].gap0 = 0;
  __k = key_escape;
  v60 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v60->gap0 = 1;
  *(_WORD *)&v60[4].gap0 = 0;
  *(_WORD *)&v60[6].gap0 = 0;
  *(_DWORD *)&v60[8].gap0 = 27;
  v60[12].gap0 = 0;
  v60[13].gap0 = 0;
  __k = key_back;
  v61 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v61->gap0 = 14;
  *(_WORD *)&v61[4].gap0 = 0;
  *(_WORD *)&v61[6].gap0 = 0;
  *(_DWORD *)&v61[8].gap0 = 8;
  v61[12].gap0 = 0;
  v61[13].gap0 = 0;
  __k = key_insert;
  v62 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v62->gap0 = 210;
  *(_WORD *)&v62[4].gap0 = 0;
  *(_WORD *)&v62[6].gap0 = 0;
  *(_DWORD *)&v62[8].gap0 = 45;
  v62[12].gap0 = 0;
  v62[13].gap0 = 0;
  __k = key_return;
  v63 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v63->gap0 = 28;
  *(_WORD *)&v63[4].gap0 = 0;
  *(_WORD *)&v63[6].gap0 = 0;
  *(_DWORD *)&v63[8].gap0 = 13;
  v63[12].gap0 = 0;
  v63[13].gap0 = 0;
  __k = key_left;
  v64 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v64->gap0 = 203;
  *(_WORD *)&v64[4].gap0 = 0;
  *(_WORD *)&v64[6].gap0 = 0;
  *(_DWORD *)&v64[8].gap0 = 37;
  v64[12].gap0 = 0;
  v64[13].gap0 = 0;
  __k = key_right;
  v65 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v65->gap0 = 205;
  *(_WORD *)&v65[4].gap0 = 0;
  *(_WORD *)&v65[6].gap0 = 0;
  *(_DWORD *)&v65[8].gap0 = 39;
  v65[12].gap0 = 0;
  v65[13].gap0 = 0;
  __k = key_up;
  v66 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v66->gap0 = 200;
  *(_WORD *)&v66[4].gap0 = 0;
  *(_WORD *)&v66[6].gap0 = 0;
  *(_DWORD *)&v66[8].gap0 = 38;
  v66[12].gap0 = 0;
  v66[13].gap0 = 0;
  __k = key_down;
  v67 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v67->gap0 = 208;
  *(_WORD *)&v67[4].gap0 = 0;
  *(_WORD *)&v67[6].gap0 = 0;
  *(_DWORD *)&v67[8].gap0 = 40;
  v67[12].gap0 = 0;
  v67[13].gap0 = 0;
  __k = key_tab;
  v68 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v68->gap0 = 15;
  *(_WORD *)&v68[4].gap0 = 0;
  *(_WORD *)&v68[6].gap0 = 0;
  *(_DWORD *)&v68[8].gap0 = 9;
  v68[12].gap0 = 0;
  v68[13].gap0 = 0;
  __k = key_rcontrol;
  v69 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v69->gap0 = 157;
  *(_WORD *)&v69[4].gap0 = 0;
  *(_WORD *)&v69[6].gap0 = 0;
  *(_DWORD *)&v69[8].gap0 = 163;
  v69[12].gap0 = 0;
  v69[13].gap0 = 0;
  __k = key_lcontrol;
  v70 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v70->gap0 = 29;
  *(_WORD *)&v70[4].gap0 = 0;
  *(_WORD *)&v70[6].gap0 = 0;
  *(_DWORD *)&v70[8].gap0 = 162;
  v70[12].gap0 = 0;
  v70[13].gap0 = 0;
  __k = key_rmenu;
  v71 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v71->gap0 = 184;
  *(_WORD *)&v71[4].gap0 = 0;
  *(_WORD *)&v71[6].gap0 = 0;
  *(_DWORD *)&v71[8].gap0 = 165;
  v71[12].gap0 = 0;
  v71[13].gap0 = 0;
  __k = key_lmenu;
  v72 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v72->gap0 = 56;
  *(_WORD *)&v72[4].gap0 = 0;
  *(_WORD *)&v72[6].gap0 = 0;
  *(_DWORD *)&v72[8].gap0 = 164;
  v72[12].gap0 = 0;
  v72[13].gap0 = 0;
  __k = key_rshift;
  v73 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v73->gap0 = 54;
  *(_WORD *)&v73[4].gap0 = 0;
  *(_WORD *)&v73[6].gap0 = 0;
  *(_DWORD *)&v73[8].gap0 = 161;
  v73[12].gap0 = 0;
  v73[13].gap0 = 0;
  __k = key_lshift;
  v74 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v74->gap0 = 42;
  *(_WORD *)&v74[4].gap0 = 0;
  *(_WORD *)&v74[6].gap0 = 0;
  *(_DWORD *)&v74[8].gap0 = 160;
  v74[12].gap0 = 0;
  v74[13].gap0 = 0;
  __k = key_numpadenter;
  v75 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v75->gap0 = 156;
  *(_WORD *)&v75[4].gap0 = 0;
  *(_WORD *)&v75[6].gap0 = 0;
  *(_DWORD *)&v75[8].gap0 = 13;
  v75[12].gap0 = 0;
  v75[13].gap0 = 0;
  __k = key_decimal;
  v76 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v76->gap0 = 83;
  *(_WORD *)&v76[4].gap0 = 0;
  *(_WORD *)&v76[6].gap0 = 0;
  *(_DWORD *)&v76[8].gap0 = 110;
  v76[12].gap0 = 0;
  v76[13].gap0 = 0;
  __k = key_add;
  v77 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v77->gap0 = 78;
  *(_WORD *)&v77[4].gap0 = 0;
  *(_WORD *)&v77[6].gap0 = 0;
  *(_DWORD *)&v77[8].gap0 = 107;
  v77[12].gap0 = 0;
  v77[13].gap0 = 0;
  __k = key_divide;
  v78 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v78->gap0 = 181;
  *(_WORD *)&v78[4].gap0 = 0;
  *(_WORD *)&v78[6].gap0 = 0;
  *(_DWORD *)&v78[8].gap0 = 111;
  v78[12].gap0 = 0;
  v78[13].gap0 = 0;
  __k = key_subtract;
  v79 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v79->gap0 = 74;
  *(_WORD *)&v79[4].gap0 = 0;
  *(_WORD *)&v79[6].gap0 = 0;
  *(_DWORD *)&v79[8].gap0 = 109;
  v79[12].gap0 = 0;
  v79[13].gap0 = 0;
  __k = key_multiply;
  v80 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
          a2,
          &__k);
  *(_DWORD *)&v80->gap0 = 55;
  *(_WORD *)&v80[4].gap0 = 0;
  *(_WORD *)&v80[6].gap0 = 0;
  *(_DWORD *)&v80[8].gap0 = 106;
  v80[12].gap0 = 0;
  v80[13].gap0 = 0;
}
