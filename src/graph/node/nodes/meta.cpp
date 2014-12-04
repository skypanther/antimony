#include <Python.h>

#include "graph/node/node.h"
#include "graph/node/manager.h"

#include "graph/node/nodes/meta.h"

#include "graph/datum/datums/name_datum.h"
#include "graph/datum/datums/float_datum.h"
#include "graph/datum/datums/shape_input_datum.h"
#include "graph/datum/datums/shape_function_datum.h"
#include "graph/datum/datums/string_datum.h"
#include "graph/datum/datums/script_datum.h"

////////////////////////////////////////////////////////////////////////////////

Node* ScriptNode(QString name, QString x, QString y, QString z,
                 QString script, QObject* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);

    Node* n = new Node(NodeType::SCRIPT, parent);
    new NameDatum("name", name, n);
    new ScriptDatum("script", script, n);
    return n;
}

Node* ScriptNode(float x, float y, float z, float scale,
                 QObject* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::SCRIPT, parent);
    new NameDatum("name", NodeManager::manager()->getName("a"), n);
    new ScriptDatum("script",
             "from fab import shapes\n\n"
             "output('c', shapes.circle(0, 0, 1))", n);
    return n;
}

Node* EquationNode(float x, float y, float z, float scale,
                       QObject* parent)
{
    Q_UNUSED(x);
    Q_UNUSED(y);
    Q_UNUSED(z);
    Q_UNUSED(scale);

    Node* n = new Node(NodeType::EQUATION, parent);
    new NameDatum("name", NodeManager::manager()->getName("a"), n);
    new ShapeInputDatum("a", n);
    new ShapeFunctionDatum("shape", n, "buffer", {"a"});

    return n;
}
