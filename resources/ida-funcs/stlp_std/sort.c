void __usercall stlp_std::sort<unsigned int *>(
        unsigned int *__first@<edi>,
        unsigned int *__last@<esi>,
        unsigned int *a3@<ecx>)
{
  int v3; // eax
  int v4; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    v4 = 0;
    while ( v3 != 1 )
    {
      ++v4;
      v3 >>= 1;
    }
    stlp_std::priv::__introsort_loop<unsigned int *,unsigned int,int,stlp_std::less<unsigned int>>(
      (stlp_std::less<unsigned int>)__first,
      __first,
      __last,
      0,
      2 * v4,
      a3);
    stlp_std::priv::__final_insertion_sort<survarium::single_game_effect * *,stlp_std::less<survarium::single_game_effect *>>(
      __first,
      __last,
      a3);
  }
}


void __usercall stlp_std::sort<float *>(float *__first@<edi>, float *__last@<esi>, float *a3@<ecx>)
{
  int v3; // eax
  int v4; // ecx

  if ( __first != __last )
  {
    v3 = __last - __first;
    v4 = 0;
    while ( v3 != 1 )
    {
      ++v4;
      v3 >>= 1;
    }
    stlp_std::priv::__introsort_loop<float *,float,int,stlp_std::less<float>>(
      (stlp_std::less<float>)__first,
      __first,
      __last,
      0,
      2 * v4,
      a3);
    stlp_std::priv::__final_insertion_sort<float *,stlp_std::less<float>>(
      __first,
      (stlp_std::less<float>)__last,
      __last,
      a3);
  }
}


void __cdecl stlp_std::sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
        vostok::render::grass_patch **__first,
        vostok::render::grass_patch **__last,
        vostok::render::sort_grass_patch_predicate __comp)
{
  int v3; // eax
  int v4; // ecx
  __int128 v5; // [esp-Ch] [ebp-18h]

  if ( __first != __last )
  {
    v3 = __last - __first;
    v4 = 0;
    while ( v3 != 1 )
    {
      ++v4;
      v3 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::render::grass_patch * *,vostok::render::grass_patch *,int,vostok::render::sort_grass_patch_predicate>(
      __first,
      __last,
      0,
      2 * v4,
      __comp);
    *(vostok::render::sort_grass_patch_predicate *)&v5 = __comp;
    stlp_std::priv::__final_insertion_sort<vostok::render::grass_patch * *,vostok::render::sort_grass_patch_predicate>(
      __first,
      __last,
      v5);
  }
}


void __usercall stlp_std::sort<survarium::hud_game_effect_presenter::effect_data *>(
        vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *__first@<edi>,
        survarium::hud_game_effect_presenter::effect_data *__last@<esi>)
{
  int v2; // eax
  int v3; // ecx
  survarium::hud_game_effect_presenter::effect_data *__comp; // [esp+4h] [ebp-4h]

  if ( __first != (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)__last )
  {
    v2 = ((char *)__last - (char *)__first) / 12;
    v3 = 0;
    while ( v2 != 1 )
    {
      ++v3;
      v2 >>= 1;
    }
    stlp_std::priv::__introsort_loop<survarium::hud_game_effect_presenter::effect_data *,survarium::hud_game_effect_presenter::effect_data,int,stlp_std::less<survarium::hud_game_effect_presenter::effect_data>>(
      __first,
      __last,
      0,
      2 * v3,
      __comp);
    stlp_std::priv::__final_insertion_sort<survarium::hud_game_effect_presenter::effect_data *,stlp_std::less<survarium::hud_game_effect_presenter::effect_data>>(
      (survarium::hud_game_effect_presenter::effect_data *)__first,
      __last,
      __comp);
  }
}


void __usercall stlp_std::sort<vostok::memory::platform::region *>(
        stlp_std::less<vostok::memory::platform::region> *__first@<edi>,
        stlp_std::less<vostok::memory::platform::region> *__last@<esi>,
        vostok::memory::platform::region *a3@<ecx>)
{
  int v3; // eax
  int v4; // ecx

  if ( __first != __last )
  {
    v3 = (__last - __first) >> 4;
    v4 = 0;
    while ( v3 != 1 )
    {
      ++v4;
      v3 >>= 1;
    }
    stlp_std::priv::__introsort_loop<vostok::memory::platform::region *,vostok::memory::platform::region,int,stlp_std::less<vostok::memory::platform::region>>(
      __first,
      (vostok::memory::platform::region *)__first,
      (vostok::memory::platform::region *)__last,
      0,
      2 * v4,
      a3);
    stlp_std::priv::__final_insertion_sort<vostok::memory::platform::region *,stlp_std::less<vostok::memory::platform::region>>(
      (vostok::memory::platform::region *)__first,
      (vostok::memory::platform::region *)__last,
      a3);
  }
}
