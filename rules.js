URLDATA = JSON.parse(localStorage.getItem("configData"))
APIURL = URLDATA.webUrl;
URI = URLDATA.uri

$(function () {
    function loadRules() {
        debugger
        ruleData.map((val, index) => {
            let html = "<tr>" + (val.active === "1" ?
                + '<td><input type="checkbox"> </td>' : '<td><input type="checkbox" ></td>')

                /*  "<lable title=\"Enable/Disable Rule\" "+ " class=\"switch\" onclick=\""+ "<input type=\"checkbox"> 
                + "<span class=\"slider round\"</span>"+"</label>" + "</td> ":
               + "<td>"+" <label class=\"switch\>+ <input type=\"checkbox checked">
                   + "<span class=\"slider round\"></span>"+" </label>" */
                + '<td>' + val.ruleId + '</td>'
                + '<td>' + val.type + '</td>'
                + '<td>' + val.comp + val.value + '</td> '
                + "<td> "
                + '<button title="Edit" onclick="editRule(' + index + ')" '
                + '  class="mdc-button mdc-button--raised icon-button filled-button--warning mdc-ripple-upgraded" '
                + '  style="padding:3px;margin : 5px;--mdc-ripple-fg-size:21px; --mdc-ripple-fg-scale:2.90056; --mdc-ripple-fg-translate-start:4.625px, 1.5px; --mdc-ripple-fg-translate-end:7.5px, 7.5px;"> '
                + '  <i class="material-icons mdc-button__icon">edit</i> '
                + '</button> '
                + '<button onclick="deleteRule(' + index + ')" title="Delete"'
                + '  class="mdc-button mdc-button--raised icon-button filled-button--secondary mdc-ripple-upgraded" '
                + '  style="padding:3px;margin : 5px;--mdc-ripple-fg-size:21px; --mdc-ripple-fg-scale:2.90056; --mdc-ripple-fg-translate-start:-4.46875px, 8.5px; --mdc-ripple-fg-translate-end:7.5px, 7.5px;"> '
                + '  <i class="material-icons mdc-button__icon">delete</i> '
                + '</button> '
                + '</td> '
                + '</tr>'
            $(".ruleList").append(html);
        })

    }

    loadRules()
})


/**
* Validate the fields
* 
* Description: This function checks whether all required fields are filled and checks the format of values in add facility form.
*/
function validateRules() {
    debugger;
    try {

        var flag = true;
        var stat = document.getElementById("Status");
        // var inpName = document.getElementById("name");
        var inpType = document.getElementById("Type");
        var inpComp = document.getElementById("comp");
        var inpVal = document.getElementById("val");

        if (!stat.checkValidity() || !inpType.checkValidity() || !inpComp.checkValidity() || !inpVal.checkValidity()) {
            flag = false;
            alert("Please enter all the required fields");
            return;
        }
        if (flag) {
            addRule();
        }
    }
    catch (er) {
        console.log("Error in validateRules: ", er);
    }
};

function addRule() {

    try {

        $("#addRulePane").css("display", "none");
        $("#progressbarPane").css("display", "flex");

        let flag = false;
        let ruleData = {};

        var data = {
            "active": $("#Status").prop("checked") ? "Active" : "Inactive",
            "type": document.getElementById("Type").value,
            "comp": document.getElementById("comp").value,
            "value": document.getElementById("val").value,
        }
        ruleData = data;
        $.ajax(APIURL + "save/rule", {
            asyn: false,
            type: 'POST',  // http method
            data: ruleData,
            success: function (data, status, xhr) {
                swal({
                    title: "Rule Added",
                    text: "New rule added successfully",
                    icon: "success",
                    buttons: [false, "okay"],
                }).then((value) => {
                    refreshRule();

                });
            }, error: function (jqXhr, textStatus, errorMessage) {
                $("#progressbarPane").css("display", "none");
                console.log('Error' + errorMessage);
                swal("Could not add rule. Please try again later.").then(data => {
                    refreshRule();
                });;
            }
        });
    }
    catch (er) {
        $("#progressbarPane").css("display", "none");
        console.log("Error in addrule : ", er);
    }
}

