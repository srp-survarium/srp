void __usercall stlp_std::__make_heap<vostok::physics::closest_ray_result *,vostok::physics::distance_predicate,vostok::physics::closest_ray_result,int>(
        vostok::physics::closest_ray_result *__last@<eax>,
        vostok::physics::closest_ray_result *__first,
        vostok::physics::distance_predicate __len)
{
  int v3; // ebx
  vostok::physics::closest_ray_result v4; // [esp-34h] [ebp-48h] BYREF
  __int128 v5; // [esp-Ch] [ebp-20h]
  int __lena; // [esp+Ch] [ebp-8h]
  vostok::physics::closest_ray_result *v7; // [esp+10h] [ebp-4h]

  *(_QWORD *)&v5 = *(_QWORD *)LODWORD(__len.m_from.x);
  DWORD2(v5) = *(_DWORD *)(LODWORD(__len.m_from.x) + 8);
  __lena = __last - __first;
  v3 = (__lena - 2) / 2;
  v7 = &__first[v3];
  qmemcpy(&v4, v7, sizeof(v4));
  stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
    __first,
    v3,
    __lena,
    v4,
    v5);
  while ( v3 )
  {
    --v7;
    *(_QWORD *)&v5 = *(_QWORD *)LODWORD(__len.m_from.x);
    DWORD2(v5) = *(_DWORD *)(LODWORD(__len.m_from.x) + 8);
    --v3;
    qmemcpy(&v4, v7, sizeof(v4));
    stlp_std::__adjust_heap<vostok::physics::closest_ray_result *,int,vostok::physics::closest_ray_result,vostok::physics::distance_predicate>(
      __first,
      v3,
      __lena,
      v4,
      v5);
  }
}


void __usercall stlp_std::__make_heap<survarium::relocate_item_descr *,survarium::ammo_slots_sort,survarium::relocate_item_descr,int>(
        survarium::relocate_item_descr *__last@<eax>,
        survarium::relocate_item_descr *__first,
        survarium::ammo_slots_sort __len)
{
  int v3; // ebx
  survarium::relocate_item_descr *v4; // eax
  __int128 v5; // [esp+0h] [ebp-20h]
  __int128 v6; // [esp+0h] [ebp-20h]
  int __lena; // [esp+18h] [ebp-8h]
  survarium::relocate_item_descr *v8; // [esp+1Ch] [ebp-4h]

  __lena = __last - __first;
  *(vostok::vfs::vfs_association *)&v5 = __len.m_dict->vostok::vfs::vfs_association;
  v3 = (__lena - 2) / 2;
  DWORD2(v5) = __len.m_dict->m_flags.m_flags;
  v4 = &__first[v3];
  v8 = v4;
  stlp_std::__adjust_heap<survarium::relocate_item_descr *,int,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
    __first,
    v3,
    __lena,
    *v4,
    v5);
  while ( v3 )
  {
    --v8;
    *(vostok::vfs::vfs_association *)&v6 = __len.m_dict->vostok::vfs::vfs_association;
    DWORD2(v6) = __len.m_dict->m_flags.m_flags;
    stlp_std::__adjust_heap<survarium::relocate_item_descr *,int,survarium::relocate_item_descr,survarium::ammo_slots_sort>(
      __first,
      --v3,
      __lena,
      *v8,
      v6);
  }
}


void __usercall stlp_std::__make_heap<vostok::math::curve_point<float> *,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &),vostok::math::curve_point<float>,int>(
        vostok::math::curve_point<float> *__last@<eax>,
        vostok::math::curve_point<float> *__first,
        bool (__cdecl *__comp)(const vostok::math::curve_point<float> *, const vostok::math::curve_point<float> *))
{
  int v3; // ebx
  vostok::math::curve_point<float> v4; // [esp-1Ch] [ebp-30h] BYREF
  int __len; // [esp+Ch] [ebp-8h]
  vostok::math::curve_point<float> *v6; // [esp+10h] [ebp-4h]

  __len = __last - __first;
  v3 = (__len - 2) / 2;
  v6 = &__first[v3];
  qmemcpy(&v4, v6, sizeof(v4));
  stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
    __first,
    v3,
    __len,
    v4,
    __comp);
  while ( v3 )
  {
    --v6;
    --v3;
    qmemcpy(&v4, v6, sizeof(v4));
    stlp_std::__adjust_heap<vostok::math::curve_point<float> *,int,vostok::math::curve_point<float>,bool (__cdecl *)(vostok::math::curve_point<float> const &,vostok::math::curve_point<float> const &)>(
      __first,
      v3,
      __len,
      v4,
      __comp);
  }
}
