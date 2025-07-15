vostok::render::sort_surfaces_predicate_entry *__usercall vostok::render::sort_surfaces_predicate_entry::operator=@<eax>(
        vostok::render::sort_surfaces_predicate_entry *this@<esi>,
        const vostok::render::sort_surfaces_predicate_entry *__that@<eax>)
{
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &__that->ps_ref,
    (vostok::render::res_xs<vostok::render::ps_data> *)this);
  this->instance = __that->instance;
  this->vs = __that->vs;
  this->ps = __that->ps;
  this->distance = __that->distance;
  this->two_sided = __that->two_sided;
  this->alpha_test = __that->alpha_test;
  return this;
}
