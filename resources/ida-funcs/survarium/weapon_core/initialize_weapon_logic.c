void __thiscall survarium::weapon_core::initialize_weapon_logic(
        survarium::weapon_core *this,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *inactive_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *show_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *hide_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *idle_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *reload_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *fire_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *aim_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *aim_fire_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *chamber_a_round_state,
        const vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *chamber_a_round_aimed_state)
{
  survarium::game_camera *m_object; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v12; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v14; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v15; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v16; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v17; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v18; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v19; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v20; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v21; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v22; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v23; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v24; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v25; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v26; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v27; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v28; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v29; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v30; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v31; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v32; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v33; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v34; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v35; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v36; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v37; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v38; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v39; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v40; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v41; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v42; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v43; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v44; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v45; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v46; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v47; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v48; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v49; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v50; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v51; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v52; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v53; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v54; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v55; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v56; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v57; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v58; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v59; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v60; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v61; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v62; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v63; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v64; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v65; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v66; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v67; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v68; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v69; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v70; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v71; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v72; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v73; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v74; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v75; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v76; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v77; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v78; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v79; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v80; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v81; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v82; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v83; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v84; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v85; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v86; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v87; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v88; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v89; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v90; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v91; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v92; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v93; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v94; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v95; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *v96; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v97; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v98; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v99; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v100; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v101; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v102; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v103; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v104; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v105; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v106; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v107; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v108; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v109; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v110; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v111; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v112; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v113; // ecx
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v114; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v115; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v116; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v117; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v118; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v119; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v120; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v121; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v122; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v123; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v124; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v125; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v126; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v127; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v128; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v129; // [esp-14h] [ebp-140Ch]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v131; // [esp+8h] [ebp-13F0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v132; // [esp+18h] [ebp-13E0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v133; // [esp+28h] [ebp-13D0h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v134; // [esp+38h] [ebp-13C0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v135; // [esp+48h] [ebp-13B0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v136; // [esp+58h] [ebp-13A0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v137; // [esp+68h] [ebp-1390h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v138; // [esp+78h] [ebp-1380h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v139; // [esp+88h] [ebp-1370h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v140; // [esp+98h] [ebp-1360h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v141; // [esp+A8h] [ebp-1350h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v142; // [esp+B8h] [ebp-1340h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v143; // [esp+C8h] [ebp-1330h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v144; // [esp+D8h] [ebp-1320h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v145; // [esp+E8h] [ebp-1310h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v146; // [esp+F8h] [ebp-1300h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v147; // [esp+108h] [ebp-12F0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v148; // [esp+118h] [ebp-12E0h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v149; // [esp+128h] [ebp-12D0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v150; // [esp+138h] [ebp-12C0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v151; // [esp+148h] [ebp-12B0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v152; // [esp+158h] [ebp-12A0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v153; // [esp+168h] [ebp-1290h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v154; // [esp+178h] [ebp-1280h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v155; // [esp+188h] [ebp-1270h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v156; // [esp+198h] [ebp-1260h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v157; // [esp+1A8h] [ebp-1250h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v158; // [esp+1B8h] [ebp-1240h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v159; // [esp+1C8h] [ebp-1230h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v160; // [esp+1D8h] [ebp-1220h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v161; // [esp+1E8h] [ebp-1210h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v162; // [esp+1F8h] [ebp-1200h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v163; // [esp+208h] [ebp-11F0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v164; // [esp+218h] [ebp-11E0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v165; // [esp+228h] [ebp-11D0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v166; // [esp+238h] [ebp-11C0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v167; // [esp+248h] [ebp-11B0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v168; // [esp+258h] [ebp-11A0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v169; // [esp+268h] [ebp-1190h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v170; // [esp+278h] [ebp-1180h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v171; // [esp+288h] [ebp-1170h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v172; // [esp+298h] [ebp-1160h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v173; // [esp+2A8h] [ebp-1150h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v174; // [esp+2B8h] [ebp-1140h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v175; // [esp+2C8h] [ebp-1130h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v176; // [esp+2D8h] [ebp-1120h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v177; // [esp+2E8h] [ebp-1110h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v178; // [esp+2F8h] [ebp-1100h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v179; // [esp+308h] [ebp-10F0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > v180; // [esp+318h] [ebp-10E0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v181; // [esp+328h] [ebp-10D0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v182; // [esp+338h] [ebp-10C0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v183; // [esp+348h] [ebp-10B0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v184; // [esp+358h] [ebp-10A0h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v185; // [esp+368h] [ebp-1090h]
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v186; // [esp+378h] [ebp-1080h]
  vostok::sound::encoded_sound_interface *(__thiscall *v187)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+394h] [ebp-1064h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v188; // [esp+408h] [ebp-FF0h] BYREF
  BOOL (__thiscall *v189)(survarium::weapon_core *); // [esp+418h] [ebp-FE0h]
  int v190; // [esp+41Ch] [ebp-FDCh]
  boost::function<bool __cdecl(void)> v191; // [esp+420h] [ebp-FD8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v192; // [esp+440h] [ebp-FB8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v193; // [esp+450h] [ebp-FA8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v194; // [esp+478h] [ebp-F80h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v195; // [esp+488h] [ebp-F70h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v196; // [esp+4B0h] [ebp-F48h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v197; // [esp+4C0h] [ebp-F38h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v198; // [esp+4E8h] [ebp-F10h] BYREF
  bool (__thiscall *v199)(survarium::weapon_core *); // [esp+4F8h] [ebp-F00h]
  int v200; // [esp+4FCh] [ebp-EFCh]
  boost::function<bool __cdecl(void)> v201; // [esp+500h] [ebp-EF8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v202; // [esp+520h] [ebp-ED8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v203; // [esp+530h] [ebp-EC8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v204; // [esp+558h] [ebp-EA0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v205; // [esp+568h] [ebp-E90h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v206; // [esp+590h] [ebp-E68h] BYREF
  bool (__thiscall *v207)(survarium::weapon_core *); // [esp+5A0h] [ebp-E58h]
  int v208; // [esp+5A4h] [ebp-E54h]
  boost::function<bool __cdecl(void)> v209; // [esp+5A8h] [ebp-E50h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v210; // [esp+5C8h] [ebp-E30h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v211; // [esp+5D8h] [ebp-E20h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v212; // [esp+600h] [ebp-DF8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v213; // [esp+610h] [ebp-DE8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v214; // [esp+638h] [ebp-DC0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v215; // [esp+648h] [ebp-DB0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v216; // [esp+670h] [ebp-D88h] BYREF
  bool (__thiscall *v217)(survarium::weapon_core *); // [esp+680h] [ebp-D78h]
  int v218; // [esp+684h] [ebp-D74h]
  boost::function<bool __cdecl(void)> v219; // [esp+688h] [ebp-D70h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v220; // [esp+6A8h] [ebp-D50h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v221; // [esp+6B8h] [ebp-D40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v222; // [esp+6E0h] [ebp-D18h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v223; // [esp+6F0h] [ebp-D08h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v224; // [esp+718h] [ebp-CE0h] BYREF
  BOOL (__thiscall *v225)(survarium::weapon_core *); // [esp+728h] [ebp-CD0h]
  int v226; // [esp+72Ch] [ebp-CCCh]
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+730h] [ebp-CC8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v228; // [esp+750h] [ebp-CA8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v229; // [esp+760h] [ebp-C98h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v230; // [esp+788h] [ebp-C70h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v231; // [esp+798h] [ebp-C60h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v232; // [esp+7C0h] [ebp-C38h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v233; // [esp+7D0h] [ebp-C28h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v234; // [esp+7F8h] [ebp-C00h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v235; // [esp+808h] [ebp-BF0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v236; // [esp+830h] [ebp-BC8h] BYREF
  bool (__thiscall *v237)(survarium::weapon_core *); // [esp+840h] [ebp-BB8h]
  int v238; // [esp+844h] [ebp-BB4h]
  boost::function0<bool> v239; // [esp+848h] [ebp-BB0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v240; // [esp+868h] [ebp-B90h] BYREF
  bool (__thiscall *v241)(survarium::weapon_core *); // [esp+878h] [ebp-B80h]
  int v242; // [esp+87Ch] [ebp-B7Ch]
  boost::function0<bool> v243; // [esp+880h] [ebp-B78h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v244; // [esp+8A0h] [ebp-B58h] BYREF
  bool (__thiscall *v245)(survarium::weapon_core *); // [esp+8B0h] [ebp-B48h]
  int v246; // [esp+8B4h] [ebp-B44h]
  boost::function0<bool> v247; // [esp+8B8h] [ebp-B40h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v248; // [esp+8D8h] [ebp-B20h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v249; // [esp+8E8h] [ebp-B10h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v250; // [esp+910h] [ebp-AE8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v251; // [esp+920h] [ebp-AD8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v252; // [esp+948h] [ebp-AB0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v253; // [esp+958h] [ebp-AA0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v254; // [esp+980h] [ebp-A78h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v255; // [esp+990h] [ebp-A68h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v256; // [esp+9B8h] [ebp-A40h] BYREF
  bool (__thiscall *v257)(survarium::weapon_core *); // [esp+9C8h] [ebp-A30h]
  int v258; // [esp+9CCh] [ebp-A2Ch]
  boost::function0<bool> v259; // [esp+9D0h] [ebp-A28h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v260; // [esp+9F0h] [ebp-A08h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v261; // [esp+A00h] [ebp-9F8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v262; // [esp+A28h] [ebp-9D0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v263; // [esp+A38h] [ebp-9C0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v264; // [esp+A60h] [ebp-998h] BYREF
  bool (__thiscall *v265)(survarium::weapon_core *); // [esp+A70h] [ebp-988h]
  int v266; // [esp+A74h] [ebp-984h]
  boost::function0<bool> v267; // [esp+A78h] [ebp-980h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v268; // [esp+A98h] [ebp-960h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v269; // [esp+AA8h] [ebp-950h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v270; // [esp+AD0h] [ebp-928h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v271; // [esp+AE0h] [ebp-918h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v272; // [esp+B08h] [ebp-8F0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v273; // [esp+B18h] [ebp-8E0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v274; // [esp+B40h] [ebp-8B8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v275; // [esp+B50h] [ebp-8A8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v276; // [esp+B78h] [ebp-880h] BYREF
  bool (__thiscall *v277)(survarium::weapon_core *); // [esp+B88h] [ebp-870h]
  int v278; // [esp+B8Ch] [ebp-86Ch]
  boost::function0<bool> v279; // [esp+B90h] [ebp-868h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v280; // [esp+BB0h] [ebp-848h] BYREF
  bool (__thiscall *v281)(survarium::weapon_core *); // [esp+BC0h] [ebp-838h]
  int v282; // [esp+BC4h] [ebp-834h]
  boost::function0<bool> v283; // [esp+BC8h] [ebp-830h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v284; // [esp+BE8h] [ebp-810h] BYREF
  bool (__thiscall *v285)(survarium::weapon_core *); // [esp+BF8h] [ebp-800h]
  int v286; // [esp+BFCh] [ebp-7FCh]
  boost::function0<bool> v287; // [esp+C00h] [ebp-7F8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v288; // [esp+C20h] [ebp-7D8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v289; // [esp+C30h] [ebp-7C8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v290; // [esp+C58h] [ebp-7A0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v291; // [esp+C68h] [ebp-790h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v292; // [esp+C90h] [ebp-768h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v293; // [esp+CA0h] [ebp-758h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v294; // [esp+CC8h] [ebp-730h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v295; // [esp+CD8h] [ebp-720h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v296; // [esp+D00h] [ebp-6F8h] BYREF
  bool (__thiscall *v297)(survarium::weapon_core *); // [esp+D10h] [ebp-6E8h]
  int v298; // [esp+D14h] [ebp-6E4h]
  boost::function0<bool> v299; // [esp+D18h] [ebp-6E0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v300; // [esp+D38h] [ebp-6C0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v301; // [esp+D48h] [ebp-6B0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v302; // [esp+D70h] [ebp-688h] BYREF
  bool (__thiscall *v303)(survarium::weapon_core *); // [esp+D80h] [ebp-678h]
  int v304; // [esp+D84h] [ebp-674h]
  boost::function0<bool> v305; // [esp+D88h] [ebp-670h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v306; // [esp+DA8h] [ebp-650h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v307; // [esp+DB8h] [ebp-640h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v308; // [esp+DE0h] [ebp-618h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v309; // [esp+DF0h] [ebp-608h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v310; // [esp+E18h] [ebp-5E0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v311; // [esp+E28h] [ebp-5D0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v312; // [esp+E50h] [ebp-5A8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v313; // [esp+E60h] [ebp-598h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v314; // [esp+E88h] [ebp-570h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v315; // [esp+E98h] [ebp-560h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v316; // [esp+EC0h] [ebp-538h] BYREF
  bool (__thiscall *v317)(survarium::weapon_core *); // [esp+ED0h] [ebp-528h]
  int v318; // [esp+ED4h] [ebp-524h]
  boost::function0<bool> v319; // [esp+ED8h] [ebp-520h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v320; // [esp+EF8h] [ebp-500h] BYREF
  bool (__thiscall *v321)(survarium::weapon_core *); // [esp+F08h] [ebp-4F0h]
  int v322; // [esp+F0Ch] [ebp-4ECh]
  boost::function0<bool> v323; // [esp+F10h] [ebp-4E8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v324; // [esp+F30h] [ebp-4C8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v325; // [esp+F40h] [ebp-4B8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v326; // [esp+F68h] [ebp-490h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v327; // [esp+F78h] [ebp-480h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v328; // [esp+FA0h] [ebp-458h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v329; // [esp+FB0h] [ebp-448h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v330; // [esp+FD8h] [ebp-420h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v331; // [esp+FE8h] [ebp-410h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v332; // [esp+1010h] [ebp-3E8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v333; // [esp+1020h] [ebp-3D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v334; // [esp+1048h] [ebp-3B0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v335; // [esp+1058h] [ebp-3A0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v336; // [esp+1080h] [ebp-378h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v337; // [esp+1090h] [ebp-368h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v338; // [esp+10B8h] [ebp-340h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v339; // [esp+10C8h] [ebp-330h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v340; // [esp+10F0h] [ebp-308h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v341; // [esp+1100h] [ebp-2F8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v342; // [esp+1128h] [ebp-2D0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v343; // [esp+1138h] [ebp-2C0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v344; // [esp+1160h] [ebp-298h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v345; // [esp+1170h] [ebp-288h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v346; // [esp+1198h] [ebp-260h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v347; // [esp+11A8h] [ebp-250h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v348; // [esp+11D0h] [ebp-228h] BYREF
  bool (__thiscall *v349)(survarium::weapon_core *); // [esp+11E0h] [ebp-218h]
  int v350; // [esp+11E4h] [ebp-214h]
  boost::function0<bool> v351; // [esp+11E8h] [ebp-210h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v352; // [esp+1208h] [ebp-1F0h] BYREF
  bool (__thiscall *v353)(survarium::weapon_core *); // [esp+1218h] [ebp-1E0h]
  int v354; // [esp+121Ch] [ebp-1DCh]
  boost::function0<bool> v355; // [esp+1220h] [ebp-1D8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v356; // [esp+1240h] [ebp-1B8h] BYREF
  bool (__thiscall *v357)(survarium::weapon_core *); // [esp+1250h] [ebp-1A8h]
  int v358; // [esp+1254h] [ebp-1A4h]
  boost::function0<bool> v359; // [esp+1258h] [ebp-1A0h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v360; // [esp+1278h] [ebp-180h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v361; // [esp+1288h] [ebp-170h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v362; // [esp+12B0h] [ebp-148h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v363; // [esp+12C0h] [ebp-138h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v364; // [esp+12E8h] [ebp-110h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v365; // [esp+12F8h] [ebp-100h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v366; // [esp+1320h] [ebp-D8h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v367; // [esp+1330h] [ebp-C8h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > v368; // [esp+1358h] [ebp-A0h] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > v369; // [esp+1368h] [ebp-90h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > result; // [esp+1390h] [ebp-68h] BYREF
  BOOL (__thiscall *f)(survarium::weapon_core *, survarium::weapon_targets); // [esp+13A0h] [ebp-58h]
  int f_4; // [esp+13A4h] [ebp-54h]
  boost::function0<bool> v373; // [esp+13A8h] [ebp-50h] BYREF
  char v374; // [esp+13CFh] [ebp-29h]
  vostok::ai::fsm_state *v375; // [esp+13D0h] [ebp-28h]
  vostok::ai::fsm_state *v376; // [esp+13D4h] [ebp-24h]
  vostok::ai::fsm_state *v377; // [esp+13D8h] [ebp-20h]
  vostok::ai::fsm_state *from; // [esp+13DCh] [ebp-1Ch]
  vostok::ai::fsm_state *v379; // [esp+13E0h] [ebp-18h]
  vostok::ai::fsm_state *v380; // [esp+13E4h] [ebp-14h]
  vostok::ai::fsm_state *v381; // [esp+13E8h] [ebp-10h]
  vostok::ai::fsm_state *state; // [esp+13ECh] [ebp-Ch]
  vostok::ai::fsm_state *to; // [esp+13F0h] [ebp-8h]
  vostok::ai::fsm_state *v384; // [esp+13F4h] [ebp-4h]

  m_object = (survarium::game_camera *)chamber_a_round_state->m_object;
  this->m_is_there_chamber_a_round_state = chamber_a_round_state->m_object != 0;
  v374 = 0;
  survarium::weapon_user_dead_state::finalize(m_object);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    inactive_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    show_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    hide_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    idle_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    reload_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    fire_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    aim_state);
  vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
    &this->m_logic_states,
    aim_fire_state);
  if ( this->m_is_there_chamber_a_round_state )
    vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
      &this->m_logic_states,
      chamber_a_round_state);
  if ( chamber_a_round_aimed_state->m_object )
    v187 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
  else
    v187 = 0;
  if ( v187 )
    vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::push_back(
      &this->m_logic_states,
      chamber_a_round_aimed_state);
  state = inactive_state->m_object;
  to = show_state->m_object;
  from = hide_state->m_object;
  v375 = idle_state->m_object;
  v377 = reload_state->m_object;
  v379 = fire_state->m_object;
  v380 = aim_state->m_object;
  v376 = aim_fire_state->m_object;
  v381 = chamber_a_round_state->m_object;
  v384 = chamber_a_round_aimed_state->m_object;
  *(_DWORD *)&v379[12].transitions.gap4 = &this->m_is_firing;
  *(_DWORD *)&v376[12].transitions.gap4 = &this->m_is_firing;
  vostok::ai::fsm::add_state(this->m_logic, state);
  vostok::ai::fsm::add_state(this->m_logic, to);
  vostok::ai::fsm::add_state(this->m_logic, from);
  vostok::ai::fsm::add_state(this->m_logic, v375);
  vostok::ai::fsm::add_state(this->m_logic, v377);
  vostok::ai::fsm::add_state(this->m_logic, v379);
  vostok::ai::fsm::add_state(this->m_logic, v380);
  vostok::ai::fsm::add_state(this->m_logic, v376);
  if ( this->m_is_there_chamber_a_round_state )
    vostok::ai::fsm::add_state(this->m_logic, v381);
  if ( v384 )
    vostok::ai::fsm::add_state(this->m_logic, v384);
  f = survarium::weapon_core::target_predicate;
  f_4 = 0;
  v12 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v186 = *v12;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v12->f_.f_),
    &v373);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    &v373,
    v186);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    state,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v373);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v13,
    (int *)&v373);
  LODWORD(v369.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v369.f_.f_) = 0;
  v185 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v368,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v185.l_.a1_.t_,
    &v369.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v369.l_,
    v185);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    state,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v369.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v14,
    (int *)&v369.l_);
  LODWORD(v367.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v367.f_.f_) = 0;
  v15 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v366,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)1);
  v184 = *v15;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v15->f_.f_),
    &v367.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v367.l_,
    v184);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    state,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v367.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v16,
    (int *)&v367.l_);
  LODWORD(v365.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v365.f_.f_) = 0;
  v183 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v364,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)2);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v183.l_.a1_.t_,
    &v365.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v365.l_,
    v183);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    state,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v365.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v17,
    (int *)&v365.l_);
  LODWORD(v363.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v363.f_.f_) = 0;
  v18 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v362,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)3);
  v182 = *v18;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v18->f_.f_),
    &v363.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v363.l_,
    v182);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    state,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v363.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v19,
    (int *)&v363.l_);
  LODWORD(v361.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v361.f_.f_) = 0;
  v181 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v360,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v181.l_.a1_.t_,
    &v361.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v361.l_,
    v181);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    from,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v361.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v20,
    (int *)&v361.l_);
  if ( v384 )
  {
    v357 = survarium::weapon_core::must_chamber_a_round_aimed_predicate;
    v358 = 0;
    v21 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v356,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_aimed_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v180 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v21;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v21->f_.f_),
      &v359);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v359,
      v180);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      to,
      v384,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v359);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v22,
      (int *)&v359);
  }
  if ( this->m_is_there_chamber_a_round_state )
  {
    v353 = survarium::weapon_core::must_chamber_a_round_predicate;
    v354 = 0;
    v23 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v352,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v179 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v23;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v23->f_.f_),
      &v355);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v355,
      v179);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      to,
      v381,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v355);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v24,
      (int *)&v355);
  }
  v349 = survarium::weapon_core::can_and_must_reload_predicate;
  v350 = 0;
  v178 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v348,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::can_and_must_reload_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v178.l_.a1_.t_,
    &v351);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
    &v351,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v178);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v351);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v25,
    (int *)&v351);
  LODWORD(v347.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v347.f_.f_) = 0;
  v26 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v346,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v177 = *v26;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v26->f_.f_),
    &v347.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v347.l_,
    v177);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v347.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v27,
    (int *)&v347.l_);
  LODWORD(v345.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v345.f_.f_) = 0;
  v176 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v344,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v176.l_.a1_.t_,
    &v345.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v345.l_,
    v176);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v345.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v28,
    (int *)&v345.l_);
  LODWORD(v343.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v343.f_.f_) = 0;
  v29 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v342,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)1);
  v175 = *v29;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v29->f_.f_),
    &v343.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v343.l_,
    v175);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    v379,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v343.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v30,
    (int *)&v343.l_);
  LODWORD(v341.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v341.f_.f_) = 0;
  v174 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v340,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)2);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v174.l_.a1_.t_,
    &v341.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v341.l_,
    v174);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    v380,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v341.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v31,
    (int *)&v341.l_);
  LODWORD(v339.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v339.f_.f_) = 0;
  v32 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v338,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)3);
  v173 = *v32;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v32->f_.f_),
    &v339.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v339.l_,
    v173);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    to,
    v376,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v339.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v33,
    (int *)&v339.l_);
  LODWORD(v337.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v337.f_.f_) = 0;
  v172 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v336,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v172.l_.a1_.t_,
    &v337.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v337.l_,
    v172);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    from,
    state,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v337.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v34,
    (int *)&v337.l_);
  LODWORD(v335.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v335.f_.f_) = 0;
  v35 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v334,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v171 = *v35;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v35->f_.f_),
    &v335.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v335.l_,
    v171);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    from,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v335.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v36,
    (int *)&v335.l_);
  LODWORD(v333.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v333.f_.f_) = 0;
  v170 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v332,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v170.l_.a1_.t_,
    &v333.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v333.l_,
    v170);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    from,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v333.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v37,
    (int *)&v333.l_);
  LODWORD(v331.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v331.f_.f_) = 0;
  v38 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v330,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)1);
  v169 = *v38;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v38->f_.f_),
    &v331.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v331.l_,
    v169);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    from,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v331.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v39,
    (int *)&v331.l_);
  LODWORD(v329.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v329.f_.f_) = 0;
  v168 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v328,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)2);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v168.l_.a1_.t_,
    &v329.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v329.l_,
    v168);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    from,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v329.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v40,
    (int *)&v329.l_);
  LODWORD(v327.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v327.f_.f_) = 0;
  v41 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v326,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)3);
  v167 = *v41;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v41->f_.f_),
    &v327.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v327.l_,
    v167);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    from,
    to,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v327.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v42,
    (int *)&v327.l_);
  LODWORD(v325.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v325.f_.f_) = 0;
  v166 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v324,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v166.l_.a1_.t_,
    &v325.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v325.l_,
    v166);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v375,
    from,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v325.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v43,
    (int *)&v325.l_);
  if ( v384 )
  {
    v321 = survarium::weapon_core::must_chamber_a_round_aimed_predicate;
    v322 = 0;
    v44 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v320,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_aimed_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v165 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v44;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v44->f_.f_),
      &v323);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v323,
      v165);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v375,
      v384,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v323);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v45,
      (int *)&v323);
  }
  if ( this->m_is_there_chamber_a_round_state )
  {
    v317 = survarium::weapon_core::must_chamber_a_round_predicate;
    v318 = 0;
    v46 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v316,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v164 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v46;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v46->f_.f_),
      &v319);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v319,
      v164);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v375,
      v381,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v319);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v47,
      (int *)&v319);
  }
  LODWORD(v315.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v315.f_.f_) = 0;
  v163 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v314,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v163.l_.a1_.t_,
    &v315.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v315.l_,
    v163);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v375,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v315.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v48,
    (int *)&v315.l_);
  LODWORD(v313.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v313.f_.f_) = 0;
  v49 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v312,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)1);
  v162 = *v49;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v49->f_.f_),
    &v313.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v313.l_,
    v162);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v375,
    v379,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v313.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v50,
    (int *)&v313.l_);
  LODWORD(v311.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v311.f_.f_) = 0;
  v161 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v310,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)2);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v161.l_.a1_.t_,
    &v311.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v311.l_,
    v161);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v375,
    v380,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v311.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v51,
    (int *)&v311.l_);
  LODWORD(v309.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v309.f_.f_) = 0;
  v52 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v308,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)3);
  v160 = *v52;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v52->f_.f_),
    &v309.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v309.l_,
    v160);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v375,
    v376,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v309.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v53,
    (int *)&v309.l_);
  LODWORD(v307.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v307.f_.f_) = 0;
  v159 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v306,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v159.l_.a1_.t_,
    &v307.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v307.l_,
    v159);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v377,
    from,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v307.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v54,
    (int *)&v307.l_);
  if ( this->m_is_there_chamber_a_round_state && !this->m_chamber_a_round_on_reload )
  {
    v303 = survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate;
    v304 = 0;
    v158 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
              (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v302,
              (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate,
              (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v158.l_.a1_.t_,
      &v305);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v305,
      (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v158);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v377,
      v381,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v305);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v55,
      (int *)&v305);
  }
  LODWORD(v301.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v301.f_.f_) = 0;
  v56 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v300,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v157 = *v56;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v56->f_.f_),
    &v301.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v301.l_,
    v157);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v377,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v301.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v57,
    (int *)&v301.l_);
  v297 = survarium::weapon_core::instant_idle_predicate;
  v298 = 0;
  v156 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v296,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::instant_idle_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v156.l_.a1_.t_,
    &v299);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
    &v299,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v156);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v377,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v299);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v58,
    (int *)&v299);
  LODWORD(v295.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v295.f_.f_) = 0;
  v59 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v294,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)1);
  v155 = *v59;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v59->f_.f_),
    &v295.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v295.l_,
    v155);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v377,
    v379,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v295.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v60,
    (int *)&v295.l_);
  LODWORD(v293.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v293.f_.f_) = 0;
  v154 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v292,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)2);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v154.l_.a1_.t_,
    &v293.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v293.l_,
    v154);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v377,
    v380,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v293.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v61,
    (int *)&v293.l_);
  LODWORD(v291.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v291.f_.f_) = 0;
  v62 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v290,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)3);
  v153 = *v62;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v62->f_.f_),
    &v291.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v291.l_,
    v153);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v377,
    v376,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v291.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v63,
    (int *)&v291.l_);
  LODWORD(v289.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v289.f_.f_) = 0;
  v152 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v288,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v152.l_.a1_.t_,
    &v289.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v289.l_,
    v152);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    from,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v289.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v64,
    (int *)&v289.l_);
  if ( v384 )
  {
    v285 = survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate;
    v286 = 0;
    v65 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v284,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v151 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v65;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v65->f_.f_),
      &v287);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v287,
      v151);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v379,
      v384,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v287);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v66,
      (int *)&v287);
  }
  if ( this->m_is_there_chamber_a_round_state )
  {
    v281 = survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate;
    v282 = 0;
    v67 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v280,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v150 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v67;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v67->f_.f_),
      &v283);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v283,
      v150);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v379,
      v381,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v283);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v68,
      (int *)&v283);
  }
  v277 = survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate;
  v278 = 0;
  v149 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v276,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v149.l_.a1_.t_,
    &v279);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
    &v279,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v149);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v279);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v69,
    (int *)&v279);
  LODWORD(v275.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v275.f_.f_) = 0;
  v70 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v274,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v148 = *v70;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v70->f_.f_),
    &v275.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v275.l_,
    v148);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v275.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v71,
    (int *)&v275.l_);
  LODWORD(v273.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v273.f_.f_) = 0;
  v147 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v272,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v147.l_.a1_.t_,
    &v273.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v273.l_,
    v147);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v273.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v72,
    (int *)&v273.l_);
  LODWORD(v271.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v271.f_.f_) = 0;
  v73 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v270,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)2);
  v146 = *v73;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v73->f_.f_),
    &v271.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v271.l_,
    v146);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    v380,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v271.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v74,
    (int *)&v271.l_);
  LODWORD(v269.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v269.f_.f_) = 0;
  v145 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v268,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)3);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v145.l_.a1_.t_,
    &v269.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v269.l_,
    v145);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    v376,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v269.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v75,
    (int *)&v269.l_);
  v265 = survarium::weapon_core::is_trying_to_aim;
  v266 = 0;
  v76 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v264,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::is_trying_to_aim,
          (survarium::weapon_core_animation_end_aware_state *)this);
  v144 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v76;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v76->f_.f_),
    &v267);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
    &v267,
    v144);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v379,
    v376,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v267);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v77,
    (int *)&v267);
  LODWORD(v263.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v263.f_.f_) = 0;
  v143 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v262,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v143.l_.a1_.t_,
    &v263.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v263.l_,
    v143);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v380,
    from,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v263.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v78,
    (int *)&v263.l_);
  LODWORD(v261.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v261.f_.f_) = 0;
  v79 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v260,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v142 = *v79;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v79->f_.f_),
    &v261.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v261.l_,
    v142);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v380,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v261.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v80,
    (int *)&v261.l_);
  v257 = survarium::weapon_core::instant_idle_predicate;
  v258 = 0;
  v141 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v256,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::instant_idle_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v141.l_.a1_.t_,
    &v259);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
    &v259,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v141);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v380,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v259);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v81,
    (int *)&v259);
  LODWORD(v255.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v255.f_.f_) = 0;
  v82 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v254,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)4);
  v140 = *v82;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v82->f_.f_),
    &v255.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v255.l_,
    v140);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v380,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v255.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v83,
    (int *)&v255.l_);
  LODWORD(v253.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v253.f_.f_) = 0;
  v139 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v252,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)1);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v139.l_.a1_.t_,
    &v253.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v253.l_,
    v139);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v380,
    v379,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v253.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v84,
    (int *)&v253.l_);
  LODWORD(v251.f_.f_) = survarium::weapon_core::target_predicate;
  HIDWORD(v251.f_.f_) = 0;
  v85 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v250,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)3);
  v138 = *v85;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v85->f_.f_),
    &v251.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v251.l_,
    v138);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v380,
    v376,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v251.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v86,
    (int *)&v251.l_);
  LODWORD(v249.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v249.f_.f_) = 0;
  v137 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v248,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v137.l_.a1_.t_,
    &v249.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v249.l_,
    v137);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    from,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v249.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v87,
    (int *)&v249.l_);
  if ( v384 )
  {
    v245 = survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate;
    v246 = 0;
    v88 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v244,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_aimed_and_animation_ended_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v136 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v88;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v88->f_.f_),
      &v247);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v247,
      v136);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v376,
      v384,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v247);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v89,
      (int *)&v247);
  }
  if ( this->m_is_there_chamber_a_round_state )
  {
    v241 = survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate;
    v242 = 0;
    v90 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v240,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::must_chamber_a_round_and_animation_ended_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
    v135 = *(boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > > *)v90;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v90->f_.f_),
      &v243);
    boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
      &v243,
      v135);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v376,
      v381,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v243);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v91,
      (int *)&v243);
  }
  v237 = survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate;
  v238 = 0;
  v134 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v236,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::can_and_must_reload_and_animation_ended_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v134.l_.a1_.t_,
    &v239);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>(
    &v239,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v134);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v239);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v92,
    (int *)&v239);
  LODWORD(v235.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v235.f_.f_) = 0;
  v93 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v234,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          0);
  v133 = *v93;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v93->f_.f_),
    &v235.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v235.l_,
    v133);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    v375,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v235.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v94,
    (int *)&v235.l_);
  LODWORD(v233.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v233.f_.f_) = 0;
  v132 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v232,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)4);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v132.l_.a1_.t_,
    &v233.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v233.l_,
    v132);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    v377,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v233.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v95,
    (int *)&v233.l_);
  LODWORD(v231.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v231.f_.f_) = 0;
  v96 = boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
          (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v230,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
          (vostok::sound::sound_world *)this,
          (vostok::memory::writer *)1);
  v131 = *v96;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v96->f_.f_),
    &v231.l_.a1_.t_);
  boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets>>>>(
    (boost::function0<bool> *)&v231.l_,
    v131);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    v379,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v231.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v97,
    (int *)&v231.l_);
  LODWORD(v229.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
  HIDWORD(v229.f_.f_) = 0;
  v114 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
            (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v228,
            (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
            (vostok::sound::sound_world *)this,
            (vostok::memory::writer *)2);
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    (boost::function<bool __cdecl(void)> *)&v229.l_,
    v114,
    0);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    v380,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v229.l_);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v98,
    (int *)&v229.l_);
  v225 = survarium::weapon_core::is_not_trying_to_aim_predicate;
  v226 = 0;
  v115 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v224,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::is_not_trying_to_aim_predicate,
            (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    &transition_predicate,
    (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v115,
    0);
  vostok::ai::fsm::add_transition(
    this->m_logic,
    v376,
    v379,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&transition_predicate);
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v99,
    (int *)&transition_predicate);
  if ( this->m_is_there_chamber_a_round_state )
  {
    LODWORD(v223.f_.f_) = survarium::weapon_core::target_predicate;
    HIDWORD(v223.f_.f_) = 0;
    v116 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v222,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)5);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v223.l_,
      v116,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v381,
      from,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v223.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v100,
      (int *)&v223.l_);
    LODWORD(v221.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v221.f_.f_) = 0;
    v117 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v220,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              0);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v221.l_,
      v117,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v381,
      v375,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v221.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v101,
      (int *)&v221.l_);
    v217 = survarium::weapon_core::instant_idle_predicate;
    v218 = 0;
    v118 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
              (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v216,
              (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::instant_idle_predicate,
              (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      &v219,
      (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v118,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v381,
      v375,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v219);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v102,
      (int *)&v219);
    LODWORD(v215.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v215.f_.f_) = 0;
    v119 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v214,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)1);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v215.l_,
      v119,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v381,
      v379,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v215.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v103,
      (int *)&v215.l_);
    LODWORD(v213.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v213.f_.f_) = 0;
    v120 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v212,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)2);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v213.l_,
      v120,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v381,
      v380,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v213.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v104,
      (int *)&v213.l_);
    LODWORD(v211.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v211.f_.f_) = 0;
    v121 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v210,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)3);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v211.l_,
      v121,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v381,
      v376,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v211.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v105,
      (int *)&v211.l_);
    if ( v384 )
    {
      v207 = survarium::weapon_core::is_trying_to_aim;
      v208 = 0;
      v122 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
                (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v206,
                (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::is_trying_to_aim,
                (survarium::weapon_core_animation_end_aware_state *)this);
      boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
        &v209,
        (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v122,
        0);
      vostok::ai::fsm::add_transition(
        this->m_logic,
        v381,
        v384,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v209);
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v106,
        (int *)&v209);
    }
  }
  if ( v384 )
  {
    LODWORD(v205.f_.f_) = survarium::weapon_core::target_predicate;
    HIDWORD(v205.f_.f_) = 0;
    v123 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v204,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)5);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v205.l_,
      v123,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      from,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v205.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v107,
      (int *)&v205.l_);
    LODWORD(v203.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v203.f_.f_) = 0;
    v124 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v202,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              0);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v203.l_,
      v124,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      v375,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v203.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v108,
      (int *)&v203.l_);
    v199 = survarium::weapon_core::instant_idle_predicate;
    v200 = 0;
    v125 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
              (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v198,
              (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::instant_idle_predicate,
              (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      &v201,
      (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v125,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      v375,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v201);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v109,
      (int *)&v201);
    LODWORD(v197.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v197.f_.f_) = 0;
    v126 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v196,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)1);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v197.l_,
      v126,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      v379,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v197.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v110,
      (int *)&v197.l_);
    LODWORD(v195.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v195.f_.f_) = 0;
    v127 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v194,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)2);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v195.l_,
      v127,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      v380,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v195.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v111,
      (int *)&v195.l_);
    LODWORD(v193.f_.f_) = survarium::weapon_core::target_and_animation_ended_predicate;
    HIDWORD(v193.f_.f_) = 0;
    v128 = *boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(
              (boost::_bi::bind_t<bool,boost::_mfi::cmf1<bool,survarium::weapon_core,enum survarium::weapon_targets>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core *>,boost::_bi::value<enum survarium::weapon_targets> > > *)&v192,
              (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)survarium::weapon_core::target_and_animation_ended_predicate,
              (vostok::sound::sound_world *)this,
              (vostok::memory::writer *)3);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      (boost::function<bool __cdecl(void)> *)&v193.l_,
      v128,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      v376,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v193.l_);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v112,
      (int *)&v193.l_);
    v189 = survarium::weapon_core::is_not_trying_to_aim_predicate;
    v190 = 0;
    v129 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
              (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v188,
              (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::weapon_core::is_not_trying_to_aim_predicate,
              (survarium::weapon_core_animation_end_aware_state *)this);
    boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
      &v191,
      (boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *> > >)v129,
      0);
    vostok::ai::fsm::add_transition(
      this->m_logic,
      v384,
      v381,
      (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v191);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v113,
      (int *)&v191);
  }
}
