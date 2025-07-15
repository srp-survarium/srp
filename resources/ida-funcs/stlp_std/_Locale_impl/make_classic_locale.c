void stlp_std::_Locale_impl::make_classic_locale()
{
  stlp_std::_Locale_impl *v0; // eax
  stlp_std::locale::facet *v1; // eax
  stlp_std::ctype<char> *v2; // eax
  stlp_std::locale::facet *v3; // eax
  stlp_std::locale::facet *v4; // eax
  stlp_std::moneypunct<char,1> *v5; // eax
  stlp_std::locale::facet *v6; // eax
  stlp_std::moneypunct<char,0> *v7; // eax
  stlp_std::locale::facet *v8; // eax
  stlp_std::locale::facet *v9; // eax
  stlp_std::messages<char> *v10; // eax
  stlp_std::locale::facet *v11; // eax
  stlp_std::locale::facet *v12; // eax
  stlp_std::locale::facet *v13; // eax
  stlp_std::locale::facet *v14; // eax
  stlp_std::locale::facet *v15; // eax
  char *v16; // eax
  stlp_std::locale::facet *v17; // esi
  char *v18; // eax
  stlp_std::locale::facet *v19; // esi
  stlp_std::locale::facet *v20; // eax
  stlp_std::locale::facet *v21; // eax
  stlp_std::locale::facet *v22; // eax
  stlp_std::moneypunct<wchar_t,1> *v23; // eax
  stlp_std::locale::facet *v24; // eax
  stlp_std::moneypunct<wchar_t,0> *v25; // eax
  stlp_std::locale::facet *v26; // eax
  stlp_std::locale::facet *v27; // eax
  stlp_std::messages<wchar_t> *v28; // eax
  stlp_std::locale::facet *v29; // eax
  stlp_std::locale::facet *v30; // eax
  stlp_std::locale::facet *v31; // eax
  stlp_std::locale::facet *v32; // eax
  stlp_std::locale::facet *v33; // eax
  char *v34; // eax
  stlp_std::locale::facet *v35; // esi
  char *v36; // eax
  stlp_std::locale::facet *v37; // esi
  stlp_std::vector<stlp_std::locale::facet *,stlp_std::allocator<stlp_std::locale::facet *> > *p_facets_vec; // esi
  void **M_start; // eax
  stlp_std::priv::_STLP_alloc_proxy<void * *,void *,stlp_std::allocator<void *> > *p_M_end_of_storage; // ebx
  unsigned int v41; // ecx
  int v42; // ebp
  _STLP_atomic_freelist::item *v43; // edi
  _STLP_atomic_freelist::item *v44; // eax
  stlp_std::forward_iterator_tag v45; // [esp+17h] [ebp-89h] BYREF
  unsigned int __n; // [esp+18h] [ebp-88h] BYREF
  stlp_std::_Locale_impl *impl; // [esp+1Ch] [ebp-84h]
  char *v48; // [esp+20h] [ebp-80h]
  stlp_std::locale::facet *v49[28]; // [esp+24h] [ebp-7Ch] BYREF
  int v50; // [esp+94h] [ebp-Ch] BYREF
  int v51; // [esp+9Ch] [ebp-4h]

  __n = (unsigned int)&Locale_classic_impl_buf;
  stlp_std::_Locale_impl::_Locale_impl((stlp_std::_Locale_impl *)&Locale_classic_impl_buf, "C");
  impl = v0;
  v51 = -1;
  v49[0] = 0;
  v1 = (stlp_std::locale::facet *)operator new(8u);
  if ( v1 )
  {
    v1->_M_ref_count = 1;
    v1->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::collate<char>::`vftable';
  }
  else
  {
    v1 = 0;
  }
  v49[1] = v1;
  v2 = (stlp_std::ctype<char> *)operator new(0x10u);
  v48 = (char *)v2;
  v51 = 1;
  if ( v2 )
    stlp_std::ctype<char>::ctype<char>(v2, 0, 0, 1u);
  else
    v3 = 0;
  v51 = -1;
  v49[2] = v3;
  v4 = (stlp_std::locale::facet *)operator new(8u);
  if ( v4 )
  {
    v4->_M_ref_count = 1;
    v4->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::codecvt<char,char,int>::`vftable';
  }
  else
  {
    v4 = 0;
  }
  v49[3] = v4;
  v5 = (stlp_std::moneypunct<char,1> *)operator new(0x10u);
  v48 = (char *)v5;
  v51 = 2;
  if ( v5 )
    stlp_std::moneypunct<char,1>::moneypunct<char,1>(v5, 1u);
  else
    v6 = 0;
  v49[4] = v6;
  v7 = (stlp_std::moneypunct<char,0> *)operator new(0x10u);
  v48 = (char *)v7;
  v51 = 3;
  if ( v7 )
    stlp_std::moneypunct<char,0>::moneypunct<char,0>(v7, 1u);
  else
    v8 = 0;
  v51 = -1;
  v49[5] = v8;
  v9 = (stlp_std::locale::facet *)operator new(8u);
  if ( v9 )
  {
    v9->_M_ref_count = 1;
    v9->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::numpunct<char>::`vftable';
  }
  else
  {
    v9 = 0;
  }
  v49[6] = v9;
  v10 = (stlp_std::messages<char> *)operator new(8u);
  v48 = (char *)v10;
  v51 = 4;
  if ( v10 )
    stlp_std::messages<char>::messages<char>(v10, 1u);
  else
    v11 = 0;
  v51 = -1;
  v49[7] = v11;
  v12 = (stlp_std::locale::facet *)operator new(8u);
  if ( v12 )
  {
    v12->_M_ref_count = 1;
    v12->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::money_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  }
  else
  {
    v12 = 0;
  }
  v49[8] = v12;
  v13 = (stlp_std::locale::facet *)operator new(8u);
  if ( v13 )
  {
    v13->_M_ref_count = 1;
    v13->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::money_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  }
  else
  {
    v13 = 0;
  }
  v49[9] = v13;
  v14 = (stlp_std::locale::facet *)operator new(8u);
  if ( v14 )
  {
    v14->_M_ref_count = 1;
    v14->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::num_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  }
  else
  {
    v14 = 0;
  }
  v49[10] = v14;
  v15 = (stlp_std::locale::facet *)operator new(8u);
  if ( v15 )
  {
    v15->_M_ref_count = 1;
    v15->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::num_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  }
  else
  {
    v15 = 0;
  }
  v49[11] = v15;
  v16 = (char *)operator new(0x444u);
  v17 = (stlp_std::locale::facet *)v16;
  v48 = v16;
  v51 = 5;
  if ( v16 )
  {
    *((_DWORD *)v16 + 1) = 1;
    *(_DWORD *)v16 = &stlp_std::locale::facet::`vftable';
    LOBYTE(v51) = 6;
    stlp_std::priv::time_init<char>::time_init<char>((stlp_std::priv::time_init<char> *)(v16 + 8));
    v17->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::time_get<char,stlp_std::istreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  }
  else
  {
    v17 = 0;
  }
  v49[12] = v17;
  v18 = (char *)operator new(0x444u);
  v19 = (stlp_std::locale::facet *)v18;
  v48 = v18;
  v51 = 7;
  if ( v18 )
  {
    *((_DWORD *)v18 + 1) = 1;
    *(_DWORD *)v18 = &stlp_std::locale::facet::`vftable';
    LOBYTE(v51) = 8;
    stlp_std::priv::time_init<char>::time_init<char>((stlp_std::priv::time_init<char> *)(v18 + 8));
    v19->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::time_put<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>::`vftable';
  }
  else
  {
    v19 = 0;
  }
  v51 = -1;
  v49[13] = v19;
  v20 = (stlp_std::locale::facet *)operator new(8u);
  if ( v20 )
  {
    v20->_M_ref_count = 1;
    v20->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::collate<wchar_t>::`vftable';
  }
  else
  {
    v20 = 0;
  }
  v49[14] = v20;
  v21 = (stlp_std::locale::facet *)operator new(8u);
  if ( v21 )
  {
    v21->_M_ref_count = 1;
    v21->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::ctype<wchar_t>::`vftable';
  }
  else
  {
    v21 = 0;
  }
  v49[15] = v21;
  v22 = (stlp_std::locale::facet *)operator new(8u);
  if ( v22 )
  {
    v22->_M_ref_count = 1;
    v22->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::codecvt<wchar_t,char,int>::`vftable';
  }
  else
  {
    v22 = 0;
  }
  v49[16] = v22;
  v23 = (stlp_std::moneypunct<wchar_t,1> *)operator new(0x10u);
  v48 = (char *)v23;
  v51 = 9;
  if ( v23 )
    stlp_std::moneypunct<wchar_t,1>::moneypunct<wchar_t,1>(v23, 1u);
  else
    v24 = 0;
  v49[17] = v24;
  v25 = (stlp_std::moneypunct<wchar_t,0> *)operator new(0x10u);
  v48 = (char *)v25;
  v51 = 10;
  if ( v25 )
    stlp_std::moneypunct<wchar_t,0>::moneypunct<wchar_t,0>(v25, 1u);
  else
    v26 = 0;
  v51 = -1;
  v49[18] = v26;
  v27 = (stlp_std::locale::facet *)operator new(8u);
  if ( v27 )
  {
    v27->_M_ref_count = 1;
    v27->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::numpunct<wchar_t>::`vftable';
  }
  else
  {
    v27 = 0;
  }
  v49[19] = v27;
  v28 = (stlp_std::messages<wchar_t> *)operator new(8u);
  v48 = (char *)v28;
  v51 = 11;
  if ( v28 )
    stlp_std::messages<wchar_t>::messages<wchar_t>(v28, 1u);
  else
    v29 = 0;
  v51 = -1;
  v49[20] = v29;
  v30 = (stlp_std::locale::facet *)operator new(8u);
  if ( v30 )
  {
    v30->_M_ref_count = 1;
    v30->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::money_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  }
  else
  {
    v30 = 0;
  }
  v49[21] = v30;
  v31 = (stlp_std::locale::facet *)operator new(8u);
  if ( v31 )
  {
    v31->_M_ref_count = 1;
    v31->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::money_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  }
  else
  {
    v31 = 0;
  }
  v49[22] = v31;
  v32 = (stlp_std::locale::facet *)operator new(8u);
  if ( v32 )
  {
    v32->_M_ref_count = 1;
    v32->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::num_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  }
  else
  {
    v32 = 0;
  }
  v49[23] = v32;
  v33 = (stlp_std::locale::facet *)operator new(8u);
  if ( v33 )
  {
    v33->_M_ref_count = 1;
    v33->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::num_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  }
  else
  {
    v33 = 0;
  }
  v49[24] = v33;
  v34 = (char *)operator new(0x6C4u);
  v35 = (stlp_std::locale::facet *)v34;
  v48 = v34;
  v51 = 12;
  if ( v34 )
  {
    *((_DWORD *)v34 + 1) = 1;
    *(_DWORD *)v34 = &stlp_std::locale::facet::`vftable';
    LOBYTE(v51) = 13;
    stlp_std::priv::time_init<wchar_t>::time_init<wchar_t>((stlp_std::priv::time_init<wchar_t> *)(v34 + 8));
    v35->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::time_get<wchar_t,stlp_std::istreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  }
  else
  {
    v35 = 0;
  }
  v49[25] = v35;
  v36 = (char *)operator new(0x6C4u);
  v37 = (stlp_std::locale::facet *)v36;
  v48 = v36;
  v51 = 14;
  if ( v36 )
  {
    *((_DWORD *)v36 + 1) = 1;
    *(_DWORD *)v36 = &stlp_std::locale::facet::`vftable';
    LOBYTE(v51) = 15;
    stlp_std::priv::time_init<wchar_t>::time_init<wchar_t>((stlp_std::priv::time_init<wchar_t> *)(v36 + 8));
    v37->__vftable = (stlp_std::locale::facet_vtbl *)&stlp_std::time_put<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>::`vftable';
  }
  else
  {
    v37 = 0;
  }
  v49[26] = v37;
  p_facets_vec = &impl->facets_vec;
  v51 = -1;
  v49[27] = 0;
  M_start = impl->facets_vec._M_impl._M_start;
  p_M_end_of_storage = &impl->facets_vec._M_impl._M_end_of_storage;
  v41 = impl->facets_vec._M_impl._M_end_of_storage._M_data - M_start;
  __n = 28;
  if ( v41 < 0x1C )
  {
    v42 = impl->facets_vec._M_impl._M_finish - M_start;
    if ( M_start )
    {
      v43 = (_STLP_atomic_freelist::item *)stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_allocate_and_copy<void * *>(
                                             &impl->facets_vec._M_impl,
                                             &__n,
                                             (stlp_std::locale::facet **)M_start,
                                             (stlp_std::locale::facet **)impl->facets_vec._M_impl._M_finish);
      stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(&p_facets_vec->_M_impl);
    }
    else
    {
      v43 = stlp_std::allocator<void *>::_M_allocate(&impl->facets_vec._M_impl._M_end_of_storage, 0x1Cu, &__n);
    }
    v44 = &v43[__n];
    p_facets_vec->_M_impl._M_start = (void **)&v43->_M_next;
    p_facets_vec->_M_impl._M_finish = (void **)&v43[v42]._M_next;
    p_M_end_of_storage->_M_data = (void **)&v44->_M_next;
  }
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_assign_aux<stlp_std::locale::facet * *>(
    &p_facets_vec->_M_impl,
    v49,
    (int)&v50,
    &v45);
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    v51 = 16;
    stlp_std::locale::locale(&Locale_classic, impl);
    atexit((int (__cdecl *)())stlp_std::_Locale_impl::make_classic_locale_::_2_::_dynamic_atexit_destructor_for___Locale_classic__);
    v51 = -1;
  }
  Stl_classic_locale = &Locale_classic;
  if ( (_S4 & 2) == 0 )
  {
    _S4 |= 2u;
    v51 = 17;
    stlp_std::locale::locale(&Locale_global, impl);
    atexit((int (__cdecl *)())stlp_std::_Locale_impl::make_classic_locale_::_2_::_dynamic_atexit_destructor_for___Locale_global__);
  }
  Stl_global_locale = &Locale_global;
}
