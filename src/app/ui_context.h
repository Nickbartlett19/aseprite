// Aseprite
// Copyright (C) 2001-2018  David Capello
//
// This program is distributed under the terms of
// the End-User License Agreement for Aseprite.

#ifndef APP_UI_CONTEXT_H_INCLUDED
#define APP_UI_CONTEXT_H_INCLUDED
#pragma once

#include "app/context.h"
#include "app/docs_observer.h"

namespace app {
  class DocumentView;
  class Editor;

  typedef std::vector<DocumentView*> DocumentViews;

  class UIContext : public app::Context {
  public:
    static UIContext* instance() { return m_instance; }

    UIContext();
    virtual ~UIContext();

    bool isUIAvailable() const override;

    DocumentView* activeView() const;
    void setActiveView(DocumentView* documentView);

    DocumentView* getFirstDocumentView(Doc* document) const override;
    DocumentViews getAllDocumentViews(Doc* document) const;

    // Returns the current editor. It can be null.
    Editor* activeEditor();

    // Returns the active editor for the given document, or creates a
    // new one if it's necessary.
    Editor* getEditorFor(Doc* document);

  protected:
    void onAddDocument(Doc* doc) override;
    void onRemoveDocument(Doc* doc) override;
    void onGetActiveSite(Site* site) const override;
    void onSetActiveDocument(Doc* doc) override;

  private:
    DocumentView* m_lastSelectedView;
    static UIContext* m_instance;
  };

} // namespace app

#endif