function validateEditRules() {
    try {

        var flag = true;
        var numbers = /^[0-9]+$/;
        var status = document.getElementById("Statusedit");
        var ruleid = document.getElementById("nameEdit");
        var inputType = document.getElementById("TypeEdit");
        var inputComp = document.getElementById("compEdit");
        var inputVal = document.getElementById("valEdit");
        if (!status.checkValidity() || !ruleid.checkValidity() || !inputType.checkValidity() || !inputComp.checkValidity() || !inputVal.checkValidity()) {
            flag = false;
            alert("Please enter all the required fields");
            return;
        }

        if (flag) {
            updateRule();
        }

    }
    catch (e) {
        console.log("Error in validateEditRules: ", er);
    }
}
function editRule(index) {
    debugger
    try {
        var editRuleData = ruleData[index];
        console.log(editRuleData)

        $("#editRulesPane").css("display", "block");
        $("#addRulePane").css("display", "none");
        $("#listrulePane").css("display", "none");
        $("#Statusedit").val(editRuleData['active']);
        $("#nameEdit").focus();
        $("#nameEdit").val(editRuleData['ruleId']);
        $("#Statusedit").focus();
        $("#TypeEdit").val(editRuleData['type']);
        $("#TypeEdit").focus();
        $("#compEdit").val(editRuleData['comp']);
        $("#compEdit").focus();
        $("#valEdit").val(editRuleData['value']);
        $("#valEdit").focus();
    }
    catch (e) {
        console.log(e);
    }

}

function updateRule(index) {

    debugger
    try {
        $("#editRulesPane").css("display", "none");
        $("#progressbarPane").css("display", "flex");
        var dataEdit = {
            "active": document.getElementById("Statusedit").value,
            "ruleId": document.getElementById("nameEdit").value,
            "type": document.getElementById("TypeEdit").value,
            "comp": document.getElementById("compEdit").value,
            "value": document.getElementById("valEdit").value,
        }

        $.ajax(APIURL + "update/rule", {
            asyn: false,
            type: 'PUT',  // http method
            data: dataEdit,
            success: function (data, status, xhr) {
                swal({
                    title: "Rule Edited",
                    text: "Rule edited successfully",
                    icon: "success",
                    buttons: [false, "okay"],
                }).then((value) => {
                    refreshRule()

                });
            }, error: function (jqXhr, textStatus, errorMessage) {
                $("#progressbarPane").css("display", "none");
                $("#editRulesPane").css("display", "block");
                console.log('Error' + errorMessage);
                swal("Could not edit Rule. Please try again later.").then(data => {
                    refreshRule();
                });;
            }
        });
    }
    catch (er) {
        console.log("Error in updateRule : ", er);
        $("#progressbarPane").css("display", "none");
        $("#editRulesPane").css("display", "block");
    }
}


/**
 * Delete an existing rule
 * 
 * Description: This function deletes an existing ruleusing API.
 * 
 * @param {number} userIndex userIndex is an index of particular user in array.
 */

function deleteRule(userIndex) {
    try {
        debugger
        var myid = ruleData[userIndex].ruleId;
        swal({
            title: "Are you sure you want to delete ?",
            text: "Once deleted, you will not be able to retrieve this object.",
            icon: "warning",
            buttons: true,
            dangerMode: true,
        })
            .then((willDelete) => {
                if (willDelete) {
                    $("#listrulePane").css("display", "none");
                    $("#progressbarPane").css("display", "flex");
                    $.ajax(APIURL + URI.rules.delete + myid, {
                        asyn: false,
                        type: 'DELETE',
                        success: function (data, status, xhr) {
                            getRuleData();
                            $("#rules").addClass("active");
                            $("#mainContentPane").load("pages/rules.html");
                            swal("Deleted Successfully !", {
                                icon: "success",
                            }).then((value) => {
                                refreshRule();
                            });
                        }, error: function (jqXhr, textStatus, errorMessage) {
                            $("#progressbarPane").css("display", "none");
                            console.log('Error in deleteRule :' + errorMessage);
                            swal("Could not delete Rule. Please try again later.").then(data => {
                                refreshRule();
                            });;

                        }

                    });

                } else {
                    swal("Delete is canceled by user");
                }
            });

    }
    catch (er) {
        $("#progressbarPane").css("display", "none");
        console.log("Error in deleteAsset : ", er);
    }
}


/**
* Reset the fields 
* 
* Description: This function resets all the fields in edit asset form on clicking the reset button.
*/
function resetRules() {
    try {
        document.getElementById("Status").value = "";
        document.getElementById("name").value = "";
        document.getElementById("Type").value = "";
        document.getElementById("comp").value = "";
        document.getElementById("val").value = "";

    }
    catch (er) {
        console.log("Error in reset rule", er)
    }
}

function addNewRule(flag) {
    debugger;
    resetRules();
    if (flag == true) {
        $("#addRulePane").css("display", "block");
        $("#editRulesPane").css("display", "none");
        $("#listrulePane").css("display", "none");
    }
    else {
        $("#addRulePane").css("display", "none");
        $("#editRulesPane").css("display", "none");
        $("#listrulePane").css("display", "block");
    }
}


function refreshRule() {
    getRuleData().then(data => {
        ChangeView("rules")
    })
}


