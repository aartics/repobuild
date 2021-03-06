// Copyright 2013
// Author: Christopher Van Arsdale

#ifndef _REPOBUILD_NODES_GO_LIBRARY_H__
#define _REPOBUILD_NODES_GO_LIBRARY_H__

#include <memory>
#include <vector>
#include "repobuild/nodes/node.h"
#include "repobuild/env/resource.h"

namespace repobuild {
class ComponentHelper;

class GoLibraryNode : public Node {
 public:
  GoLibraryNode(const TargetInfo& t, const Input& i, DistSource* s);
  virtual ~GoLibraryNode();
  virtual void Parse(BuildFile* file, const BuildFileNode& input);
  virtual void LocalWriteMake(Makefile* out) const {
    LocalWriteMakeInternal(true, out);
  }
  virtual void LocalDependencyFiles(LanguageType lang,
                                    ResourceFileSet* files) const;
  virtual void LocalObjectFiles(LanguageType lang,
                                ResourceFileSet* files) const;

  // Manual construction.
  void Set(const std::vector<Resource>& sources);

 protected:
  void Init();
  void LocalWriteMakeInternal(bool write_user_target, Makefile* out) const;
  Resource GoFileFor(const Resource& r) const;
  std::string GoBuildPrefix() const;

  Resource touchfile_;
  std::vector<Resource> sources_;
  std::unique_ptr<ComponentHelper> component_;
};

}  // namespace repobuild

# endif  // _REPOBUILD_NODES_GO_LIBRARY_H__
