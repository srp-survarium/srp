void __thiscall stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char> > *this,
        char *__pos,
        unsigned int __n,
        char *__x,
        const stlp_std::__false_type *__formal)
{
  char *M_finish; // edi
  char *v7; // eax
  char __xa; // [esp+Fh] [ebp-1h] BYREF

  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    if ( M_finish - __pos <= __n )
    {
      v7 = stlp_std::priv::__uninitialized_fill_n<char *,unsigned int,char>(M_finish, __n - (M_finish - __pos), __x);
      this->_M_finish = v7;
      stlp_std::priv::__ucopy_trivial((unsigned __int8 *)__pos, (unsigned __int8 *)M_finish, (unsigned __int8 *)v7);
      this->_M_finish += M_finish - __pos;
      memset((int)__pos, (unsigned __int8)*__x, M_finish - __pos);
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&M_finish[-__n],
        (unsigned __int8 *)M_finish,
        (unsigned __int8 *)M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &M_finish[-__n], M_finish);
      memset((int)__pos, (unsigned __int8)*__x, __n);
    }
  }
  else
  {
    __xa = *__x;
    HIBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__xa,
      (const stlp_std::__false_type *)&__x + 3);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float> > *this,
        float *__pos,
        unsigned int __n,
        float *__x,
        const stlp_std::__false_type *__formal)
{
  float *v5; // edx
  float v7; // xmm0_4
  float *M_finish; // esi
  unsigned int v9; // edi
  float *v10; // eax
  int j; // edi
  float *v12; // ecx
  int v13; // eax
  double v14; // st7
  float *v15; // edx
  float *v16; // eax
  int i; // esi
  float __xa; // [esp+8h] [ebp-4h] BYREF
  float *__na; // [esp+18h] [ebp+Ch]

  v5 = __x;
  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v9 = M_finish - __pos;
    if ( v9 <= __n )
    {
      v12 = &M_finish[__n - v9];
      v13 = (int)(4 * (__n - v9)) >> 2;
      __na = this->_M_finish;
      if ( v13 > 0 )
      {
        while ( 1 )
        {
          v14 = *v5;
          v15 = __na++;
          *v15 = v14;
          if ( --v13 <= 0 )
            break;
          v5 = __x;
        }
      }
      this->_M_finish = v12;
      stlp_std::priv::__ucopy_trivial((unsigned __int8 *)__pos, (unsigned __int8 *)M_finish, (unsigned __int8 *)v12);
      this->_M_finish += v9;
      v16 = __pos;
      for ( i = M_finish - __pos; i > 0; --i )
        *v16++ = *__x;
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&M_finish[-__n],
        (unsigned __int8 *)M_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &M_finish[-__n], (char *)M_finish);
      v10 = __pos;
      for ( j = (int)(4 * __n) >> 2; j > 0; --j )
        *v10++ = *__x;
    }
  }
  else
  {
    v7 = *__x;
    HIBYTE(__x) = 0;
    __xa = v7;
    stlp_std::priv::_Impl_vector<float,vostok::vectora_allocator<float>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__xa,
      (const stlp_std::__false_type *)&__x + 3);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<void *,vostok::input::std_allocator<void *> > *this,
        void **__pos,
        unsigned int __n,
        void **__x,
        const stlp_std::__false_type *__formal)
{
  void **M_finish; // ebx
  unsigned int v7; // edi
  void **v8; // eax
  void **v9; // [esp-20h] [ebp-2Ch]
  void *__xa; // [esp+8h] [ebp-4h] BYREF

  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = this->_M_finish;
    v7 = M_finish - __pos;
    if ( v7 <= __n )
    {
      v8 = stlp_std::priv::__uninitialized_fill_n<void * *,unsigned int,void *>(M_finish, __n - v7, __x);
      this->_M_finish = v8;
      stlp_std::priv::__ucopy_trivial((unsigned __int8 *)__pos, (unsigned __int8 *)M_finish, (unsigned __int8 *)v8);
      v9 = __x;
      this->_M_finish += v7;
      stlp_std::fill<void * *,void *>(__pos, M_finish, v9);
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(
        (unsigned __int8 *)&M_finish[-__n],
        (unsigned __int8 *)M_finish,
        (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &M_finish[-__n], (char *)M_finish);
      stlp_std::fill<void * *,void *>(__pos, &__pos[__n], __x);
    }
  }
  else
  {
    __xa = *__x;
    HIBYTE(__x) = 0;
    stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__xa,
      (const stlp_std::__false_type *)&__x + 3);
  }
}


void __thiscall stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_fill_insert_aux(
        stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_> > *this,
        vostok::ui::undo_ *__pos,
        unsigned int __n,
        const vostok::ui::undo_ *__x,
        const stlp_std::__false_type *__formal)
{
  const char *text; // ecx
  unsigned __int8 *M_finish; // esi
  unsigned int v8; // edi
  vostok::ui::undo_ *v9; // eax
  int k; // edi
  vostok::ui::undo_ *v11; // ecx
  int v12; // eax
  _DWORD *i; // edx
  vostok::ui::undo_ *v14; // eax
  int j; // esi
  vostok::ui::undo_ __xa; // [esp+8h] [ebp-8h] BYREF

  if ( __x < this->_M_start || __x >= this->_M_finish )
  {
    M_finish = (unsigned __int8 *)this->_M_finish;
    v8 = (M_finish - (unsigned __int8 *)__pos) >> 3;
    if ( v8 <= __n )
    {
      v11 = (vostok::ui::undo_ *)&M_finish[8 * (__n - v8)];
      v12 = (int)(8 * (__n - v8)) >> 3;
      for ( i = M_finish; v12 > 0; i += 2 )
      {
        *i = __x->text;
        i[1] = *(_DWORD *)&__x->caret;
        --v12;
      }
      this->_M_finish = v11;
      stlp_std::priv::__ucopy_trivial((unsigned __int8 *)__pos, M_finish, (unsigned __int8 *)v11);
      this->_M_finish += v8;
      v14 = __pos;
      for ( j = (M_finish - (unsigned __int8 *)__pos) >> 3; j > 0; --j )
        *v14++ = *__x;
    }
    else
    {
      stlp_std::priv::__ucopy_trivial(&M_finish[-8 * __n], M_finish, (unsigned __int8 *)this->_M_finish);
      this->_M_finish += __n;
      stlp_std::priv::__copy_trivial_backward((unsigned __int8 *)__pos, &M_finish[-8 * __n], (char *)M_finish);
      v9 = __pos;
      for ( k = (int)(8 * __n) >> 3; k > 0; --k )
        *v9++ = *__x;
    }
  }
  else
  {
    text = __x->text;
    *(_DWORD *)&__xa.caret = *(_DWORD *)&__x->caret;
    HIBYTE(__x) = 0;
    __xa.text = text;
    stlp_std::priv::_Impl_vector<vostok::ui::undo_,vostok::vectora_allocator<vostok::ui::undo_>>::_M_fill_insert_aux(
      this,
      __pos,
      __n,
      &__xa,
      (const stlp_std::__false_type *)&__x + 3);
  }
}
